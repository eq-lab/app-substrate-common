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

parser_error_t _readMethod(parser_context_t *c, parser_tx_t *v) {
    switch (v->knownChainType) {
        case KnownChainType_Unknown:
            return parser_not_supported;
        
        case KnownChainType_Polkadot:
            return _readMethod_Polkadot(c, v);

        case KnownChainType_Kusama:
             return _readMethod_Kusama(c, v);

        case KnownChainType_BridgeHub_Polkadot:
             return _readMethod_BridgeHub_Polkadot(c, v);
        
        case KnownChainType_Astar:
             return _readMethod_Astar(c, v);

        case KnownChainType_Equilibrium:
             return _readMethod_Equilibrium(c, v);
        
        // TODO_GRANT: fill all chains

        default:
            return parser_not_supported;
    }
}

uint8_t _getMethod_NumItems(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx) // TODO_GRANT
{
    // TODO_GRANT: blind sign
    switch (knownChainType)
    {
        case KnownChainType_Unknown:
            return STR_SUBSTRATE;

        case KnownChainType_Polkadot:
            return _getMethod_NumItems_Polkadot(moduleIdx, callIdx);

        // TODO_GRANT: fill
        case KnownChainType_Kusama:
            //  return _getMethod_NumItems_Kusama(moduleIdx, callIdx);

        case KnownChainType_BridgeHub_Polkadot:
            //  return _getMethod_NumItems_BridgeHub_Polkadot(moduleIdx, callIdx);
        
        case KnownChainType_Astar:
            //  return _getMethod_NumItems_Astar(moduleIdx, callIdx);

        case KnownChainType_Equilibrium:
            //  return _getMethod_NumItems_Equilibrium(moduleIdx, callIdx);
        default:
            return 2;
    }
}

const char* _getMethod_ModuleName(known_chain_type_t knownChainType, uint8_t moduleIdx)
{
    switch (knownChainType)
    {
        case KnownChainType_Unknown:
            return STR_SUBSTRATE;

        case KnownChainType_Polkadot:
            return _getMethod_ModuleName_Polkadot(moduleIdx);

        // TODO_GRANT: fill
        default:
            return NULL;
    }
}

const char* _getMethod_Name(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx) // TODO_GRANT
{
    switch (knownChainType)
    {
        case KnownChainType_Unknown:
            return STR_ME_SIGN;

        case KnownChainType_Polkadot:
            return _getMethod_Name_Polkadot(moduleIdx, callIdx);

        // TODO_GRANT: fill
        default:
            return NULL;
    }
}

const char* _getMethod_ItemName(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    switch (knownChainType)
    {
        case KnownChainType_Unknown:
            switch (itemIdx) {
                case 0:
                    return STR_IT_tx_hash;
                case 1:
                    return STR_IT_genesis_hash;
                default:
                    return NULL;
                }

        case KnownChainType_Polkadot:
            return _getMethod_ItemName_Polkadot(moduleIdx, callIdx, itemIdx);

        // TODO_GRANT: fill
        default:
            return NULL;
    }
}

parser_error_t _getMethod_ItemValue(known_chain_type_t knownChainType, pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx,
    uint8_t itemIdx, char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    switch (knownChainType)
    {
        case KnownChainType_Unknown:
            return parser_unexpected_error;

        case KnownChainType_Polkadot:
            return _getMethod_ItemValue_Polkadot(m, moduleIdx, callIdx, itemIdx, outValue, outValueLen, pageIdx, pageCount);

        // TODO_GRANT: fill
        default:
            return parser_unexpected_error;
    }
}

bool _getMethod_ItemIsExpert(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) // TODO_GRANT
{
    // TODO_GRANT
    return false;
}

bool _getMethod_IsNestingSupported(known_chain_type_t knownChainType, uint8_t moduleIdx, uint8_t callIdx) // TODO_GRANT is it required??
{
    // TODO_GRANT is it required?
    return false;
}
