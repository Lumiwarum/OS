#include <stdio.h>
#include <string.h>

int main()
{
	char str[256] = "";//string as an array of characters
	printf ("Provide a string please: \n");
	fgets (str, 256, stdin);
	int len = strlen(str);
	char c;
	for (int i=0;i<(len-1)/2;i++){
		c=str[i];
		str[i]=str[len-i-2];
		str[len-i-2]=c;
	}
	printf("Your string reversed is: \n%s",str);
}


