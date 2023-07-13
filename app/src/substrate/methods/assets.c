#include "assets.h"
#include "../substrate_strings.h"
#include "../../parser_impl.h"

typedef enum {
    MethodId_Assets_Transfer = 8,
    MethodId_Assets_TransferKeepAlive = 9
} MethodId_Assets;

parser_error_t _readMethod_assets(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.idx)
    {
    case MethodId_Assets_Transfer:
        // return _read_assets_transfer(v); TODO_GRANT

    case MethodId_Assets_TransferKeepAlive:
        // return _read_assets_transferKeepAlive(v); TODO_GRANT
    
    default:
        return parser_unexpected_callIndex;
    }
}

uint8_t _getMethod_NumItems_Assets(uint8_t callIdx) {
    switch (callIdx)
    {
    case MethodId_Assets_Transfer:
    case MethodId_Assets_TransferKeepAlive:
        return 3;
    }
}

const char* _getMethod_ModuleName_Assets() {
    return STR_MO_Assets;
}

const char* _getMethod_Name_Assets(uint8_t callIdx) {
    switch (callIdx)
    {
    case MethodId_Assets_Transfer:
        return STR_ME_TRANSFER;
    case MethodId_Assets_TransferKeepAlive:
        return STR_ME_TRANSFER_KEEP_LIVE;
    default:
        return NULL;
    }
}


const char* _getMethod_ItemName_Transfer(uint8_t itemIdx) {
    switch (itemIdx)
    {
    case 0:
        return STR_IT_id;
    case 1:
        return STR_IT_target;
    case 2:
        return STR_IT_amount;
    default:
        return NULL;
    }
}

const char* _getMethod_ItemName_Assets(uint8_t callIdx, uint8_t itemIdx) {
    switch (callIdx)
    {
    case MethodId_Assets_Transfer:
        return _getMethod_ItemName_Transfer(itemIdx);
    case MethodId_Assets_TransferKeepAlive:
        return _getMethod_ItemName_Transfer(itemIdx);
    default:
        return NULL;
    }
}

