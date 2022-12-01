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
	for(int i=9;i>=0;i--)
	{
 	 printf("Please element number %d is: %d\n",1+i,arr[i]);
	}
	
	
}

