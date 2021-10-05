#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void* ptr,size_t size){
	// checking if the size is 0
	if (size==0) {free(ptr); return NULL;}
	void* new_ptr= malloc(size);
	//cheking if there is no initial ptr to reallocate
	if (ptr==NULL) {return new_ptr;}
	memcpy(new_ptr,ptr,size);
	free(ptr);
	return new_ptr;
}

int main(){
	int* arr= my_realloc(NULL,5*sizeof(int));
	for (int i=0;i<5;i++){
		arr[i]=i;
		printf("%d ",arr[i]);
	}
	printf("\n");
	arr= my_realloc(arr,10*sizeof(int));
	for (int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	my_realloc(arr,0);
}
