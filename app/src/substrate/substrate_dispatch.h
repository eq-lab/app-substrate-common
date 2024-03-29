/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"
#include "parser_common.h"
#include <stddef.h>
#include <stdint.h>

#define GEN_GETCALL(CALL) _getpdCall_##CALL(ctx->tx_obj->transactionVersion)
#define GEN_DEC_GETCALL(CALL) uint32_t _getpdCall_##CALL(uint32_t txVersion)
#define GEN_DEF_GETCALL(CALL)                      \
    uint32_t _getpdCall_##CALL(uint32_t txVersion) \
    {                                              \
        switch (txVersion) {                       \
        default:                                   \
            return 0;                              \
        }                                          \
    }

parser_error_t _readMethod(parser_context_t *c, parser_tx_t *v); 
uint8_t _getMethod_NumItems(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx);
const char* _getMethod_ModuleName(known_chain_type_t knownChainType, uint8_t moduleIdx);
const char* _getMethod_Name(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx);
const char* _getMethod_ItemName(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

parser_error_t _getMethod_ItemValue(
    known_chain_type_t knownChainType,
    pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);

bool _getMethod_ItemIsExpert(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);
bool _getMethod_IsNestingSupported(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx);

#define COMMON_APP_TX_VERSION 77
#ifdef __cplusplus
}
#endif
