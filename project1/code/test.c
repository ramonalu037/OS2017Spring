#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>

int main() {
	// Show ID and name
	syscall(337);
	
	// Multiply
	long a = 52;
	long b = 385;
	long res = syscall(338, a, b);
	printf("%ld * %ld = %ld\n", a, b, res);
	
	// Min
	res = syscall(339, a, b);
	printf("min(%ld, %ld) = %ld\n", a, b, res);
	
	return 0;
}

