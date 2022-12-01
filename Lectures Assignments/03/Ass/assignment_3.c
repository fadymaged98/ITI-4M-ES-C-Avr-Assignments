#include <stdio.h>

void main()
{
	printf("Enter the number of rows\n");
	int rows=0;
	scanf("%d",&rows);
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<rows-i;j++)
		{
			printf(" ");
		}
		for(int j=i+(i+1);j>0;j--)
		{
			printf("*");
		}
		
		printf("\n");
	
	}
	
	
	
}
