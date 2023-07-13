#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readTxHash(parser_context_t* c, pd_TransactionHash_t* txHash)
{
    cx_blake2b_t ctx;
    cx_blake2b_init(&ctx, 256);
    cx_hash(&ctx.header, CX_LAST, c->buffer, c->bufferLen, txHash, BLAKE2B_DIGEST_SIZE);

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

parser_error_t _toStringGenesisHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[102];
    bufferUI[0] = '0';
    bufferUI[1] = 'x';
    array_to_hexstr(&bufferUI[2], 100, v->_ptr, 32);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}
