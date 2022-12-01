#include <stdio.h>
#include <stdlib.h>


void main()
{
	
	printf(" enter the number of numbers\n");
	int size;
	scanf("%d",&size);
	int*ptr;
	
	ptr=(int*)malloc(sizeof(int)*size);
	
	int temp;
	for(int i=0;i<size;i++)
	{
		printf(" enter the number %d\n",i+1);
		scanf("%d",&temp);
		ptr[i]=temp;
	}
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				int temp_2=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp_2;
			}
		}
	}
	printf("-------------------------------------------\n");
	
	for(int i=0;i<size;i++)
	{
		printf("  %d\n",ptr[i]);
		
	}
	
	
	
	
}

