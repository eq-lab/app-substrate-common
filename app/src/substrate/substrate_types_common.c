#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readTxHash(parser_context_t* c, pd_Method_Common_t* v)
{
    CHECK_INPUT();
    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 256);
    cx_hash(&ctx.header, CX_LAST, c->buffer, c->bufferLen, v->txHash, BLAKE2B_DIGEST_SIZE);

    c->offset = c->bufferLen;

    return parser_ok;
}

parser_error_t _readGenesisHash(parser_context_t* c, pd_Hash_t* v) {
    // Methods are not length delimited so in order to retrieve the genesisHash
    // it is necessary to parse from the back.
    // The transaction is expect to end in
    // [32 bytes] genesisHash
    // [32 bytes] blockHash
    const uint16_t genesisHashOffsetFromBack = 32 + 32;
    if (c->bufferLen < genesisHashOffsetFromBack) {
        return parser_unexpected_buffer_end;
    }
    uint16_t offset = c->offset;
    c->offset = c->bufferLen - genesisHashOffsetFromBack;
    parser_error_t err = _readHash(c, v);
    c->offset = offset;
    return err;
}

parser_error_t _toStringTransactionHash(
    const pd_TransactionHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[102];
    bufferUI[0] = '0';
    bufferUI[1] = 'x';
    array_to_hexstr(&bufferUI[2], 100, (uint8_t*)v, 32);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}


const uint8_t GenesisHash_Polkadot[32] = {145, 177, 113, 187, 21, 142, 45, 56, 72, 250, 35, 169, 241, 194, 81, 130, 251, 142, 32, 49, 59, 44, 30, 180, 146, 25, 218, 122, 112, 206, 144, 195};
const uint8_t GenesisHash_Kusama[32] = {176, 168, 212, 147, 40, 92, 45, 247, 50, 144, 223, 183, 230, 31, 135, 15, 23, 180, 24, 1, 25, 122, 20, 156, 169, 54, 84, 73, 158, 163, 218, 254};
const uint8_t GenesisHash_Statemint[32] = {104, 213, 111, 21, 248, 93, 49, 54, 151, 14, 193, 105, 70, 4, 11, 193, 117, 38, 84, 233, 6, 20, 127, 126, 67, 233, 213, 57, 215, 195, 222, 47};
const uint8_t GenesisHash_Statemine[32] = {72, 35, 158, 246, 7, 215, 146, 136, 116, 2, 122, 67, 166, 118, 137, 32, 151, 39, 223, 179, 211, 220, 94, 91, 3, 163, 155, 220, 46, 218, 119, 26};
const uint8_t GenesisHash_Equilibrium[32] = {137, 211, 236, 70, 210, 251, 67, 239, 90, 151, 19, 131, 51, 115, 213, 234, 102, 107, 9, 47, 168, 253, 104, 251, 195, 69, 150, 3, 101, 113, 185, 7};
const uint8_t GenesisHash_Genshiro[32] = {155, 140, 239, 192, 235, 92, 86, 139, 82, 121, 152, 189, 215, 108, 24, 78, 43, 118, 174, 86, 27, 231, 110, 70, 103, 7, 34, 48, 33, 126, 162, 67};
const uint8_t GenesisHash_Acala[32] = {252, 65, 185, 189, 142, 248, 254, 83, 213, 140, 126, 166, 124, 121, 76, 126, 201, 167, 61, 175, 5, 230, 213, 75, 20, 255, 99, 66, 201, 155, 166, 76};
const uint8_t GenesisHash_Karura[32] = {186, 245, 170, 190, 64, 100, 109, 17, 240, 238, 138, 187, 220, 100, 244, 164, 183, 103, 73, 37, 203, 160, 142, 74, 5, 255, 158, 190, 214, 226, 18, 107};
const uint8_t GenesisHash_Bifrost_Polkadot[32] = {38, 46, 27, 42, 215, 40, 71, 95, 214, 254, 136, 230, 45, 52, 194, 0, 171, 230, 253, 105, 57, 49, 221, 173, 20, 64, 89, 177, 235, 136, 78, 91};
const uint8_t GenesisHash_Bifrost_Kusama[32] = {159, 40, 198, 166, 142, 15, 201, 100, 110, 255, 100, 147, 86, 132, 246, 238, 238, 206, 82, 126, 55, 187, 225, 242, 19, 210, 44, 170, 29, 157, 107, 237};
const uint8_t GenesisHash_Nodle[32] = {151, 218, 126, 222, 152, 215, 186, 212, 227, 107, 77, 115, 75, 96, 85, 66, 90, 59, 224, 54, 218, 42, 51, 46, 165, 167, 3, 118, 86, 66, 122, 33};
const uint8_t GenesisHash_Astar[32] = {158, 183, 108, 81, 132, 196, 171, 134, 121, 210, 213, 216, 25, 253, 249, 11, 156, 0, 20, 3, 233, 225, 125, 162, 225, 75, 109, 138, 236, 64, 41, 198};
const uint8_t GenesisHash_Shiden[32] = {241, 207, 144, 34, 199, 235, 179, 75, 22, 45, 91, 94, 52, 231, 5, 165, 167, 64, 178, 208, 236, 193, 0, 159, 184, 144, 35, 230, 42, 72, 129, 8};


static const char* getChainName(uint8_t* genesisHash) {
    if(!memcmp(genesisHash, GenesisHash_Polkadot, 32)){
        return STR_CH_Polkadot;
    } else if(!memcmp(genesisHash, GenesisHash_Polkadot, 32)){
        return STR_CH_Polkadot;
    } else if(!memcmp(genesisHash, GenesisHash_Kusama, 32)){
        return STR_CH_Kusama;
    } else if(!memcmp(genesisHash, GenesisHash_Statemint, 32)){
        return STR_CH_Statemint;
    } else if(!memcmp(genesisHash, GenesisHash_Statemine, 32)){
        return STR_CH_Statemine;
    } else if(!memcmp(genesisHash, GenesisHash_Equilibrium, 32)){
        return STR_CH_Equilibrium;
    } else if(!memcmp(genesisHash, GenesisHash_Genshiro, 32)){
        return STR_CH_Genshiro;
    } else if(!memcmp(genesisHash, GenesisHash_Bifrost_Polkadot, 32)){
        return STR_CH_Bifrost_Polkadot;
    } else if(!memcmp(genesisHash, GenesisHash_Bifrost_Kusama, 32)){
        return STR_CH_Bifrost_Kusama;
    } else if(!memcmp(genesisHash, GenesisHash_Nodle, 32)){
        return STR_CH_Nodle;
    } else if(!memcmp(genesisHash, GenesisHash_Astar, 32)){
        return STR_CH_Astar;
    } else if(!memcmp(genesisHash, GenesisHash_Shiden, 32)){
        return STR_CH_Shiden;
    }
    return NULL;
}

parser_error_t _toStringGenesisHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    const char* chainName = getChainName(v->_ptr);
    if (chainName != NULL) {
        pageString(outValue, outValueLen, chainName, pageIdx, pageCount);
    } else {
        char bufferUI[102];
        bufferUI[0] = '0';
        bufferUI[1] = 'x';
        array_to_hexstr(&bufferUI[2], 100, v->_ptr, 32);
        pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    }
    return parser_ok;
}
