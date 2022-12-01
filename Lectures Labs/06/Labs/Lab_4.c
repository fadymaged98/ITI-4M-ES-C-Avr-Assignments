#include <stdio.h>



void main()
{
	int arr[10];
	for(int i=0;i<10;i++)
	{
 	 printf("Please element number %d :",1+i);
	 scanf("%d",&arr[i]);
	}
	printf("---------------------------------------------------\n");
	
	int sum=0;
	int *ptr=arr;
	for(int i=0;i<10;i++)
	{
			sum+=*ptr;
			ptr++;
			
	}
			
	
		printf("the value  exist %d times",sum);
	
}