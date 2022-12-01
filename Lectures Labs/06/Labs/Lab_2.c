
#include <stdio.h>

int sum(int*x,int*y)
{
	return *x+*y;
}

void main()
{
	int x;
 	 printf("enter the value of x \n");
	 scanf("%d",&x);
	 
	 int y;
	printf("enter the value of y \n");
	scanf("%d",&y);
	printf("the sum is: %d\n",sum(&x,&y));
	
	
}

