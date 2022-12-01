#include <stdio.h>

typedef struct mystruct{
	double salary;
	double bouns;
	double deduction;
}emp;

void main()
{
	 emp ahmed={1000,500,200};
	 emp amr={2000,1000,0};
	 emp waleed={3000,350,200};
	printf(" ahmed salary equal = %lf\n",ahmed.salary);
	printf(" ahmed bouns equal = %lf\n",ahmed.bouns);
	printf(" ahmed deduction equal = %lf\n",ahmed.deduction);
	printf(" amr salary equal = %lf\n",amr.salary);
	printf(" amr bouns equal = %lf\n",amr.bouns);
	printf(" amr deduction equal = %lf\n",amr.deduction);
	printf(" waleed salary equal = %lf\n",waleed.salary);
	printf(" waleed bouns equal = %lf\n",waleed.bouns);
	printf(" waleed deduction equal = %lf\n",waleed.deduction);
	  double total;
	total=(ahmed.salary+ahmed.bouns-ahmed.deduction)+\
	(amr.salary+amr.bouns-amr.deduction)+\
	(waleed.salary+waleed.bouns-waleed.deduction);
	printf(" the total= %lf\n",total);
}

