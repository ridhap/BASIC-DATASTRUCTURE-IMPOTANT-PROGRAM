#include<stdlib.h>
#include<stdio.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("no memory available\n");
		exit(0);
	}
	return temp;
}
void display(NODE first)
{
	int i=1;
	if(first==NULL)
	{
		printf("SLL is empty\n");
		return;
	}
	while(first!=NULL)
	{
		
		printf("info in node %d is %d\n",i,first->info);
		first=first->link;
		i++;
	}
}
NODE insert(NODE first)
{
	NODE temp=getnode();
	temp->link=NULL;
	printf("enter info\n");
	scanf("%d",&temp->info);
	if(first==NULL)
	return temp;
	temp->link=first;
	return temp;
}
NODE delete(NODE first)
{	
	NODE cur=first,prev=NULL;
	if(first==NULL)
	{
		printf("SLL is empty\n");
		return first;
	}
	else if(first->link==NULL)
	{
		printf("deleted info is %d",first->info);
		free(first);
		return NULL;
	}
	else
	{
		while(cur->link!=NULL)
		{
			prev=cur;
			cur=cur->link;
		}
		printf("deleted info is %d",cur->info);
		prev->link=NULL;
		free(cur);
		return first;
	}		
}
NODE push(NODE first)
{
	NODE temp=getnode();
	temp->link=NULL;
	printf("enter info\n");
	scanf("%d",&temp->info);
	if(first==NULL)
	return temp;
	temp->link=first;
	display(first);
	return temp;
}

NODE pop(NODE first)
{
	NODE cur=first;
	if(first==NULL)
	{
		printf("SLL is empty\n");
		return first;
	}
	else if(first->link==NULL)
	{
		printf("deleted info is %d",first->info);
		free(first);
		display(first);
		return NULL;
	}
	else
	{
		first=cur->link;
		printf("deleted info is %d",cur->info);
		free(cur);
		return first;
	}
}
int main()
{
	NODE first=NULL;
	int ch,ch2;
	while(1)
	{
		printf("enter choice\n1-stack implementation of sll\n2-queue implementation of sll\n");
		scanf("%d",&ch2);
		if(ch2==2)
		{
			while(1)
			{
			
				printf("enter your choice\n1-insert\n2-delete\n3-display\nany other digit to exit");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1:first=insert(first);
						break;
	        			case 2:first=delete(first);
						break;
					case 3:display(first);
						break;
					default:exit(0);
				}
			}
		}
		else if(ch2==1)
		{
			while(1)
			{
				printf("enter your choice\n1-push\n2-pop\n3-display\nany other digit to exit\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1:first=push(first);
						break;
					case 2:first=pop(first);
						break;
					case 3:display(first);
						break;
					default:exit(0);
				}	
			}
		}	
		else
		exit(0);
	}
}		
														
	
		
		

	
				
