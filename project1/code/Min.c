#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage double sys_Min(const double a, const double b)
{
	if(a<b)
		return a;
	else
		return b;
}

