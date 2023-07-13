#include "polkadot.h"
#include "../../methods/balances.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_Balances = 5,
} PalletId;

parser_error_t _readMethod_Polkadot(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_Balances:
            return _readMethod_balances(c, v);

        default:
            return parser_unexpected_module;
    }
}

uint8_t _getMethod_NumItems_Polkadot(uint8_t moduleIdx, uint8_t callIdx) {
    switch (moduleIdx) {
        case PalletId_Balances:
            return _getMethod_NumItems_Balances(callIdx);

        default:
            return 0;
    }
}

const char* _getMethod_ModuleName_Polkadot(uint8_t moduleIdx) {
    switch (moduleIdx) {
        case PalletId_Balances:
            return _getMethod_ModuleName_Balances();

        default:
            return NULL;
    }
}

const char* _getMethod_Name_Polkadot(uint8_t moduleIdx, uint8_t callIdx) {
    switch (moduleIdx) {
        case PalletId_Balances:
            return _getMethod_Name_Balances(callIdx);

        default:
            return NULL;
    }
}

const char* _getMethod_ItemName_Polkadot(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    switch (moduleIdx) {
        case PalletId_Balances:
            return _getMethod_ItemName_Balances(callIdx, itemIdx);

        default:
            return NULL;
    }
}

parser_error_t _getMethod_ItemValue_Polkadot(
    pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount
) {
    switch (moduleIdx) {
        case PalletId_Balances:
            return _getMethod_ItemValue_Balances(
                m, callIdx, itemIdx, 
                outValue, outValueLen, 
                pageIdx, pageCount);

        default:
            return parser_not_supported;
    }
}