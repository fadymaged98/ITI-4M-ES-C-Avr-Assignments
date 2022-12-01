
#include <stdio.h>

long long fact(int x);


void main()
{
	
	
	
	
	printf("Enter a number \n");
	int num=0;
	scanf("%d",&num);
	printf("the result is = %d",fact(num));
	
}


long long faq(int x)
{
	if(x==1)
		return x;
	else
		return (x*fact(x-1));
}