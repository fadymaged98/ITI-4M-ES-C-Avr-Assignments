#include <stdio.h>

typedef struct s{
	char x;
	short y;
	char z;
	short a;
}str_1;

typedef struct m{
	char z;
	char x;
	short y;
	short a;
}str_2;

void main()
{
	
	printf(" the size of str_1 equal = %d\n",sizeof(str_1));
	printf(" the size of str_2 equal = %d\n",sizeof(str_2));
	
}

