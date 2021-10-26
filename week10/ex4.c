#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
	DIR *dirp=opendir("./tmp");
	if (dirp == NULL) {return -1;}
	struct dirent *dp = malloc(sizeof(struct dirent));
	struct stat* stats = malloc(sizeof(struct stat));
	while (( dp = readdir ( dirp )) != NULL ) {
		if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name,"..") == 0){

	        } else {
         		char file_n[260];
			snprintf(file_n, sizeof(file_n), "%s%s", "tmp/", dp->d_name);
			stat(file_n, stats);
        		if (stats->st_nlink > 1) {
               			printf("%s - ", dp->d_name);
                		DIR *dir1 = opendir("./tmp");//safe since we know, that we are in this directory
                		struct dirent* dp1 = malloc(sizeof(struct dirent));
                		struct stat* stats1 = malloc(sizeof(struct stat));
				while ( (dp1 = readdir ( dir1 )) != NULL ) {
                    			char file_n1[260];
                    			snprintf(file_n1, sizeof(file_n1), "%s%s", "tmp/", dp1->d_name);
                    			stat(file_n1, stats1);
                    			if (stats1->st_ino == stats->st_ino) {
                    				printf("%s ", dp->d_name);
                    			}
                		}
            			printf("\n");
           		 }
      		}
	}
	(void)closedir(dirp);
	return 0;
}
