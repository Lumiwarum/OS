#include <stdio.h>

void tree(int n,int* initial);

int main(int argc,char *argv[])
{
	if (argc != 2) {
		printf("Please execute program with only 1 parameter");
	}
	int height = 0;
	sscanf(argv[1],"%d",&height);
	tree(height,&height);
}

void tree(int n,int* initial){
	if (n>1) {
		tree(n-1,initial);
	}
	n=n*2-1;// calculate number of stars
	int freeSpaces=(*initial)*2-1 - n;// number of  free spaces
	for (int i=0;i<freeSpaces/2;i++){
		printf(" ");
	}
	for (int i=0;i<n;i++){
		printf("*");
	}
	printf("\n");
}
