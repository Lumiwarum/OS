#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
void* ptr;
	for (int i=0;i<10;i++){
		ptr=malloc(10485760);
		memset(ptr,0,10485760);
		sleep(1);
	}
}

/* 2nd task
Si and So fields are both at 0 value since there is enough free memory for allocating
Work pf the program can be found by looking at values of "free" field each seconds 
It changes, until the program is done
*/

/* 3rd task
There comes new process named ex2
fields Virt and Res are both increasing till the end of the process. As mentioned in the 2nd task we have enough
free memory,so we don't swap pages and therefore Virt and Res fields have the same (almost) value
*/
