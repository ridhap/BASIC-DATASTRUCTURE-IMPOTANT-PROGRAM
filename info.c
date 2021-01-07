//program to implement dll
#include<stdio.h>
#include<stdlib.h>
struct name
{
	char fname[20],lname[20];
};
struct det
{
	struct name N;
	struct det *rlink;
	struct det *llink;
};	
typedef struct det *DET;
DET getnode()
{
	DET temp;
	temp=(DET)malloc(sizeof(struct det));
	if(temp==NULL)
	{
		printf("Memory not allocated");
		exit(0);
	}
	return temp;
}
DET accept(DET temp)
{
	printf("Enter first name and last name:\n");
	scanf("%s",temp->N.fname);
	scanf("%s",temp->N.lname);
	return temp;
}
void dis(DET temp)
{
	printf("%s ",temp->N.fname);
	printf("%s\n",temp->N.lname);
}
DET ins_front(DET first)
{
	DET temp;
	temp=getnode();
	temp->llink=temp->rlink=NULL;
	temp=accept(temp);
	if(first==NULL)
		return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
DET ins_rear(DET first)
{
	DET temp,cur;
	temp=getnode();
	temp->llink=temp->rlink=NULL;
	temp=accept(temp);
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->rlink!=NULL)
		cur=cur->rlink;
	cur->rlink=temp;
	temp->llink=cur;
	return first;
}
DET del_front(DET first)
{
	DET temp;
	temp=getnode();
	temp->llink=temp->rlink=NULL;	
	if(first==NULL)
		return NULL;
	dis(first);	
	if(first->rlink==NULL)
	{
		dis(first);	
		return NULL;
	}	
	temp=first->rlink;
	temp->llink=temp;
	return temp;
}	
DET del_rear(DET first)
{
	DET temp,cur,prev;
	if(first==NULL)
	{
		printf("No nodes\n");
		return NULL;
	}
	cur=prev=first;
	while(cur!=NULL)
	{	
		prev=cur;
		cur=cur->rlink;
	}
	printf("The deleted details are:\n");
	dis(prev);
	prev=prev->llink;
	prev->rlink=NULL;
	return first;
}
void display(DET first)
{
	DET temp;
	if(first==NULL)
	{
		printf("No nodes\n");
		return;
	}
	temp=first;	
	printf("The details are:\n");
	while(temp!=NULL)
	{
		dis(temp);
		temp=temp->rlink;
	}
}
void count(DET first)
{
	int c=0;
	DET cur=first;
	while(cur!=NULL)
	{
		c++;
		cur=cur->rlink;
	}
	printf("No of details:%d\n",c);
}
int main()
{
	DET first=NULL;
	int ch;
	while(1)
	{
		printf("1.Ins_rear	2.Ins_front	3.Del_rear	4.Del_front	5.Display	6.Count	\nelse Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:first=ins_rear(first);
				display(first);
				break;
			case 2:first=ins_front(first);
				display(first);
				break;
			case 3:first=del_rear(first);
				display(first);
				break;
			case 4:first=del_front(first);
				display(first);
				break;
			case 5:	display(first);
				break;
			case 6:count(first);
				break;
			default:exit(0);
		}
	}
}
