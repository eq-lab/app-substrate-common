#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../methods/types.h"
#include "equilibrium/types.h"

typedef enum {
    KnownChainType_Unknown = 0,
    KnownChainType_Polkadot,
    KnownChainType_Kusama,
    KnownChainType_AssetHub_Polkadot,
    KnownChainType_AssetHub_Kusama,
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
    KnownChainType_Basilisk
} known_chain_type_t;

#ifdef __cplusplus
}
#endif