#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../substrate_types.h"

typedef struct {
    pd_Compactu128_t asset;
    pd_AccountId_t to;
    pd_Balance_t amount;
} pd_eqbalances_transfer_t;


typedef union {
    pd_eqbalances_transfer_t balances_transfer;
} pd_Method_Equilibrium_t;


#ifdef __cplusplus
}
#endif