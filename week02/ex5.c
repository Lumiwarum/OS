#include <stdio.h>

void tree(int n,int* initial);
void rectangle(int n,int* initial);
void triangle(int n);
void halfTree(int n);

int main(int argc,char *argv[])
{
        if (argc != 3) {
                printf("Please  execute program with only 2 parameter\n");
		printf("First parameter is height of the figure, second is a type of the figure\n");
		printf("Possible types of figure:\n1-tree\n2-rectangle\n3-triangle\n4-half of tree\n");
	return 0;
        }
        int height = 0;
	int typeOfFigure=1;//default type is tree
        sscanf(argv[1],"%d",&height);
	sscanf(argv[2],"%d",&typeOfFigure);
	switch(typeOfFigure){
		case 1:
		tree(height,&height);
		break;
		case 2:
		rectangle(height,&height);
		break;
		case 3:
		triangle(height);
		break;
		case 4:
		halfTree(height);
		break;
		default:
		printf ("Wrong parameter for the type of figure\nPossible types are:\n");
		printf ("1-tree\n2-rectangle\n3-triangle\n4-half of tree\n");
		break;
	}
}

void tree(int n,int* initial){
        if (n>1) {
                tree(n-1,initial);
        }
        n=n*2-1;// calculate number of stars
        int freeSpaces=(*initial)*2-1 - n;// number of  free spaces
        for (int i=0;i<freeSpaces/2;i++){
                printf(" ");
        }
        for (int i=0;i<n;i++){
                printf("*");
        }
	printf("\n");
}

/*
* actually this function draws a square, but because of difference of space between two lines and two stars
* this function draws a figure that looks more like a rectangle
* parameter inital is for remembering width of the rectangle that equals to its initial height
*/
void rectangle(int n,int* initial){
	if(n>1) {
	rectangle(n-1,initial);
	}
	for (int i=0;i<*initial;i++){
		printf("*");
	}
	printf("\n");
}

/*
* This function draws a triangle, however the only parameter that it gets is height of the figure
* that is why this function draws almost a trinagle, in case if the initial height is even.
* With even height the triangle won't have the 3rd vertex.
*/
void triangle(int n){
	for (int i=0;i<n/2;i++){
		for (int j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	if (n%2==1){
		for (int i=0;i<n/2+1;i++){
			printf("*");
		}
		printf("\n");
	}
	for (int i=n/2;i>0;i--){
		for (int j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
}

void halfTree(int n){
	if(n>1){
		halfTree(n-1);
	}
	for (int i=0;i<n;i++){
		printf("*");
	}
	printf("\n");
}
