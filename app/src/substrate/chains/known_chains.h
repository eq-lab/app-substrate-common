#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../parser_txdef.h"

bool _readKnownChainType(parser_tx_t *v);

const char* _getMethod_chainName(known_chain_type_t knownChainType);

#ifdef __cplusplus
}
#endif