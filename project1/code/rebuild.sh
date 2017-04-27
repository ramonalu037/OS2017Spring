#!/bin/bash
# Rebuild Linux kernel 2.6.32.60
# Assuming already made "menuconfig"
# Will not update grub
# Will not shutdown and reboot

# Directory of Linux kernel source files
dir=/usr/src/linux-2.6.32.60

# Enter the number of cores to use
read -p 'Enter the number of cores you want to use for rebuild: ' ncore

# Copy files to their directories
sudo cp -t ${dir}/arch/x86/kernel/ syscall_table_32.S
sudo cp -t ${dir}/arch/x86/include/asm/ unistd_32.h syscalls.h
sudo cp -t ${dir}/kernel/ Makefile Show.c Multiply.c Min.c \
	returnzero.c CPU_Utilization.c

# Rebuild
sudo make -B -j${ncore} -C ${dir} bzImage
#sudo make -j${ncore} -C ${dir} modules
#sudo make -j${ncore} -C ${dir} modules_install
sudo make -B -j${ncore} -C ${dir} install
