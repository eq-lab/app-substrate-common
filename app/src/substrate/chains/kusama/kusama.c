#include "kusama.h"
#include "../../methods/balances.h"

typedef enum {
    PalletId_Balances = 4,
} PalletId;

bool _readMethod_Kusama(parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_Balances:
            return _readMethod_balances(v);

        default:
            return false;
    }
}