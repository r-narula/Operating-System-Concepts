// learning about creating a kernel module and loading it into the kernel of linux
// The following program illustrates a very basic kernel module that prints appropriate
// messages when the kernel module is loaded and unloaded.

#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

static void hello_init(void)
{
    printk(KERN_ALERT"TEST: Hello world, This is a mononoke!");
    return 0;
}

statsi void hello_exit(void)
{
    printk(KERN_ALERT "TEST:Good Bye mononoke");
}
module_init(hello_init);
module_exit(hello_exit);