#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "../../parser_txdef.h"
#include "../../common/parser_common.h"

bool _readMethod_balances(parser_context_t *c, parser_tx_t *v);

uint8_t _getMethod_NumItems_Balances(uint8_t callIdx);

const char* _getMethod_ModuleName_Balances();

const char* _getMethod_Name_Balances(uint8_t callIdx);

const char* _getMethod_ItemName_Balances(uint8_t callIdx, uint8_t itemIdx);

parser_error_t _getMethod_ItemValue_Balances(
    pd_Method_t* m, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount);


// TODO_GRANT:

// bool _getMethod_ItemIsExpert(uint32_t transactionVersion, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx);

#ifdef __cplusplus
}
#endif