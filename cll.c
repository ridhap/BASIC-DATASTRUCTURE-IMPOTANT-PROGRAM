//implement circular ll
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
NODE ins_front(NODE last)
{
	NODE temp=getnode();
	printf("Enter the info:");
	scanf("%d",&(temp->info));
	temp->link=temp;
	if(last==NULL)
		return temp;
	temp->link=last->link;
	last->link=temp;
	return last;
}
NODE ins_rear(NODE last)
{
	NODE temp,cur;
	printf("Enter the info:");
	scanf("%d",&(temp->info));
	temp->link=temp;
	if(last->link==last)
		return temp;
	temp->link=last->link;
	last->link=temp;
	return temp;
}
NODE del_front(NODE last)
{
	NODE temp,first;
	if(last==NULL)
	{
		printf("No nodes");
		return NULL;
	}
	if(last->link==last)
	{
		printf("%d\n",last->info);
		return NULL;
	}
	temp=last->link;
	printf("%d",temp->info);
	last->link=temp->link;
	first=last->link;	
	return last;
}
NODE del_rear(NODE last)
{
	NODE cur,prev;
	if(last==NULL)
	{
		printf("No node\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("%d",last->info);
		return NULL;
	}
	cur=last->link;
	while(cur->link!=last)
	{
		cur=cur->link;
	}
	printf("%d is deleted\n",last->info);
	cur->link=last->link;
	return cur;
}
void display(NODE last)
{
	NODE cur;
	if(last==NULL)
	{
		printf("No Node\n");
		return;
	}
	cur=last->link;
	printf("The elements are:\n");
	do
	{
		printf("%d ",cur->info);
		cur=cur->link;
	}while(cur!=last->link);
}
int main()
{
	NODE last=NULL;
	int ch;
	while(1)
	{
		printf("\n1.INS_front	2.INS_rear	3.DEL_front	4.DEL_rear	5.Display	else exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:last=ins_front(last);
				display(last);
				break;
			case 2:last=ins_rear(last);
				display(last);
				break;
			case 3:last=del_front(last);
				display(last);
				break;
			case 4:last=del_rear(last);
				display(last);
				break;
			case 5:	display(last);
				break;
			default:exit(0);
		}
	}
}
			
