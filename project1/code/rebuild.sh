#!/bin/bash
# Rebuild Ubuntu2.6.32.60
# Assuming already made "menuconfig"
# Will not update grub
# Will not shutdown and reboot

# Directory of Ubuntu source files
dir = usr/src/linux-2.6.32.60

# Enter the number of cores to use
read -p "\nEnter the number of cores you want to use for rebuild: " ncore

# Rebuild
sudo $(dir)/make -j$(ncore) bzImage
#sudo $(dir)/make -j$(ncore) modules
#sudo $(dir)/make -j$(ncore) modules_install
#sudo $(dir)/make -j$(ncore) install
