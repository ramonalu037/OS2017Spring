#!/bin/bash
# Rebuild Ubuntu2.6.32.60
# Assuming already made "menuconfig"
# Will not update grub
# Will not shutdown and reboot

# Directory of Ubuntu source files
dir=/usr/src/linux-2.6.32.60

# Enter the number of cores to use
read -p 'Enter the number of cores you want to use for rebuild: ' ncore

# Rebuild
sudo make -j${ncore} -C ${dir} bzImage
sudo make -j${ncore} -C ${dir} modules
sudo make -j${ncore} -C ${dir} modules_install
sudo make -j${ncore} -C ${dir} install
