#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_types_common.h"
#include <stddef.h>
#include <stdint.h>

parser_error_t _readTxHash(parser_context_t* c, pd_TransactionHash_t* v);

parser_error_t _readGenesisHash(parser_context_t* c, pd_Hash_t* v);

parser_error_t _toStringTransactionHash(
    const pd_TransactionHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);
    
parser_error_t _toStringGenesisHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
