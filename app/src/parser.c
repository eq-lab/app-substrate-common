/*******************************************************************************
*   (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#include <stdio.h>
#include <zxmacros.h>
#include <zxformat.h>
#include "app_mode.h"
#include "parser.h"
#include "coin.h"
#include "substrate_dispatch.h"
#include "substrate_strings.h"
#include "substrate_functions_common.h"

#if defined(TARGET_NANOX) || defined(TARGET_NANOS2)
// For some reason NanoX requires this function
void __assert_fail(const char * assertion, const char * file, unsigned int line, const char * function){
    while(1) {};
}
#endif

#define FIELD_FIXED_TOTAL_COUNT 7

#define FIELD_METHOD        0
#define FIELD_NETWORK       1
#define FIELD_NONCE         2
#define FIELD_TIP           3
#define FIELD_ERA_PHASE     4
#define FIELD_ERA_PERIOD    5
#define FIELD_BLOCK_HASH    6

#define EXPERT_FIELDS_TOTAL_COUNT 5

parser_error_t parser_parse(parser_context_t *ctx, const uint8_t *data, size_t dataLen, parser_tx_t *tx_obj) {
    CHECK_PARSER_ERR(parser_init(ctx, data, dataLen))
    ctx->tx_obj = tx_obj;
    ctx->tx_obj->nestCallIdx.slotIdx = 0;
    ctx->tx_obj->nestCallIdx._lenBuffer = 0;
    ctx->tx_obj->nestCallIdx._ptr = NULL;
    ctx->tx_obj->nestCallIdx._nextPtr = NULL;
    ctx->tx_obj->nestCallIdx.isTail = true;
    parser_error_t err = _readTx(ctx, ctx->tx_obj);
    CTX_CHECK_AVAIL(ctx, 0)

    return err;
}

__Z_INLINE bool parser_show_expert_fields() {
    return app_mode_expert();
}

bool parser_show_tip(const parser_context_t *ctx){
    if (ctx->tx_obj->tip.value.len <= 4) {
        uint64_t v;
        _getValue(&ctx->tx_obj->tip.value, &v);
        if ( v == 0 ){
            return false;
        }
    }
    return true;
}

parser_error_t parser_validate(const parser_context_t *ctx) {
    // Iterate through all items to check that all can be shown and are valid
    uint8_t numItems = 0;
    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems))

    char tmpKey[40];
    char tmpVal[40];

    for (uint8_t idx = 0; idx < numItems; idx++) {
        uint8_t pageCount = 0;
        CHECK_PARSER_ERR(parser_getItem(ctx, idx, tmpKey, sizeof(tmpKey), tmpVal, sizeof(tmpVal), 0, &pageCount))
    }

    return parser_ok;
}

parser_error_t parser_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
    uint8_t methodArgCount = _getMethod_NumItems(ctx->tx_obj->transactionVersion,
                                                 ctx->tx_obj->callIndex.moduleIdx,
                                                 ctx->tx_obj->callIndex.idx);

    uint8_t total = FIELD_FIXED_TOTAL_COUNT;
    if (!parser_show_tip(ctx)) {
        total -= 1;
    }
    if (!parser_show_expert_fields()) {
        total -= EXPERT_FIELDS_TOTAL_COUNT;

        for (uint8_t argIdx = 0; argIdx < methodArgCount; argIdx++) {
            bool isArgExpert = _getMethod_ItemIsExpert(ctx->tx_obj->transactionVersion,
                                                       ctx->tx_obj->callIndex.moduleIdx,
                                                       ctx->tx_obj->callIndex.idx, argIdx);
            if (isArgExpert) {
                methodArgCount--;
            }
        }
    }

    *num_items = total + methodArgCount;
    return parser_ok;
}

parser_error_t parser_getItem(const parser_context_t *ctx,
                              uint8_t displayIdx,
                              char *outKey, uint16_t outKeyLen,
                              char *outVal, uint16_t outValLen,
                              uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outKey, outKeyLen);
    MEMZERO(outVal, outValLen);
    snprintf(outKey, outKeyLen, "?");
    snprintf(outVal, outValLen, "?");
    *pageCount = 1;

    uint8_t numItems;
    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems))
    CHECK_APP_CANARY()

    if (displayIdx < 0 || displayIdx >= numItems) {
        return parser_no_data;
    }

    parser_error_t err = parser_ok;
    if (displayIdx == FIELD_METHOD) {
        snprintf(outKey, outKeyLen, "%s", STR_MO_POLKADOT);
        snprintf(outVal, outValLen, "%s", STR_ME_SIGN);
        return err;
    }

    // if (!parser_show_expert_fields()) {
    //     // Search for the next non expert item
    //     while ((argIdx < methodArgCount) && _getMethod_ItemIsExpert(ctx->tx_obj->transactionVersion,
    //                                                                 ctx->tx_obj->callIndex.moduleIdx,
    //                                                                 ctx->tx_obj->callIndex.idx, argIdx)) {
    //         argIdx++;
    //         displayIdx++;
    //     }
    // }

    if (displayIdx == 1) {
        snprintf(outKey, outKeyLen, "%s", STR_IT_tx_hash);

        err = _toStringTransactionHash(
                        &ctx->tx_obj->txHash,
                        outVal, outValLen,
                        pageIdx, pageCount);

        return err;

    } else if (displayIdx == 2) {
        snprintf(outKey, outKeyLen, "%s", STR_IT_genesis_hash);

        err = _toStringGenesisHash(
                        &ctx->tx_obj->genesisHash,
                        outVal, outValLen,
                        pageIdx, pageCount);
    }

}



