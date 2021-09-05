#include <stdio.h>
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

void quickSort(int arr[], int lo, int hi);
int partition(int arr[], int lo, int hi);
void swap(int* fir, int* sec);
void printArray(int arr[],int arrSize);

int main(){
int arr[5]={3,1,5,-1,4};
int arr2[10]={-4,10,2,4,5,-2,11,7,-10,1};
printf("Initial array:\n");
printArray(arr,ARR_SIZE(arr));
quickSort(arr,0,4);
printf("Array after quickSort:\n");
printArray(arr,ARR_SIZE(arr));
printf("Initial second array:\n");
printArray(arr2,ARR_SIZE(arr2));
quickSort(arr2,0,ARR_SIZE(arr2)-1);
printf("Second array after quickSort:\n");
printArray(arr2,ARR_SIZE(arr2));
}

void quickSort(int arr[], int lo, int hi){
if ((lo>=0)&&(hi>=0)){
	if(lo<hi){
		int p=partition(arr,lo,hi);
		quickSort(arr,lo,p);
		quickSort(arr,p+1,hi);
	}
}
}

int partition(int arr[], int lo, int hi){
int pivot=arr[(hi-lo)/2+lo];
int i=lo;
int j=hi;
while(1>0){
	while((arr[i]<pivot)&&(i<=j)){
		i++;
	}
	while((arr[j]>pivot)&&(j>i)){
		j--;
	}
	if (i>=j){
		return j;
	}
	swap(&arr[i],&arr[j]);
}
}

void swap(int* fir, int* sec){
int buffer=*fir;
*fir=*sec;
*sec=buffer;
}

void printArray(int arr[],int arrSize){
for (int i=0;i<arrSize;i++){
printf("%d\n",arr[i]);
}
}
