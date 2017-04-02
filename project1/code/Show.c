#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage long sys_Show(void)
{
	printk("R05922141 Ramona Lu\nD00222001 Yu-Hsiang Lin\n");
	return 0;
}

