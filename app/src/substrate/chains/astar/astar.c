#include "astar.h"
#include "../../methods/assets.h"
#include "../../methods/balances.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_Assets = 36,
    PalletId_Balances = 31,
} PalletId;

bool _readMethod_Astar(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_Assets:
            return _readMethod_assets(c, v); 

        case PalletId_Balances:
            return false; // TODO_GRANT: Astar has old balances pallet version, we are waiting while they update it
            // return _readMethod_balances(v);

        default:
            return false;
    }
}
