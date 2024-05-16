#include"headers.h"
#include"declarations.h"

static void __exit cleanup(void)
{
#ifdef DEBUG
	printk(KERN_INFO "%s: Begin.\n",__func__);
#endif
	kfree(bdev);
	if(majorno >0)
		unregister_blkdev(majorno,BDDNAME);
#ifdef DEBUG
	printk(KERN_INFO "%s: End.\n",__func__);
#endif
}
module_exit(cleanup);
