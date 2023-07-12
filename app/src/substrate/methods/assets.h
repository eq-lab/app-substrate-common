#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "../../parser_txdef.h"
#include "../../common/parser_common.h"

bool _readMethod_assets(parser_context_t *c, parser_tx_t *v);

uint8_t _getMethod_NumItems_Assets(uint8_t callIdx);

const char* _getMethod_ModuleName_Assets();

const char* _getMethod_Name_Assets(uint8_t callIdx);

const char* _getMethod_ItemName_Assets(uint8_t callIdx, uint8_t itemIdx);

// TODO_GRANT:

// parser_error_t _getMethod_ItemValue(
//     uint32_t transactionVersion,
//     pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
//     char* outValue, uint16_t outValueLen,
//     uint8_t pageIdx, uint8_t* pageCount);

// bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

#ifdef __cplusplus
}
#endif