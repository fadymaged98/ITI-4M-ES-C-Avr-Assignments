#include <stdio.h>


void main()
{

	
	printf("Plase enter a number \n");
	int grade=0;
	scanf("%d",&grade);
	if((0<=grade)&&(grade<50))
		printf("your rating is failed\n");
	else if((50<=grade)&&(grade<65))
		printf("your rating is normal\n");
	else if((65<=grade)&&(grade<75))
		printf("your rating is good\n");
	else if((75<=grade)&&(grade<85))
		printf("your rating is very good\n");
	else
		printf("your rating is excellent\n");

}
