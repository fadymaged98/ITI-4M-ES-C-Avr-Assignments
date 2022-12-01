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
	
	int find,count=0;
	printf("Please  number \n ");
	 scanf("%d",&find);
	
	for(int i=0;i<10-1;i++)
	{
		
		if(arr[i]==find)
		{
			count++;
		}
		
	}
			
	if(count==0)
		printf("the value doesn't exist");
	else
		printf("the value  exist %d times",count);
	
}
