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
	
	for(int i=0;i<10-1;i++)
	{
		for(int j=0;j<10-1-i;j++)
		{
		if(arr[j]>arr[j+1])
		{
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		}
	}
			
	
	
	for(int i=0;i<10;i++)
	{
 	 printf(" element number %d is: %d\n",1+i,arr[i]);
	}
	
	
}
