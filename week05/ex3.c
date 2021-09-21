#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int status[2]={1,0};// 1st- producer 2nd - consumer
int buffer[10]={0};
int i=0;

void goSleep(int id){
status[id]=0;
}

void awake(int id){
status[id]=1;
}

void *producer(int* n);
void *consumer(int* n);
void *checker(void* n);

int main(){
pthread_t consumerId;
pthread_t producerId;
pthread_t checkerId;
pthread_create(&checkerId,NULL,checker,NULL);
pthread_create(&producerId,NULL,producer,NULL);
pthread_create(&consumerId,NULL,consumer,NULL);
pthread_join(producerId,NULL);
}

void *producer(int* n){
while (1){
	if (!status[0]){
	continue;
	}
	while (i<10){
		buffer[i]=rand()%20 + 1;
		i++;
	}
	awake(1);//awake consumer
	goSleep(0);//producer goes to sleep
}
}

void *consumer(int* n){
while (1){
	if (!status[1]){
	continue;
	}
	while (i>0){
		buffer[i]=0;
		i--;
	}
	awake(0);// awake producer
	goSleep(1);// consumer goes to sleep
}
}

void *checker(void* n){
while (1){
	sleep(1);
	if (status[0]==status[1]){
		printf("Fatal race condition occured: both treads are sleepeng now\n");
		break;
	}
	}
}
