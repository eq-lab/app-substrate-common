#include "balances.h"

typedef enum {
    MethodId_Balances_Transfer = 7,
    MethodId_Balances_TransferAll = 4,
    MethodId_Balances_TransferAllowDeath = 0,
    MethodId_Balances_TransferKeepAlive = 3
} MethodId_Balances;

bool _readMethod_balances(parser_tx_t *v) {
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