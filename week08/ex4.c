#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>

int main() {
void* ptr;
struct rusage myusage;
	for (int i=0;i<10;i++){
		ptr=malloc(10485760);
		memset(ptr,0,10485760);
		getrusage(RUSAGE_SELF,&myusage);
		printf("Current usage: %ld\n",myusage.ru_maxrss);
		sleep(1);
	}
}

