#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>

int main() {
	// Show ID and name
	syscall(337);
	
	// Multiply
	double a = 0.6;
	double b = 1.2;
	double res = syscall(338, a, b);
	printf("%.3f * %.3f = %.3f\n", a, b, res);
	
	// Min
	res = syscall(339, a, b);
	printf("min(%.3f, %.3f) = %.3f\n", a, b, res);
	
	// CPU_Utilization
	syscall(341);
	
	return 0;
}

