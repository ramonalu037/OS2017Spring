#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>

int main() {
	syscall(338);
	return 0;
}

