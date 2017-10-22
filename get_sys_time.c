
#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/time.h>
#include <linux/printk.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

SYSCALL_DEFINE1(my_xtime, struct timespec _user *, current_time){
	struct timespec currTime = current_kernel_time();

	if(!access_ok(VERIFY_WRITE, current_time, sizeof(struct timespec))){
		return -EFAULT;
	}

	current_time->tv_sec = currTime.tv_sec;
	current_time->tv_nsec = currTime.tv_nsec;

	printk(KERN_INFO "Current time: %ld", current_time->tv_nsec);

	return 0;
}
