#include <stdio.h>
#include <stdlib.h>

int main(){
char str[256];
while (1){
	fgets(str,255,stdin);
	system(str);
}
}
