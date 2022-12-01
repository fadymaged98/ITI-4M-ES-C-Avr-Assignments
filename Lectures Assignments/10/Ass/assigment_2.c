
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

void add_node_at_pos(int x,int pos)
{
	struct node* check=head;
	int len=0;
	while(check!=NULL)
	{
		len++;
		check=check->next;
	}
	if(len<pos)
	{
		printf("wrong position try again\n");
		return;
	}
	
	struct node* new=(struct node *)malloc(sizeof(struct node));
	
	new->data=x;
	struct node* current=head;
	struct node* prev=head;
	for(int i=0;i<pos-1;i++)
	{
		prev=current;
		current=current->next;
	}
	
	prev->next=new;
	new->next=current;
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

void delete_node(int x)
{
	if(head==NULL)
	{
		printf("the list is empty\n");
		return;
	}
	
	struct node * currrent=head;
	struct node * previus=head;
	while(currrent!=NULL)
	{
		
		if(currrent->data==x)
		{
			previus->next=currrent->next;
			free(currrent);
			currrent=previus->next;
			continue;
		}
			
		previus=currrent;	
		currrent=currrent->next;
	}
}

void main()
{
	while(1)
	{
	printf(" TO add node press 0 \n");
	printf(" TO print list press 1 \n");
	printf(" TO delete node press 2 \n");
	printf(" TO add node at pos press 3 \n");
	printf(" TO exit press 4 \n");
	int order,data,pos;
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
			printf("enter node data\n");
			scanf("%d",&data);
			delete_node(data);
			break;
		case 3:
			printf("enter node data\n");
			scanf("%d",&data);
			printf("enter node pos\n");
			scanf("%d",&pos);
			add_node_at_pos(data,pos);
			break;	
		case 4: 
			printf("bye bye\n");
			return;
		default :
			printf("incorrect entry\n");
	}
	printf("---------------------------------------------------------\n");
	}		
}

