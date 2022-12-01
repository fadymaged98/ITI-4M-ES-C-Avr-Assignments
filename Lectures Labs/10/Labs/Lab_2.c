
#include <stdio.h>
#include <stdlib.h>




struct node{
	int data;
	struct node *next;
};
	
struct node* head =NULL;


void add_node(int x)
{
	struct node* ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->next=head;
	head=ptr;
}

void print_list(void)
{
	if(head==NULL)
	{
		printf("the list is empty\n");
		return;
	}
	
	struct node * currrent=head;
	while(currrent!=NULL)
	{
		printf("%d=>\n",currrent->data);
		currrent=currrent->next;
	}
}



void main()
{
	while(1)
	{
	printf(" TO add node press 0 \n");
	printf(" TO print list press 1 \n");
	printf(" TO exit press 2 \n");
	int order,data;
	scanf("%d",&order);
	printf("---------------------------------------------------------\n");
	switch(order)
	{
		case 0:
			printf("enter node data\n");
			scanf("%d",&data);
			add_node(data);
			break;
		case 1 :
			print_list();
			break;
		case 2: 
			printf("bye bye\n");
			return;
		default :
			printf("incorrect entry\n");
	}
	printf("---------------------------------------------------------\n");
	}		
}

