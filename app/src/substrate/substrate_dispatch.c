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
#include "substrate_dispatch.h"
#include "substrate_strings.h"
#include "substrate_functions_common.h"
#include "parser_impl.h"

#include "zxmacros.h"
#include <stdint.h>

parser_error_t _readMethod(parser_context_t* c, parser_tx_t *v)
{
    return parser_tx_version_not_supported;
}

uint8_t _getMethod_NumItems(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    return 2;
}

const char* _getMethod_ModuleName(uint32_t transactionVersion, uint8_t moduleIdx)
{
    return STR_MO_POLKADOT;
}

const char* _getMethod_Name(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    return STR_ME_SIGN;
}

const char* _getMethod_ItemName(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    switch (itemIdx) {
    case 0:
        return STR_IT_tx_hash;
    case 1:
        return STR_IT_genesis_hash;
    default:
        return NULL;
    }
}

parser_error_t _getMethod_ItemValue(uint32_t transactionVersion, pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx,
    uint8_t itemIdx, char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    return parser_unexpected_error;
}

bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    return false;
}

bool _getMethod_IsNestingSupported(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx)
{
    return false;
}
