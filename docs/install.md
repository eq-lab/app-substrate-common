# Installation guide

## Prerequisites

### MacOS
1. Check python3 version
```bash
python3 --version
```

2. If you see _"zsh: command not found: python3"_ message, install it:
- Install [homebrew](https://brew.sh/)
- Install python3 using terminal:
```bash 
brew install python3
```
3. Install ledgerblue package:
```bash 
pip3 install ledgerblue
```

### Linux
1. Install python3 using terminal:
```bash
sudo apt install python3 python3-pip 
```

2. Add rules to resolve __OSError: open failed__ error:
```bash
wget -q -O - https://raw.githubusercontent.com/LedgerHQ/udev-rules/master/add_udev_rules.sh | sudo bash
```
3. Install ledgerblue package:
```bash 
pip install ledgerblue --user
```

### Windows
1. Install [Git Bash](https://git-scm.com/downloads)
2. Install [Python3](https://www.python.org/downloads/windows/)
3. Install ledgerblue package:
```bash 
pip install ledgerblue --user
```

## Load app to Ledger device
1. Go to [latest release page](https://github.com/eq-lab/app-substrate-common/releases/latest)
2. Download __installer_s.sh__ for Ledger Nano S, or __installer_s2.sh__ for Ledger Nano S Plus
   ![](../imgs/install_1.png)
3. Connect Ledger device to computer via USB
4. Unlock Ledger and go to catalog of apps screen
   ![](../imgs/install_2.png)
5. Execute installer script:

- On Linux:
```bash
chmod +rwx installer_s.sh 
installer_s.sh load
```

- On Mac OS:
```bash
/bin/bash installer_s.sh load
```

- On Windows:
```bash
installer_s.sh load
```
You will receive a _"No dongle found"_ error message if any of these conditions are not met:
- Ledger device is connected to a computer via a USB
- Ledger device is unlocked
- A page of apps catalog is opened on Ledger

### Confirmation installation on Ledger
On the Ledger device, you will see these pages:

![](../imgs/install_3.jpg)

Click the left button and select _"Allow unsafe manager"_:

![](../imgs/install_4.jpg)

App will be loaded to Ledger device:

![](../imgs/install_5.jpg)

After app loading is finished, the page _"Install app Substrate"_ will be open:

![](../imgs/install_6.jpg)

Click twice the left button and select _"Perform installation"_:

![](../imgs/install_7.jpg)

Enter PIN to confirm installation:

![](../imgs/install_8.jpg)

After confirmation app will be ready to use:

![](../imgs/install_9.jpg)