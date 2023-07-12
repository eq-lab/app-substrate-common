#include "equilibrium.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_EqBalances = 36
} PalletId;

bool _readMethod_eq_balances(parser_context_t *c, parser_tx_t *v) {
    // TODO_GRANT
    return false;
}

bool _readMethod_Equilibrium(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_EqBalances:
            return _readMethod_eq_balances(c, v);

        default:
            return false;
    }
}
