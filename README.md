# WIP: Ledger Substrate common App

This project contains implementation of the Substrate common app for Ledger hardware wallets.

For more information: 
- [forum post](https://forum.polkadot.network/t/unified-ledger-app-for-substrate-based-parachains/2027)
- [demo](https://github.com/eq-lab/ledger-substrate-app-demo) of using this app to sign transactions on parachains
- [how to build](docs/build.md)
- [how to install](docs/install.md) ([video guide](https://www.youtube.com/watch?v=TDInqy_1J68))

## ATTENTION

Please:
- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

## Examples of using
### Case 1. Known chain, known method
Polkadot chain, `Balances` pallet, `Transfer` method

![](imgs/1_case_1.jpg)

![](imgs/1_case_2.jpg)

![](imgs/1_case_3.jpg)

![](imgs/1_case_4.jpg)

![](imgs/1_case_5.jpg)

### Case 2. Known chain, unknown method
Polkadot chain

![](imgs/2_case_1.jpg)

![](imgs/2_case_2.jpg)

![](imgs/2_case_3.jpg)

![](imgs/2_case_4.jpg)

### Case 3. Unknown chain
Khala chain

![](imgs/3_case_1.jpg)

![](imgs/3_case_2.jpg)

![](imgs/3_case_3.jpg)

![](imgs/3_case_4.jpg)

![](imgs/3_case_5.jpg)

![](imgs/3_case_6.jpg)

## TODO
- [x] parse and display chain name / genesis hash
- [x] blind sign for not parsed method case
- [x] build on Mac M1
- [x] `balances::transfer` method for Polkadot chain
- [ ] other methods for `balances` pallet for Polkadot chain
- [ ] other chains
- [ ] derivation path settings
- [ ] Ledger Stax support
- [ ] tests
