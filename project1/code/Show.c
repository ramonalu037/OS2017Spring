#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage long sys_Show(void)
{
	printk("Again\nGit git git\n");
	
	return 0;
}

