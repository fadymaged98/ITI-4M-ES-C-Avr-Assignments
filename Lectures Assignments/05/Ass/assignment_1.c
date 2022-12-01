
#include <stdio.h>


int max(int *arr);
int min(int *arr);

void main()
{
	
	
	int arr[10];
	
	for(int i=0;i<10;i++)
	{
		printf("enter num %d :",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("the max value is :%d\n",max(arr));
	printf("the min value is :%d\n",min(arr));
}


int max(int *arr)
{
	int max=arr[0];
	for(int i=1;i<10;i++)
		if(max<arr[i])
			max=arr[i];
	return max;
}	
int min(int *arr)
{
	int min=arr[0];
	for(int i=1;i<10;i++)
		if(min>arr[i])
			min=arr[i];
	return min;
}