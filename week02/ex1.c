#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int intToMax = INT_MAX;
	float floatToMax = FLT_MAX;
	double doubleToMax = DBL_MAX;
	printf("The size of integer variable is: %ld \n",sizeof(intToMax));
	printf("The value of integer variable is: %d \n",intToMax);
	printf("The size of float variable is: %ld \n",sizeof(floatToMax));
	printf("The value of float variable is: %f \n",floatToMax);
	printf("The size of double variable is: %ld \n",sizeof(doubleToMax));
	printf("The value of double variable is: %f \n",doubleToMax);
}
