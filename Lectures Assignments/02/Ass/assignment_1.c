#include <stdio.h>


void main()
{
	int arr[10];
	for(int i=0;i<10;i++)
	{
		printf("Please enter number %d ",i+1);
		scanf("%d",&arr[i]);
	}
		printf("Please enter number to find\n");
		int find;
		int flag=0;
		scanf("%d",&find);
		for(int i=0;i<10;i++)
	{
		if(arr[i]==find)
		{
			printf("it is found at index %d",i);
			flag=1;
			break;
		}
	}
		if(flag==0)
			printf("the number not found");
	
}
