#include "balances.h"
#include "../substrate_strings.h"
#include "../../parser_impl.h"

typedef enum {
    MethodId_Balances_Transfer = 7,
    MethodId_Balances_TransferAll = 4,
    MethodId_Balances_TransferAllowDeath = 0,
    MethodId_Balances_TransferKeepAlive = 3
} MethodId_Balances;



parser_error_t _read_balances_transfer(parser_context_t *c, parser_tx_t *v) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &v->method.balances.balances_transfer.dest));
    CHECK_ERROR(_readCompactBalance(c, &v->method.balances.balances_transfer.amount));
    return parser_ok;
}

parser_error_t _readMethod_balances(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.idx)
    {
    case MethodId_Balances_Transfer:
        return _read_balances_transfer(c, v);
    
    case MethodId_Balances_TransferAll:
        // return _read_balances_transferAll(v); TODO_GRANT

    case MethodId_Balances_TransferAllowDeath:
        // return _read_balances_transferAllowDeath(v); TODO_GRANT

    case MethodId_Balances_TransferKeepAlive:
        // return _read_balances_transferKeepAlive(v); TODO_GRANT
    
    default:
        return parser_unexpected_callIndex;
    }
}


// Display methods


uint8_t _getMethod_NumItems_Balances(uint8_t callIdx) {
    switch (callIdx)
    {
    case MethodId_Balances_Transfer:
    case MethodId_Balances_TransferAll:
    case MethodId_Balances_TransferAllowDeath:
    case MethodId_Balances_TransferKeepAlive:
        return 2;
    }
}

const char* _getMethod_ModuleName_Balances() {
    return STR_MO_Balances;
}

const char* _getMethod_Name_Balances(uint8_t callIdx) {
    switch (callIdx)
    {
    case MethodId_Balances_Transfer:
        return STR_ME_TRANSFER;
    case MethodId_Balances_TransferAll:
        return STR_ME_TRANSFER_ALL;
    case MethodId_Balances_TransferAllowDeath:
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case MethodId_Balances_TransferKeepAlive:
        return STR_ME_TRANSFER_KEEP_LIVE;
    default:
        return NULL;
    }
}



const char* _getMethod_ItemName_Balances_Transfer(uint8_t itemIdx) {
    switch (itemIdx)
    {
    case 0:
        return STR_IT_dest;
    case 1:
        return STR_IT_value;
    default:
        NULL;
    }
}

const char* _getMethod_ItemName_Balances_TransferAll(uint8_t itemIdx) {
    switch (itemIdx)
    {
    case 0:
        return STR_IT_dest;
    case 1:
        return STR_IT_keep_alive;
    default:
        NULL;
    }
}

const char* _getMethod_ItemName_Balances(uint8_t callIdx, uint8_t itemIdx) {
    switch (callIdx)
    {
    case MethodId_Balances_Transfer:
    case MethodId_Balances_TransferAllowDeath:
    case MethodId_Balances_TransferKeepAlive:
        return _getMethod_ItemName_Balances_Transfer(itemIdx);
    
    case MethodId_Balances_TransferAll:
        return _getMethod_ItemName_Balances_TransferAll(itemIdx);
    
    default:
        return NULL;
    }
}



parser_error_t _getMethod_ItemValue_Balances_Transfer(
    pd_Method_t* m, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount
) {
    switch (itemIdx)
    {
    case 0:
        return _toStringAccountIdLookupOfT(
                &m->balances.balances_transfer.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
    
    case 1:
        return _toStringCompactBalance(
                &m->balances.balances_transfer.amount,
                outValue, outValueLen,
                pageIdx, pageCount); 
    default:
        return parser_no_data;
    }
}

parser_error_t _getMethod_ItemValue_Balances_TransferAll(
    pd_Method_t* m, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount
) {
    // TODO_GRANT
}


parser_error_t _getMethod_ItemValue_Balances(
    pd_Method_t* m, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount
) {
    switch (callIdx)
    {
    case MethodId_Balances_Transfer:
    case MethodId_Balances_TransferAllowDeath:
    case MethodId_Balances_TransferKeepAlive:
        return _getMethod_ItemValue_Balances_Transfer(m, itemIdx, outValue, outValueLen, pageIdx, pageCount);
    
    case MethodId_Balances_TransferAll:
        return _getMethod_ItemValue_Balances_TransferAll(m, itemIdx, outValue, outValueLen, pageIdx, pageCount);

    default:
        return parser_not_supported;
    }
}