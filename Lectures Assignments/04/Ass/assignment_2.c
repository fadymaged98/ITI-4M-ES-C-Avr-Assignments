
#include <stdio.h>

int add(int x,int y);
int sub(int x,int y);
int mul(int x,int y);
int div(int x,int y);
int AND(int x,int y);
int OR(int x,int y);
int XOR(int x,int y);
int NOT(int x);
int rem(int x,int y);
int inc(int x);
int dec(int x);

void main()
{
	int x=0;
	int y=0;
	
	printf("To Add press 1\n");
	printf("To sub press 2\n");
	printf("To Mul press 2\n");
	printf("To Div press 4\n");
	printf("To And press 5\n");
	printf("To Or press 6\n");
	printf("To Not press 7\n");
	printf("To Xor press 8\n");
	printf("To Rem press 9\n");
	printf("To Inc press 10\n");
	printf("To Dec press 11\n");
	
	int operation=0;
	scanf("%d",&operation);
	switch(operation)
	{
		case 1:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d + %d = %d",x,y,add(x,y));
			break;
		case 2:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d - %d = %d",x,y,sub(x,y));
			break;
		case 3:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d * %d = %d",x,y,mul(x,y));
			break;
		case 4:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d / %d = %d",x,y,sub(x,y));
			break;
		case 5:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d & %d = %d",x,y,AND(x,y));
			break;
		case 6:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d | %d = %d",x,y,OR(x,y));
			break;
		case 7:
			printf("enter a number:");
			scanf("%d",&x);
			printf(" !%d  = %d",x,NOT(x));
			break;
		case 8:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d ^ %d = %d",x,y,XOR(x,y));
			break;
		case 9:
			printf("enter the first number:");
			scanf("%d",&x);
			printf("enter the second number:");
			scanf("%d",&y);
			printf(" %d % %d = %d",x,y,rem(x,y));
			break;
		case 10:
			printf("enter a number:");
			scanf("%d",&x);
			printf(" %d+1  = %d",x,inc(x));
			break;
		case 11:
			printf("enter a number:");
			scanf("%d",&x);
			printf(" %d-1  = %d",x,dec(x));
			break;
		default:
			printf("Invalid input");
	}
		
}


int add(int x,int y)
{
	
	return x+y;
}	
int sub(int x,int y)
{
	
	return x-y;
}	
int mul(int x,int y)
{
	
	return x*y;
}	
int div(int x,int y)
{
	return x/y;
}	
	
int AND(int x,int y)
{
	return x&y;
}	
int OR(int x,int y)
{
	return x|y;
}	
int XOR(int x,int y)
{
	return x^y;
}	
int NOT(int x)
{
	return !x;
}	
int rem(int x,int y)
{
	return x%y;
}	
int inc(int x)
{
	return x+1;
}	
int dec(int x)
{
	return x-1;
}	