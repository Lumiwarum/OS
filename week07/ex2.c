#include <stdio.h>
#include <stdlib.h>

int main(){
printf("Please enter N - size of the array\n");
int n;
scanf("%d",&n);
int *arr= malloc(n*sizeof(int));
for (int i=0;i<n;i++){
	arr[i]=i;
}
printf("Your array is:\n");
for (int i=0;i<n;i++){
	printf("%d ",arr[i]);
}
printf("\n");
free(arr);
}
