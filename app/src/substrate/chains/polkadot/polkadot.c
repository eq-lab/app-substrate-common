#include "polkadot.h"
#include "../../methods/common.h"

typedef enum {
    PalletId_Balances_Transfer = 7,

} PalletId_Balances;

bool _read_method_Polkadot(parser_tx_t *v) {
    switch (v->callIndex.idx) {
        case PalletId_Balances_Transfer:
            return _read_method_balances(v);

        default:
            return false;
    }
}