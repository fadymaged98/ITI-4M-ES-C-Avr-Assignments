#include <stdio.h>

void sum(int*x,int*y,int *result)
{
	*result= *x+*y;
}
void sub(int*x,int*y,int *result)
{
	*result= *x-*y;
}
void main()
{
	int x;
 	 printf("enter the value of x \n");
	 scanf("%d",&x);
	 
	 int y;
	printf("enter the value of y \n");
	scanf("%d",&y);
	int sum_result, sub_result;
	sum(&x,&y,&sum_result);
	sub(&x,&y,&sub_result);
	printf("the sum is: %d\n",sum_result);
	printf("the sub is: %d\n",sub_result);
	
	
}