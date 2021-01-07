//Implement hll
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not allocated\n");
		exit(0);
	}
	return temp;
}
NODE ins_front(NODE head)
{
	NODE temp;
	printf("Enter the info:");
	temp=getnode();	
	scanf("%d",&(temp->info));
	temp->link=NULL;
	temp->link=head->link;
	head->link=temp;
	return head;
}
NODE ins_rear(NODE head)
{
	NODE temp,cur;
	printf("Enter the info:");
	temp=getnode();
	temp->link=NULL;
	scanf("%d",&(temp->info));
	cur=head;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return head;
}
NODE del_front(NODE head)
{
	NODE temp=getnode();	
	if(head->link==NULL)
	{
		printf("NO nodes\n");
		return NULL;
	}
	temp=head->link;
	printf("%d is deleted\n",temp->info);
	head->link=temp->link;
	return head;
}
NODE del_rear(NODE head)
{
	NODE temp,prev;
	temp=getnode();	
	if(head->link==NULL)
	{
		printf("NO nodes\n");
		return NULL;
	}
	temp=prev=head->link;
	if(temp==NULL)
	{
		printf("No nodes\n");
		return NULL;
	}
	while(temp->link!=NULL)
	{
		prev=temp;
		temp=temp->link;
	}
	printf("%d is deleted\n",temp->info);
	prev=NULL;
	return head;
}
void display(NODE head)
{
	NODE cur;
	if(head->link==NULL)
	{
		printf("No nodes\n");
		return;
	}
	printf("The elements are:\n");
	cur=head->link;
	while(cur!=NULL)
	{
		printf("%d ",cur->info);
		cur=cur->link;
	}
	printf("\n");
}
int main()
{
	NODE head;
	head=getnode();
	head->link=NULL;
	int ch;
	while(1)
	{
		printf("\n1.INS_front	2.INS_rear	3.DEL_front	4.DEL_rear	5.Display	else exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=ins_front(head);
				display(head);
				break;
			case 2:head=ins_rear(head);
				display(head);
				break;
			case 3:head=del_front(head);
				display(head);
				break;
			case 4:head=del_rear(head);
				display(head);
				break;
			case 5:	display(head);
				break;
			default:exit(0);
		}
	}
}
			
