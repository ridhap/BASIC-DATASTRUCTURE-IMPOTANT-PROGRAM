//program to implement sll using structure
#include<stdio.h>
#include<stdlib.h>
typedef struct det
{
	char USN[10],name[20],prog[4],phno[10];
	int sem;
}S;
struct node
{
	S det;
	struct node *link;
};
typedef struct node * NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not allocated");
		exit(0);
	}
	return temp;
}
NODE ins_front(NODE first)
{
	
	
	NODE temp;
	temp=getnode();
	temp->link=NULL;
	printf("Enter USN,Name,Program,Sem, Phno\n");
	scanf("%s",temp->det.USN);
	scanf("%s",temp->det.name);
	scanf("%s",temp->det.prog);
	scanf("%d",&(temp->det.sem));
	scanf("%s",temp->det.phno);
	if(first==NULL)
	{
		return temp;
	}
	temp->link=first;
	return temp;
}
NODE del_front(NODE first)
{
	if(first==NULL)
	{
		printf("Empty SLL\n");		
		return NULL;
	}
	printf("The deleted details:\n");
	printf("\n%s",first->det.USN);
	printf("\n%s",first->det.name);
	printf("\n%s",first->det.prog);
	printf("\n%d",first->det.sem);
	printf("\n%s",first->det.phno);
	printf("\n");
	if(first->link==NULL)
		return NULL;
	return (first->link);	
}
NODE ins_rear(NODE first)
{
	NODE temp,cur;
	temp=getnode();
	temp->link=NULL;
	printf("Enter USN,Name,Program,Sem, Phno\n");
	scanf("%s",temp->det.USN);
	scanf("%s",temp->det.name);
	scanf("%s",temp->det.prog);
	scanf("%d",&(temp->det.sem));
	scanf("%s",temp->det.phno);
	cur=first;
	if(first==NULL)
	{
		return temp;
	}
	printf("HI");
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return first;
}
NODE del_rear(NODE first)
{
	if(first==NULL)
	{
		printf("Empty SLL\n");
		return NULL;
	}
	NODE temp,cur,prev;	
	
	cur=prev=first;	
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("The deleted details:\n");
	printf("\n%s",first->det.USN);
	printf("\n%s",first->det.name);
	printf("\n%s",first->det.prog);
	printf("\n%d",first->det.sem);
	printf("\n%s",first->det.phno);
	prev->link=NULL;
	printf("\n");
	if(first->link==NULL)
		return NULL;
	return first;
}
void display(NODE first)
{
	NODE cur;
	if(first==NULL)
		printf("Empty Queue\n");
	else
	{
		cur=first;
		while(cur!=NULL)
		{
			printf("\n%s",cur->det.USN);
			printf("\n%s",cur->det.name);
			printf("\n%s",cur->det.prog);
			printf("\n%d",cur->det.sem);
			printf("\n%s",cur->det.phno);	
			cur=cur->link;
			printf("\n");
		}
	}
}
void count(NODE first)
{
	int c=0;
	NODE cur=first;
	while(cur!=NULL)
	{
		cur=cur->link;
		c++;
	}
	printf("No of students=%d",c);
}
int main()
{
	int ch=1;
	NODE first=NULL;
	while(1)
	{
		printf("1.Ins_front	2.Ins_rear	3.Del_front	4.Del_rear	5.Display	6.Count		else Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	first=ins_front(first);
				display(first);
				break;
			case 2:first=ins_rear(first);
				display(first);
				break;
			case 3:first=del_front(first);
				display(first);
				break;
			case 4:first=del_rear(first);
				display(first);
				break;
			case 5:display(first);
				break;
			case 6:count(first);
				break;	
			default:exit(0);	
		}
	}
}
		

