#include "kusama.h"
#include "../../methods/balances.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_Balances = 4,
} PalletId;

parser_error_t _readMethod_Kusama(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_Balances:
            return _readMethod_balances(c, v);

        default:
            return parser_unexpected_callIndex;
    }
}