#include <stdio.h>

#define SIZE 5

void mul(int *ptr_arr_1,int *ptr_arr_2,int* ptr_result,int size)
{
	for(int i=0;i<size;i++)
		ptr_result[i]=ptr_arr_1[i]*ptr_arr_2[i];
}

void main()
{
	int arr_1[SIZE]={1,3,4,5,6};
	int arr_2[SIZE]={4,6,8,10,9};
	int result[SIZE]={0};
	for(int i=0;i<SIZE;i++)
		printf("%d ",arr_1[i]);
	printf("\n");
	for(int i=0;i<SIZE;i++)
		printf("%d ",arr_2[i]);
	printf("\n");
	
	printf("---------------------------------------------------\n");
	
	mul(arr_1,arr_2,result,SIZE);
	for(int i=0;i<SIZE;i++)
		printf("%d ",result[i]);
	
	
}