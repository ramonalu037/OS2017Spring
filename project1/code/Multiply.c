#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage long sys_Multiply(const long a, const long b)
{
	return a*b;
}

