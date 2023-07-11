#include "known_chains.h"
#include "substrate_types_common.h"

#include "methods/assets.h"
#include "methods/balances.h"
#include "chains/astar/astar.h"
#include "chains/bridgehub_polkadot/bridgehub_polkadot.h"
#include "chains/equilibrium/equilibrium.h"
#include "chains/kusama/kusama.h"
#include "chains/polkadot/polkadot.h"

#include "parser_common.h"
#include <string.h>

const uint8_t GenesisHash_Polkadot[32] = {145, 177, 113, 187, 21, 142, 45, 56, 72, 250, 35, 169, 241, 194, 81, 130, 251, 142, 32, 49, 59, 44, 30, 180, 146, 25, 218, 122, 112, 206, 144, 195};
const uint8_t GenesisHash_Kusama[32] = {176, 168, 212, 147, 40, 92, 45, 247, 50, 144, 223, 183, 230, 31, 135, 15, 23, 180, 24, 1, 25, 122, 20, 156, 169, 54, 84, 73, 158, 163, 218, 254};
const uint8_t GenesisHash_BridgeHub_Polkadot[32] = {104, 213, 111, 21, 248, 93, 49, 54, 151, 14, 193, 105, 70, 4, 11, 193, 117, 38, 84, 233, 6, 20, 127, 126, 67, 233, 213, 57, 215, 195, 222, 47};
const uint8_t GenesisHash_BridgeHub_Kusama[32] = {72, 35, 158, 246, 7, 215, 146, 136, 116, 2, 122, 67, 166, 118, 137, 32, 151, 39, 223, 179, 211, 220, 94, 91, 3, 163, 155, 220, 46, 218, 119, 26};
const uint8_t GenesisHash_Equilibrium[32] = {137, 211, 236, 70, 210, 251, 67, 239, 90, 151, 19, 131, 51, 115, 213, 234, 102, 107, 9, 47, 168, 253, 104, 251, 195, 69, 150, 3, 101, 113, 185, 7};
const uint8_t GenesisHash_Genshiro[32] = {155, 140, 239, 192, 235, 92, 86, 139, 82, 121, 152, 189, 215, 108, 24, 78, 43, 118, 174, 86, 27, 231, 110, 70, 103, 7, 34, 48, 33, 126, 162, 67};
const uint8_t GenesisHash_Acala[32] = {252, 65, 185, 189, 142, 248, 254, 83, 213, 140, 126, 166, 124, 121, 76, 126, 201, 167, 61, 175, 5, 230, 213, 75, 20, 255, 99, 66, 201, 155, 166, 76};
const uint8_t GenesisHash_Karura[32] = {186, 245, 170, 190, 64, 100, 109, 17, 240, 238, 138, 187, 220, 100, 244, 164, 183, 103, 73, 37, 203, 160, 142, 74, 5, 255, 158, 190, 214, 226, 18, 107};
const uint8_t GenesisHash_Bifrost_Polkadot[32] = {38, 46, 27, 42, 215, 40, 71, 95, 214, 254, 136, 230, 45, 52, 194, 0, 171, 230, 253, 105, 57, 49, 221, 173, 20, 64, 89, 177, 235, 136, 78, 91};
const uint8_t GenesisHash_Bifrost_Kusama[32] = {159, 40, 198, 166, 142, 15, 201, 100, 110, 255, 100, 147, 86, 132, 246, 238, 238, 206, 82, 126, 55, 187, 225, 242, 19, 210, 44, 170, 29, 157, 107, 237};
const uint8_t GenesisHash_Nodle[32] = {151, 218, 126, 222, 152, 215, 186, 212, 227, 107, 77, 115, 75, 96, 85, 66, 90, 59, 224, 54, 218, 42, 51, 46, 165, 167, 3, 118, 86, 66, 122, 33};
const uint8_t GenesisHash_Zeitgeist[32] = {27, 242, 162, 236, 180, 168, 104, 222, 102, 234, 134, 16, 242, 206, 124, 140, 67, 112, 101, 97, 182, 71, 96, 49, 49, 95, 102, 64, 254, 56, 224, 96};
const uint8_t GenesisHash_Astar[32] = {158, 183, 108, 81, 132, 196, 171, 134, 121, 210, 213, 216, 25, 253, 249, 11, 156, 0, 20, 3, 233, 225, 125, 162, 225, 75, 109, 138, 236, 64, 41, 198};
const uint8_t GenesisHash_Shiden[32] = {241, 207, 144, 34, 199, 235, 179, 75, 22, 45, 91, 94, 52, 231, 5, 165, 167, 64, 178, 208, 236, 193, 0, 159, 184, 144, 35, 230, 42, 72, 129, 8};
const uint8_t GenesisHash_Mangata[32] = {0xd6, 0x11, 0xf2, 0x2d, 0x29, 0x1c, 0x5b, 0x7b, 0x69, 0xf1, 0xe1, 0x05, 0xcc, 0xa0, 0x33, 0x52, 0x98, 0x4c, 0x34, 0x4c, 0x44, 0x21, 0x97, 0x7e, 0xfa, 0xa4, 0xcb, 0xdd, 0x18, 0x34, 0xe2, 0xaa};
const uint8_t GenesisHash_Hydradx[32] = {175, 220, 24, 143, 69, 199, 29, 172, 186, 160, 182, 46, 22, 169, 31, 114, 108, 123, 134, 153, 169, 116, 140, 223, 113, 84, 89, 222, 107, 127, 54, 109};
const uint8_t GenesisHash_Basilisk[32] = {168, 92, 251, 155, 159, 212, 214, 34, 165, 178, 130, 137, 160, 35, 71, 175, 152, 125, 143, 115, 250, 49, 8, 69, 14, 43, 74, 17, 193, 206, 87, 85};

bool _readKnownChainType(parser_tx_t *v) {
    if(!memcmp(v->genesisHash._ptr, GenesisHash_Polkadot, 32)){
        v->knownChainType = KnownChainType_Polkadot;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Kusama, 32)){
        v->knownChainType = KnownChainType_Kusama;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_BridgeHub_Polkadot, 32)){
        v->knownChainType = KnownChainType_BridgeHub_Polkadot;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_BridgeHub_Kusama, 32)){
        v->knownChainType = KnownChainType_BridgeHub_Kusama;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Equilibrium, 32)){
        v->knownChainType = KnownChainType_Equilibrium;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Genshiro, 32)){
        v->knownChainType = KnownChainType_Genshiro;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Acala, 32)){
        v->knownChainType = KnownChainType_Acala;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Karura, 32)){
        v->knownChainType = KnownChainType_Karura;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Bifrost_Polkadot, 32)){
        v->knownChainType = KnownChainType_Bifrost_Polkadot;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Bifrost_Kusama, 32)){
        v->knownChainType = KnownChainType_Bifrost_Kusama;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Nodle, 32)){
        v->knownChainType = KnownChainType_Nodle;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Zeitgeist, 32)){
        v->knownChainType = KnownChainType_Zeitgeist;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Astar, 32)){
        v->knownChainType = KnownChainType_Astar;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Shiden, 32)){
        v->knownChainType = KnownChainType_Shiden;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Mangata, 32)){
        v->knownChainType = KnownChainType_Mangata;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Hydradx, 32)){
        v->knownChainType = KnownChainType_Hydradx;

    } else if(!memcmp(v->genesisHash._ptr, GenesisHash_Basilisk, 32)){
        v->knownChainType = KnownChainType_Basilisk;

    } else {
        v->decoderState = DecoderState_UnknownChain;
        return false;
    }
    v->decoderState = DecoderState_Ok;
    return true;
}

bool _readMethod(parser_tx_t *v) {
    switch (v->knownChainType) {
        case KnownChainType_Polkadot:
            return _readMethod_Polkadot(v);

        case KnownChainType_Kusama:
             return _readMethod_Kusama(v);

        case KnownChainType_BridgeHub_Polkadot:
             return _readMethod_BridgeHub_Polkadot(v);
        
        case KnownChainType_Astar:
             return _readMethod_Astar(v);

        case KnownChainType_Equilibrium:
             return _readMethod_Equilibrium(v);
        
        // TODO_GRANT: fill all chains

        default:
            return false;
    }
}