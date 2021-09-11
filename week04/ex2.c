#include <stdio.h>
#include <stdlib.h>

int main(){
int pid;
for (int i=0;i<5;i++){
	pid=fork();
	sleep(5);
}
}
