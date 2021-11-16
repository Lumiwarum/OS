#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("input.txt","r");
	if (fp==NULL) {return 1;}
	int C[5][3];
	int R[5][3];
	int A[3];
	int E[3];
	fscanf(fp,"%d %d %d",&E[0],&E[1],&E[2]);
	fscanf(fp,"%d %d %d",&A[0],&A[1],&A[2]);
	for (int i=0;i<5;i++){
		fscanf(fp,"%d %d %d",&C[i][0],&C[i][1],&C[i][2]);
	}
	for (int i=0;i<5;i++){
                fscanf(fp,"%d %d %d",&R[i][0],&R[i][1],&R[i][2]);
        }
	int modified=1;
	while (modified>0){
		modified=0;
		for (int i=0;i<5;i++){
			if ((R[i][0]<=A[0])&&(R[i][1]<=A[1])&&(R[i][2]<=A[2])){
				A[0]+=C[i][0];
				A[1]+=C[i][1];
				A[2]+=C[i][2];
				R[i][0]=E[0]+1;
				modified=1;
			}
		}
	}
	modified=1;
	for (int i=0;i<5;i++){
		if (R[i][0]!=E[0]+1){
			modified=0;
			printf("Process %d is deadlocked\n",i);
		}
	}
	if (modified==1){
		printf("There is no deadlock\n");
	}
}
