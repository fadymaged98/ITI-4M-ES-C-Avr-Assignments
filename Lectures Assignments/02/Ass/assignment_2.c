#include <stdio.h>


void main()
{
	printf("Plase enter Your ID \n");
	int id=0;
	int pass=0;
	scanf("%d",&id);
	switch(id)
	{
		case 1234:
			printf("enter password\n");
			scanf("%d",&pass);
			if(pass==123)
				printf("your username is ahmed");
			break;
		case 5678:
			printf("enter password\n");
			scanf("%d",&pass);
			if(pass==123)
				printf("your username is youssef");
			break;
		case 1145:
			printf("enter password\n");
			scanf("%d",&pass);
			if(pass==123)
				printf("your username is sara");
			break;
		default:
			printf("wrong ID\n");
	}
			
		

	
	
	
	
	
}
