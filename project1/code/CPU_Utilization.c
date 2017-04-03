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
	
	printk("busyalltime = %llu, totaltime = %llu\n", busyalltime, totaltime);
	
	return 0;
}
