#include <stdio.h>

int max(int x,int y);


void main()
{
	int x,y;
	printf("Please enter the first number  ");
	
	scanf("%d",&x);
	printf("Please enter the second number  ");
	
	scanf("%d",&y);
	
	printf("the max is %d ",max(x,y));
	
	
}

int max(int x,int y)
{
	if(x>y)
		return x;
	else 
		return y;
}
	