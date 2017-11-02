#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/syscall.h>

#define _NR_sys_my_xtime 326

int main(){
	struct timespec currTime;

	int ret = syscall(_NR_sys_my_xtime, &currTime);

	printf("%ld\n", currTime.tv_nsec);

	return 0;
}
