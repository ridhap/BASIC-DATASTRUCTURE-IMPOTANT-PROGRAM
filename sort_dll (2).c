//concatination of linkd list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node * llink;
	int info;
	struct node *rlink;
};
typedef struct node * NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	return temp;
}
NODE insert_rear(NODE first)
{ 
	NODE cur,temp=getnode();
	printf("enter information");
	scanf("%d",&(temp->info));
	temp->rlink=NULL;
	temp->llink=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->rlink!=NULL)
		cur=cur->rlink;
	cur->rlink=temp;
	temp->llink=cur;
	return first;
}
void concat(NODE first,NODE sec)
{
	NODE cur;
	cur=first;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	cur->rlink=sec;
	sec->llink=cur;
}
void sort(NODE first)
{
	int ele;
	NODE cur,temp,next,t;
	cur=first;
	while(cur->rlink!=NULL)
	{	
		t=cur;
		temp=first;
		next=temp->rlink;
		while(t->rlink!=NULL)
		{
			if((temp->info)>(next->info))
			{
				ele=temp->info;
				temp->info=next->info;
				next->info=ele;
			}
			t=t->rlink;
			temp=next;
			next=next->rlink;
		}
		cur=cur->rlink;
	}
}
void display(NODE first)
{
	NODE temp;
	temp=first;
	while(temp!=NULL)
	{
		printf("%d",temp->info);
		temp=temp->rlink;
	}
}
int main()
{
	int n1,n2;
	NODE first=NULL,sec=NULL;
	printf("enter the number of elem\n");
	scanf("%d",&n1);
	printf("enter first dll element\n");
	while(n1!=0)
	{
		first=insert_rear(first);
	}
	printf("enter the number of elem of on second dll\n");
	scanf("%d",&n1);
	printf("enter second dll element\n");
	while(n1!=0)
	{
		first=insert_rear(first);
	}
	concat(first,sec);
	sort(first);
	display(first);
}
