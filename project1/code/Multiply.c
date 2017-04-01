#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage double sys_Multiply(const double a, const double b)
{
	return a*b;
}

