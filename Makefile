INSTALL_DIR=modules
ifneq ($(KERNELRELEASE),)
	obj-m := blkdd.o

blkdd-objs:= init.o clean.o
	
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	${MAKE} -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf $(INSTALL_DIR)
	@mkdir $(INSTALL_DIR)
	@mv -f *.o *.ko *.mod.c .*.cmd *.mod *.order *.symvers ${INSTALL_DIR}


clean:
	rm -rf ${INSTALL_DIR}
	rm -rf *.o *.ko *.mod.c .*.cmd *.mod *.order *.symvers
endif
