#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage long sys_Min(const long a, const long b)
{
	if(a<b)
		return a;
	else
		return b;
}

