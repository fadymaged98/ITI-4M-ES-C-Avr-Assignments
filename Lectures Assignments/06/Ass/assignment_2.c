
#include <stdio.h>



void main()
{
	int x=10,y=6,z=12;
	int*p=&x;
	int*q=&y;
	int*r=&z;
	printf("the value of x is : %d\n",x);
	printf("the value of y is : %d\n",y);
	printf("the value of z is : %d\n",z);
	printf("the value of p is : %p\n",p);
	printf("the value of q is : %p\n",q);
	printf("the value of r is : %p\n",r);	
	printf("the value of *p is : %d\n",*p);
	printf("the value of *q is : %d\n",*q);
	printf("the value of *r is : %d\n",*r);
	
	printf("swapping pointers \n"); 
	int * temp;
	temp=r;
	r=p;
	p=q;
	q=temp;
	
	printf("the value of x is : %d\n",x);
	printf("the value of y is : %d\n",y);
	printf("the value of z is : %d\n",z);
	printf("the value of p is : %p\n",p);
	printf("the value of q is : %p\n",q);
	printf("the value of r is : %p\n",r);	
	printf("the value of *p is : %d\n",*p);
	printf("the value of *q is : %d\n",*q);
	printf("the value of *r is : %d\n",*r);
	
	
	
	
}
