#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 100

struct timeval gtodTime[N];
char *procClockTime[N];

void * kmalloc (size_t size, int flags);

FIlE *fd;
fd = open("/dev/mytime", O_RDONLY);
if(fd == NULL){
	perror("Error");
}

for(i = 0; i < N; i++){
	gettimeofday(&gtodTimes[i],0);
	int bytes_read = read(fd, procClocTime[i], MAX_LENGTH);	
}

close(fd);

for(i = 0; i < N; i++){
	printf("Gettimeofday: %ld\n Module Time: %ld\n", gtodTimes[i], procClockTimes[i]);
}
