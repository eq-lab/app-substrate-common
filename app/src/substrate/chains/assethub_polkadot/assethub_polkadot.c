#include "assethub_polkadot.h"
#include "../../methods/balances.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_Balances = 10,
} PalletId;

parser_error_t _readMethod_AssetHub_Polkadot(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.idx) {
        case PalletId_Balances:
            return _readMethod_balances(c, v);

        default:
            return parser_unexpected_module;
    }
}