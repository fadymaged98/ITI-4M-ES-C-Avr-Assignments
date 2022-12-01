#include <stdio.h>

typedef struct mystruct{
	int math;
	int lan;
	int phy;
	int chem;
}students;

void main()
{
	 students class[10]={{50,88,77,22},
						{66,74,95,74},
						{78,96,25,41},
						{56,22,14,78},
						{77,99,66,22},
						{4,88,66,25},
						{77,44,25,63},
						{89,52,61,63},
						{98,97,95,96},
						{2,5,8,9}
						};
	printf(" enter the student ID\n");
	int id;
	scanf("%d",&id);
	if(!((id>0)&&(id<11)))
		do{
			printf(" wrong id try again\n");
			scanf("%d",&id);
		}while(!((id>0)&&(id<11)));
		
	
	printf(" math grade is: %d\n",class[id-1].math);
	printf(" lan grade is: %d\n",class[id-1].lan);
	printf(" phy grade is: %d\n",class[id-1].phy);
	printf(" chem grade is: %d\n",class[id-1].chem);

}

