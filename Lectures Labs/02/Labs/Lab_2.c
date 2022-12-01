#include <stdio.h>



void main()
{
		
	printf("Plase enter the number of working hours\n");
	int x=0;
	scanf("%d",&x);
	int salary=50*x;
	if(x<40)
		salary*=0.9;
	printf("the salary is %d\n",salary);
	
	
}

	
	