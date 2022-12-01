
#include <stdio.h>




void main()
{
	
	
	
	
	printf("Enter a num\n");
	int num=0;
	scanf("%d",&num);
	long long fac=1;
	do{
		fac*=num;
	num--;
	}while(num!=1);
	
	printf("the result is: %d",fac);
			
		

	
	
	
	
	
}
