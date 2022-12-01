
#include <stdio.h>



void main()
{
	int x=10;
 	 printf("the value of x is = %d\n",x);
	 int * ptr=&x;
	 *ptr=20;
	printf("the value of x is = %d\n",x);
	
	
}

