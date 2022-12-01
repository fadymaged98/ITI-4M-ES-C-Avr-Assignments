#include <stdio.h>

void swap(void);

int x,y;
void main()
{
	
	printf("Please enter the first number  ");
	
	scanf("%d",&x);
	printf("Please enter the second number  ");
	
	scanf("%d",&y);
	swap();
	printf(" first number after swap %d \n ",x);
	printf(" second numberafter swap %d  \n",y);
	
}

void swap(void)
{
	x=x^y;
	y=y^x;
	x=x^y;
}