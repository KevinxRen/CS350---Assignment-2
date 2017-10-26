#include <linux/init.h>
#include <linux/time.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static struct miscdevice mytime={
	.minor = MISC_DYNAMIC_MINOR
	.name = "mytime"
	.fops = &my_fops

};

static struct file_operations my_fops={
	.owner = THIS_MODULE
	.open = my_open
	.release = my_close
	.read = my_read
};

static ssize_t my_read(struct file *file, char _user* out, size_t size,loff_t* off){
	int error;

	if(!access_OK(out, buf, size, off, file){
		return -EFAULT;
	}

	error = copy_to_user(out, buf, strlen(buf)+1);

	if(error == 0){
		struct timespec time = current_kernel_time();
		struct timespec otherTime;
		sprintf(buf, "current_kernel_time: %ld\n getnstimeofday: &ld\n",time.tv_nsec,getnstimeofday(&otherTime));
		copy_to_user(out, buf, strleng(buf)+1);
	}else{
		return -EFAULT;
	}
}

static int my_open(struct file *file){
	printk(KERN_INFO "MYTIME is opened");
	return 0;
}

static int my_close(struct file *file){
	printk(KERN_INFO "MYTIME successfully closed");
	return 0;
}

static int _init mytime_init(){
	misc_register(&mytime);
	return 0;
}

static void _exit mytime_exit(void){
	misc_deregister(&mytime);
	return 0;
}

module_init(mytime_init);
module_exit(mytime_exit);
