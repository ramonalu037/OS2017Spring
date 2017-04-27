#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage long sys_Show(void)
{
	printk("Ok, try this\nAnd this\n");

	
	return 0;
}

