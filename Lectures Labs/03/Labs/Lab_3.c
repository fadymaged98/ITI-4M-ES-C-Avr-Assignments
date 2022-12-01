#include <stdio.h>




void main()
{
	int arr[10];
	for(int i=0;i<10;i++)
	{
		printf("Please enter number %d ",i+1);
		scanf("%d",&arr[i]);
	}
		int sum=0;
		for(int i=0;i<10;i++)
	{
		sum+=arr[i];
	}
		printf("the sum  is  %d ",sum);
		printf("the avg  is  %d ",sum/10);
}
