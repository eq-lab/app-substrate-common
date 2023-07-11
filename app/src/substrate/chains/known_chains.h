#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../parser_txdef.h"

bool _readKnownChainType(parser_tx_t *v);

bool _readMethod(parser_tx_t *v);

#ifdef __cplusplus
}
#endif