MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gaurav");
MODULE_DESCRIPTION("Memory Allocation");

#ifndef DEBUG
#define DEBUG
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef BDDNAME
#define BDDNAME "BDD6.8"
#endif

#ifndef NSECTORS
#define NSECTORS 128
#endif

#ifndef HARDSECT_SIZE
#define HARDSECT_SIZE 1024
#endif

extern int majorno,nsectors,hardsect_size;

extern char *blkdev_catalog;
struct blkdev
{
	struct list_head link;
	sector_t capacity;
	u8 *data;
};
extern struct blkdev *bdev;
