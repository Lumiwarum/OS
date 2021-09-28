#include <stdio.h>
#include <stdlib.h>

int at[10];
int bt[10];
int ct[10];
int tat[10];
int wt[10];
float averageTAT=0;
float averageWT=0;
void swap(int id1,int id2){
int t=at[id1];
at[id1]=at[id2];
at[id2]=t;
t=bt[id1];
bt[id1]=bt[id2];
bt[id2]=t;
}

void sort(int n){
for (int i=0;i<n;i++){
	for (int j=0;j<n-i-1;j++){
		if (at[j]>at[j+1]){
			swap(j,j+1);
		}
	}
}
}

void printArray(int n){
printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
for (int i=0;i<n;i++){
	printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\nAverage Turnaraound Time = %f\nAverage WT = %f\n",averageTAT,averageWT);
}

void solve(int n){
int time=0;
int started=-1;
int current=0;
while(1){
	if (((time-started)==bt[current])&&(started!=-1)){
		started=-1;
		ct[current]=time;
		tat[current]=ct[current]-at[current];
		averageTAT+=tat[current];
		wt[current]=tat[current]-bt[current];
		averageWT+=wt[current];
		current++;
	}
	if ((started==-1)&&(time>=at[current])){
		started=time;
	}
	if (current==n){break;}
	time++;
}
averageTAT=averageTAT/n;
averageWT=averageWT/n;
}

int main(){
at[0]=1;at[1]=6;at[2]=4;at[3]=7;at[4]=6;at[5]=2;
bt[0]=2;bt[1]=5;bt[2]=4;bt[3]=1;bt[4]=5;bt[5]=1;
sort(4);
solve(4);
printArray(4);
}
