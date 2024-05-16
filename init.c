#include"headers.h"
#include"declarations.h"
int majorno,nsectors,hardsect_size;
struct blkdev *bdev;

char *blkdev_catalog = "blkdev1, 1024; blkdev2, 2048";
static int __init init_bdd(void)
{
	int ret =0,len;
	char *catalog, *nextToken;
#ifdef DEBUG
	printk(KERN_INFO "%s: Begin.\n",__func__);
#endif
	majorno = MAJORNO;
	nsectors = NSECTORS;
	hardsect_size = HARDSECT_SIZE;

	majorno = register_blkdev(majorno,BDDNAME);
	if(majorno <=0 )
	{
#ifdef DEBUG
		pr_err("%s: ERROR: register_blkdev() failure.\n",__func__);
		return -EBUSY;
#endif		
		//goto FAIL;
	}
#ifdef DEBUG
	printk(KERN_INFO "MAjor No: %d\n",majorno);
	printk(KERN_INFO "END: %s\n",__func__);
#endif
	bdev = kzalloc(sizeof(struct blkdev),GFP_KERNEL);
	if(!bdev)
	{
		ret = -ENOMEM;
		pr_err("%s: Error: Line-%d; kzalloc failure.\n", __func__, __LINE__);
		goto FAIL;
	}
	len = strlen(blkdev_catalog);
	if((len < 1)&&(len > PAGE_SIZE))
	{
		pr_err("%s:ERROR: Line-%d: Invalid Module Parameter. Catalog\n",__func__,__LINE__);
		ret = -EBUSY;
		goto FAIL;
	}
	

	catalog = kzalloc(len+1,GFP_KERNEL);
	if(!catalog)
	{
		ret = -ENOMEM;
		pr_err("%s: ERROR: Line-%d;kzalloc failure.\n",__func__,__LINE__);
		goto FAIL;

	}
	strcpy(catalog,blkdev_catalog);
	nextToken = catalog;

	printk(KERN_INFO "%s:End.\n",__func__);
	return 0;
FAIL:
#ifdef DEBUG
	pr_err("%s:ERROR : register_blkdev() failure.\n",__func__);
#endif
	return ret;

}
module_init(init_bdd);
