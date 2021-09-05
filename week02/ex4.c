#include <stdio.h>

void swap(int* a,int* b);

int main()
{
	int first=0,second=0;// initializing two integer variables
	char str[256]="";// initializing string to read two integers
	printf("Please enter two integers\n");
	fgets(str,256,stdin);
	sscanf(str,"%d%d",&first,&second);
	printf("Your two integers before swaping:\nFirst=%d Second=%d\n",first,second);
	swap (&first,&second);
	printf("Your two integers after swaping:\nFirst=%d Second=%d\n",first,second);
}

/*
* This function swap values of two integer variables
* As a parameters it takes two pointers to the integer variables
*/
void swap (int* a,int* b){
	int buffer=*a;
	*a= *b;
	*b= buffer;
}
