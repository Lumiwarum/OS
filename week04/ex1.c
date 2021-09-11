#include <stdio.h>

int main(){
int i=42;
int n=fork();
if (n == 0) {
	printf("Hello from child [%d - %d]\n",n,i);
} else {
	printf("Hello from parent[%d - %d]\n",n,i);
}
}
