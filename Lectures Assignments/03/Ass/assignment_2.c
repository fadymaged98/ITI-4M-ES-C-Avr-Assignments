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
			if(pass==7788)
				printf("welcome Fady");
			else
			{
				for(int i=0;i<2;i++)
				{
					printf("Try again:");
					scanf("%d",&pass);
					if(pass==7788)
					{
						printf("welcome Fady");
						break;
					}
					else if(i==1)
						printf("no more tries");
				}
			}
			
			break;
		case 5678:
			printf("enter password\n");
			scanf("%d",&pass);
			if(pass==5566)
				printf("welcome Amr");
			else
			{
				for(int i=0;i<2;i++)
				{
					printf("Try again:");
					scanf("%d",&pass);
					if(pass==5566)
					{
						printf("welcome Fady");
						break;
					}
					else if(i==1)
						printf("no more tries");
				}	
			}
			break;
		case 9870:
			printf("enter password\n");
			scanf("%d",&pass);
			if(pass==1122)
				printf("welcome Wael");
			else
			{
				for(int i=0;i<2;i++)
				{
					printf("Try again:");
					scanf("%d",&pass);
					if(pass==1122)
					{
						printf("welcome Fady");
						break;
					}
					else if(i==1)
						printf("no more tries");
				}	
			}
			break;
		default:
			printf("wrong ID\n");
	}
	
}
