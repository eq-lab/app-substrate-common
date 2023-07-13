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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

static const char* STR_SUBSTRATE = "Substrate";

// Pallet names
static const char* STR_MO_Assets = "Assets";
static const char* STR_MO_Balances = "Balances";


// Methods names
static const char* STR_ME_SIGN = "Sign";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char* STR_ME_TRANSFER_KEEP_LIVE = "Transfer keep live";

// Items names
static const char* STR_IT_network = "Network";
static const char* STR_IT_tx_hash = "Tx hash";
static const char* STR_IT_genesis_hash = "Genesis hash";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_value = "Value";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_id = "Id";
static const char* STR_IT_target = "Target";
static const char* STR_IT_amount = "Amount";


// Chains names
static const char* STR_CH_Unknown = "Unknown";
static const char* STR_CH_Polkadot = "Polkadot";
static const char* STR_CH_Kusama = "Kusama";
static const char* STR_CH_AssetHub_Polkadot = "AssetHub(DOT)";
static const char* STR_CH_AssetHub_Kusama = "AssetHub(KSM)";
static const char* STR_CH_Equilibrium = "Equlibrium";
static const char* STR_CH_Genshiro = "Genshiro";
static const char* STR_CH_Acala = "Acala";
static const char* STR_CH_Karura = "Karura";
static const char* STR_CH_Bifrost_Polkadot = "Bifrost(DOT)";
static const char* STR_CH_Bifrost_Kusama = "Bifrost(KSM)";
static const char* STR_CH_Nodle = "Nodle";
static const char* STR_CH_Zeitgeist = "Zeitgeist";
static const char* STR_CH_Astar = "Astar";
static const char* STR_CH_Shiden = "Shiden";
static const char* STR_CH_Mangata = "MangataX";
static const char* STR_CH_Hydradx = "HydraDX";
static const char* STR_CH_Basilisk = "Basilisk";


#ifdef __cplusplus
}
#endif
