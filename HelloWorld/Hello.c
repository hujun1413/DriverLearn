#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("Jun Hu");
MODULE_DESCRIPTION("My first device driver, Hello world");
MODULE_VERSION("V0.0--2017/03/12");
MODULE_LICENSE("GPL");

static int howmany = 1;
static char* whom = "world";
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init hello_init(void)
{
	int i = 0;
	for(i=0; i<howmany; ++i)
	{
		printk(KERN_EMERG "Hello, %s~\n", whom);
	}
	return 0;
}

static void __exit hello_exit(void)
{
	int i = 0;
	for(i=0; i<howmany; ++i)
	{
		printk(KERN_EMERG "Goodbye, cruel %s!\n", whom);
	}
}

module_init(hello_init);
module_exit(hello_exit);
