#include "assets.h"

typedef enum {
    MethodId_Assets_Transfer = 8,
    MethodId_Assets_TransferKeepAlive = 9
} MethodId_Assets;

bool _readMethod_assets(parser_tx_t *v) {
    switch (v->callIndex.idx)
    {
    case MethodId_Assets_Transfer:
        // return _read_assets_transfer(v); TODO_GRANT

    case MethodId_Assets_TransferKeepAlive:
        // return _read_assets_transferKeepAlive(v); TODO_GRANT
    
    default:
        return false;
    }
}