#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
char str[256];
char* argv[4];
argv[0]="/bin/sh";
argv[1]="-c";
argv[3]=NULL;
int status;
while (1){
	fgets(str,255,stdin);
	argv[2]=str;
	int pid=fork();
	if (pid == 0){
		execvp("/bin/sh",argv);
	} else {
		while(wait(&status) != pid);
	}
}
}
