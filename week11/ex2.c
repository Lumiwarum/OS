#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(){
	DIR *dir= opendir("/");
	if (dir==NULL) {return 0;}
	struct dirent *file = malloc(sizeof(struct dirent));

	while ((file = readdir(dir)) != NULL) {
		printf("Current file: %s\n", file->d_name);
	}

	(void)closedir(dir);
	return 0;
}
