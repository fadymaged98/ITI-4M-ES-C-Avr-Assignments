#include <stdio.h>

void main()
{
	
	int no_pass=0;
	int no_fail=0;
	int sum=0;
	int class_1[10]={55,99,88,63,33,44,55,99,11,63};
	int class_2[10]={95,75,38,34,99,45,35,74,12,58};
	int class_3[10]={8,9,3,44,55,88,77,41,88,66};
	
	
	int max=class_1[0];
	int min=class_1[0];
	for(int i=0;i<10;i++)
	{
		sum+=class_1[i];
		if(max<class_1[i])
			max=class_1[i];
		if(min>class_1[i])
			min=class_1[i];
		if(class_1[i]>=50)
			no_pass++;
		else
			no_fail++;
	}
	for(int i=0;i<10;i++)
	{
		sum+=class_2[i];
		if(max<class_2[i])
			max=class_2[i];
		if(min>class_2[i])
			min=class_2[i];
		if(class_2[i]>=50)
			no_pass++;
		else
			no_fail++;
	}
	for(int i=0;i<10;i++)
	{
		sum+=class_3[i];
		if(max<class_3[i])
			max=class_3[i];
		if(min>class_3[i])
			min=class_3[i];
		if(class_3[i]>=50)
			no_pass++;
		else
			no_fail++;
	}	
	printf("the number of passed is: %d\n",no_pass);
	printf("the number of fail is: %d\n",no_fail);		
	printf("the max Grade is: %d\n",max);
	printf("the min Grade is: %d\n",min);	
	printf("the avg Grade is: %d\n",sum/30);
	
}

