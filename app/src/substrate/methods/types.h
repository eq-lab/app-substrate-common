#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../substrate_types.h"

// Assets pallet
typedef struct {
    pd_CompactBalance_t assetId;
    pd_AccountIdLookupOfT_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_t;

typedef struct {
    pd_CompactBalance_t id;
    pd_AccountIdLookupOfT_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_t;


typedef union {
    pd_assets_transfer_t assets_transfer;
    pd_assets_transfer_keep_alive_t assets_transfer_keep_alive;
} pd_Method_Assets_t;



// Balances pallet
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_t;

typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_t;

typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_t;

typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_t;


typedef union {
    pd_balances_transfer_t balances_transfer;
    pd_balances_transfer_all_t balances_transfer_all;
    pd_balances_transfer_allow_death_t balances_transfer_allow_death;
    pd_balances_transfer_keep_alive_t balances_transfer_keep_alive;
} pd_Method_Balances_t;



#ifdef __cplusplus
}
#endif