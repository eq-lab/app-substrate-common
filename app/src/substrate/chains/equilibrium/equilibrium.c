#include "equilibrium.h"
#include "../../parser_impl.h"
#include "../../parser_txdef.h"
#include "../../common/parser_common.h"

typedef enum {
    PalletId_EqBalances = 36
} PalletId;

parser_error_t _readMethod_eq_balances(parser_context_t *c, parser_tx_t *v) {
    // TODO_GRANT
    return parser_unexpected_callIndex;
}

parser_error_t _readMethod_Equilibrium(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_EqBalances:
            return _readMethod_eq_balances(c, v);

        default:
            return parser_unexpected_module;
    }
}
