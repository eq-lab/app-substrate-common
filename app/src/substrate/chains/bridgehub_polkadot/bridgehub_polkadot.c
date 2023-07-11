#include "bridgehub_polkadot.h"
#include "../../methods/balances.h"

typedef enum {
    PalletId_Balances = 10,
} PalletId;

bool _readMethod_BridgeHub_Polkadot(parser_tx_t *v) {
    switch (v->callIndex.idx) {
        case PalletId_Balances:
            return _readMethod_balances(v);

        default:
            return false;
    }
}