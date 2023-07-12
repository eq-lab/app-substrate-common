#include "balances.h"
#include "../substrate_strings.h"
#include "../../parser_impl.h"

typedef enum {
    MethodId_Balances_Transfer = 7,
    MethodId_Balances_TransferAll = 4,
    MethodId_Balances_TransferAllowDeath = 0,
    MethodId_Balances_TransferKeepAlive = 3
} MethodId_Balances;

bool _readMethod_balances(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.idx)
    {
    case MethodId_Balances_Transfer:
        // return _read_balances_transfer(v); TODO_GRANT
    
    case MethodId_Balances_TransferAll:
        // return _read_balances_transferAll(v); TODO_GRANT

    case MethodId_Balances_TransferAllowDeath:
        // return _read_balances_transferAllowDeath(v); TODO_GRANT

    case MethodId_Balances_TransferKeepAlive:
        // return _read_balances_transferKeepAlive(v); TODO_GRANT
    
    default:
        return false;
    }
}

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
        return _getMethod_ItemName_Balances_Transfer(itemIdx);
    case MethodId_Balances_TransferAll:
        return _getMethod_ItemName_Balances_TransferAll(itemIdx);
    case MethodId_Balances_TransferAllowDeath:
        return _getMethod_ItemName_Balances_Transfer(itemIdx);
    case MethodId_Balances_TransferKeepAlive:
        return _getMethod_ItemName_Balances_Transfer(itemIdx);
    default:
        return NULL;
    }
}

