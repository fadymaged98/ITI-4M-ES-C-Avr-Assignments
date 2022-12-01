#include <stdio.h>




void main()
{
	int arr[3];
	for(int i=0;i<3;i++)
	{
		printf("Please enter number %d ",i+1);
		scanf("%d",&arr[i]);
	}
		int max=arr[0];
		for(int i=1;i<3;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			
		}
	}
		printf("the max number is  %d ",max);
}
