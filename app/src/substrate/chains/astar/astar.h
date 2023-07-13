#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../../parser_txdef.h"
#include "../../common/parser_common.h"

parser_error_t _readMethod_Astar(parser_context_t *c, parser_tx_t *v);

// TODO_GRANT:
// uint8_t _getMethod_NumItems_(uint8_t moduleIdx, uint8_t callIdx);
// const char* _getMethod_ModuleName(uint32_t transactionVersion, uint8_t moduleIdx);
// const char* _getMethod_Name(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx);
// const char* _getMethod_ItemName(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

// parser_error_t _getMethod_ItemValue(
//     uint32_t transactionVersion,
//     pd_Method_t* m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
//     char* outValue, uint16_t outValueLen,
//     uint8_t pageIdx, uint8_t* pageCount);

// bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

#ifdef __cplusplus
}
#endif