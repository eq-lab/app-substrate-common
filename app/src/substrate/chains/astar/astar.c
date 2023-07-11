#include "astar.h"
#include "../../methods/assets.h"
#include "../../methods/balances.h"

typedef enum {
    PalletId_Assets = 36,
    PalletId_Balances = 31,
} PalletId;

bool _readMethod_Astar(parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_Assets:
            return _readMethod_assets(v); 

        case PalletId_Balances:
            return _readMethod_balances(v);

        default:
            return false;
    }
}
