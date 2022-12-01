#include <stdio.h>

#define set_bit(reg,bit_no) reg|=(1<<bit_no)
#define clear_bit(reg,bit_no) reg&=~(1<<bit_no)
#define toggle_bit(reg,bit_no) reg^=(1<<bit_no)

void main()
{
	char x=2;
	
	printf(" x is: %d\n",x);
	set_bet(x,0);
	printf(" set_bit is: %d\n",x);
	clear_bet(x,0);
	printf(" clear_bit is: %d\n",x);
	toggle_bet(x,0);
	printf(" toggle_bit is: %d\n",x);
}

