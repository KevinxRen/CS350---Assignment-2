ifeq ($(KERNELRELEASE),)
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

syscall_test:
	gcc -Wall user_time.c -o syscall_test

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -r *.o *~ core >depends .*.cmd *.ko *.mod.c .tmp_versions syscall_test

.PHONY: modules modules_install clean

else
	obj-m := mytime_module.o user_mytime.o 

endif
