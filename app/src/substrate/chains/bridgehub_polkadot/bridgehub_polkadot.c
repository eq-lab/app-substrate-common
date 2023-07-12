#include "bridgehub_polkadot.h"
#include "../../methods/balances.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_Balances = 10,
} PalletId;

bool _readMethod_BridgeHub_Polkadot(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.idx) {
        case PalletId_Balances:
            return _readMethod_balances(c, v);

        default:
            return false;
    }
}