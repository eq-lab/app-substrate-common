#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "../substrate_types.h"
#include "../../parser_txdef.h"

typedef enum {
    Pallet_Balances = 0,
    Pallet_Assets,
    Pallet_Tokens,
    Pallet_Currencies,
    Pallet_EqBalances
} Pallet_t;

bool _read_method_balances(parser_tx_t *v);


#ifdef __cplusplus
}
#endif