#include<linux/kernel.h>
#include<linux/linkage.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

asmlinkage long sys_CPU_Utilization(void)
{
	int input_fd;
	ssize_t ret_in;
	const long buffer_size = 10000;
	char buffer[buffer_size];
	
	unsigned long long int usertime, nicetime, systemtime, idletime;
	unsigned long long int ioWait, irq, softIrq, steal, guest;
	unsigned long long int busyalltime, idlealltime, totaltime;
	
	input_fd = open('/proc/stat', O_RDONLY);
	
	while( ( ret_in = read(input_fd, &buffer, buffer_size) ) > 0 ) {
		sscanf(buffer, "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu", &usertime, &nicetime, &systemtime, &idletime, &ioWait, &irq, &softIrq, &steal, &guest);
	}
	
	usertime = usertime - guest;
	
	busyalltime = usertime + nicetime + systemtime + irq + softIrq + steal + guest;
	idlealltime = idletime + ioWait;
	totaltime = busyalltime + idlealltime;
	
	close(input_fd);
	
	
	
	sleep(2);
	
	
	
	unsigned long long int usertime2, nicetime2, systemtime2, idletime2;
	unsigned long long int ioWait2, irq2, softIrq2, steal2, guest2;
	unsigned long long int busyalltime2, idlealltime2, totaltime2;
	
	input_fd = open('/proc/stat', O_RDONLY);
	
	while( ( ret_in = read(input_fd, &buffer, buffer_size) ) > 0 ) {
		sscanf(buffer, "cpu  %16llu %16llu %16llu %16llu %16llu %16llu %16llu %16llu", &usertime2, &nicetime2, &systemtime2, &idletime2, &ioWait2, &irq2, &softIrq2, &steal2, &guest2);
	}
	
	usertime2 = usertime2 - guest2;
	
	busyalltime2 = usertime2 + nicetime2 + systemtime2 + irq2 + softIrq2 + steal2 + guest2;
	idlealltime2 = idletime2 + ioWait2;
	totaltime2 = busyalltime2 + idlealltime2;
	
	close(input_fd);
	
	
	
	printk("busyalltime = %llu, totaltime = %llu\n", busyalltime, totaltime);
	
	printk("busyalltime2 = %llu, totaltime2 = %llu\n", busyalltime2, totaltime2);
	
	return 0;
}
