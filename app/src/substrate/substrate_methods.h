/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define GET_PD_CALL(CALL, VERSION) (PD_CALL_##CALL##_V##VERSION)

#include "substrate_methods_common.h"
#include "substrate_types_common.h"
#include "known_chain_types.h"

typedef union {
    // common methods
    pd_Method_Balances_t balances;
    pd_Method_Assets_t assets;

    // unique methods
    pd_Method_Equilibrium_t equilibrium;
    // TODO_GRANT: fill with all unique methods
} pd_Method_t;

typedef union {
    char remove_me; // TODO_GRANT
    char remove_me2;
} pd_MethodNested_t;

#ifdef __cplusplus
}
#endif
