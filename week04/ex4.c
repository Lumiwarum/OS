#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
char str[256];
char* argv[4];
argv[0]="/bin/sh";
argv[1]="-c";
argv[3]=NULL;
int wstatus,pid;
while (1){
	fgets(str,255,stdin);
	argv[2]=str;
	pid=fork();
	if (pid == 0){
		execvp(argv[0],argv);
	} else {
		while(wait(&wstatus) != pid);
	}
}
}
