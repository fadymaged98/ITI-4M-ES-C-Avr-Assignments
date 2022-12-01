#include <stdio.h>



void main()
{
	int arr[10];
	for(int i=0;i<10;i++)
	{
 	 printf("Please element number %d :",1+i);
	 scanf("%d",&arr[i]);
	}
	int sum=0;
	for(int i=0;i<10;i++)
	{
		sum+=arr[i];
 	 
	}
	printf("the sum is: %d\n",sum);
	printf("the avg is: %d\n",sum/10);
	
}

