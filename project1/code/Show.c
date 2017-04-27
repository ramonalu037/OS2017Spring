#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage long sys_Show(void)
{
	printk("D00222001 Yu-Hsiang Lin\nhellohello\n");
	
	return 0;
}

