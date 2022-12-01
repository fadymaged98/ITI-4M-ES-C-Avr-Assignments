#include <stdio.h>

#define SIZE 10

void sort(int *ptr_arr,int size)
{
	for(int i=0;i<size;i++)
		for(int j=0;j<size-i;j++)
			if(ptr_arr[j]>ptr_arr[j+1])
			{
				int temp=ptr_arr[j];
				ptr_arr[j]=ptr_arr[j+1];
				ptr_arr[j+1]=temp;
			}
}

void main()
{
	int arr[SIZE]={66,77,9,2,4,5,30,44,55,2};
	
	for(int i=0;i<SIZE;i++)
		printf("%d ",arr[i]);
	printf("---------------------------------------------------\n");
	sort(arr,SIZE);
	printf("after sort\n");
	for(int i=0;i<SIZE;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	
	
	
	
	
}