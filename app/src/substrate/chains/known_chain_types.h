#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    KnownChainType_Polkadot = 0,
    KnownChainType_Kusama,
    KnownChainType_Statemint,
    KnownChainType_Statemine,
    KnownChainType_Equilibrium,
    KnownChainType_Genshiro,
    KnownChainType_Acala,
    KnownChainType_Karura,
    KnownChainType_Bifrost_Polkadot,
    KnownChainType_Bifrost_Kusama,
    KnownChainType_Nodle,
    KnownChainType_Zeitgeist,
    KnownChainType_Astar,
    KnownChainType_Shiden,
    KnownChainType_Mangata,
    KnownChainType_Hydradx,
    KnownChainType_Basilisk,
    KnownChainType_TotalAmount
} known_chain_type_t;

#ifdef __cplusplus
}
#endif