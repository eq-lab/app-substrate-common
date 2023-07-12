#include "polkadot.h"
#include "../../methods/balances.h"
#include "../../parser_impl.h"

typedef enum {
    PalletId_Balances = 7,
} PalletId;

bool _readMethod_Polkadot(parser_context_t *c, parser_tx_t *v) {
    switch (v->callIndex.moduleIdx) {
        case PalletId_Balances:
            return _readMethod_balances(c, v);

        default:
            return false;
    }
}

uint8_t _getMethod_NumItems_Polkadot(uint8_t moduleIdx, uint8_t callIdx) {

}