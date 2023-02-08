#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "coin.h"
// #include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>


typedef uint8_t pd_TransactionHash_t[BLAKE2B_DIGEST_SIZE];

typedef union {
    pd_TransactionHash_t txHash;
} pd_Method_Common_t;


#ifdef __cplusplus
}
#endif
