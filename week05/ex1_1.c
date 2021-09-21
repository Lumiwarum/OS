#include <stdio.h>
#include <pthread.h>

void *thread(int* n){
printf("Hello from thread %d\n",*n);
return NULL;
}

int main(){
pthread_t threadId;
for (int i=0;i<3;i++){
	printf("Creating thread %d\n",i);
	pthread_create(&threadId,NULL,thread,&i);
	printf("Terminating thread %d\n",i);
}
}
