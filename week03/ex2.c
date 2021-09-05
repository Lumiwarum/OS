#include <stdio.h>
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

void bubbleSort(int arr[], int arrLen);
void swap(int *a, int *b);
void printArray(int arr[], int arrSize);
int main () {
	int arr[6]={4,-3,2,78,-12,7};
	printf("Initial array is:\n");
	printArray(arr,ARR_SIZE(arr));
	bubbleSort(arr,ARR_SIZE(arr));
	printf("Array after bubble sort:\n");
	printArray(arr,ARR_SIZE(arr));
}

void bubbleSort(int arr[],int arrLen){
for (int i=0;i<arrLen;i++){
	for (int j=0;j<arrLen-i-1;j++){
		if (arr[j]>arr[j+1]){
			swap(&arr[j],&arr[j+1]);
		}
	}
}
}

void swap(int* a,int* b){
int c;
c=*a;
*a=*b;
*b=c;
}

void printArray(int arr[], int arrSize){
for (int i=0;i<arrSize;i++){
printf("%d\n",arr[i]);
}
}

