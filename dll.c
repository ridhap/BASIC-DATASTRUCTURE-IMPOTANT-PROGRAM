//program to implement dll
#include<stdio.h>
#include<stdlib.h>
struct det
{
	char SSN[8],name[20],dept[20],desig[4],phno[10];
	int sal;
	struct det *rlink;
	struct det *llink;
};
typedef struct det *EMP;
EMP getnode()
{
	EMP temp;
	temp=(EMP)malloc(sizeof(struct det));
	if(temp==NULL)
	{
		printf("Memory not allocated");
		exit(0);
	}
	return temp;
}
EMP accept(EMP temp)
{
	printf("Enter USN,name,Dept,Designation,Sal,phno:\n");
	scanf("%s",temp->SSN);
	scanf("%s",temp->name);
	scanf("%s",temp->dept);
	scanf("%s",temp->desig);
	scanf("%d",&(temp->sal));
	scanf("%s",temp->phno);
	return temp;
}
void dis(EMP temp)
{
	printf("\nSSN:%s",temp->SSN);
	printf("\nName:%s",temp->name);
	printf("\nDepartment:%s",temp->dept);
	printf("\nDesignation:%s",temp->desig);
	printf("\nSalary:%d",temp->sal);
	printf("\nPh no:%s\n",temp->phno);
}
EMP ins_front(EMP first)
{
	EMP temp;
	temp=getnode();
	temp->llink=temp->rlink=NULL;
	temp=accept(temp);
	if(first==NULL)
		return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
EMP ins_rear(EMP first)
{
	EMP temp,cur;
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
EMP del_front(EMP first)
{
	EMP temp;
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
EMP del_rear(EMP first)
{
	EMP temp,cur,prev;
	if(first==NULL)
	{
		printf("No nodes\n");
		return NULL;
	}
	cur=prev=first;
	while(cur->rlink!=NULL)
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
void display(EMP first)
{
	EMP temp;
	if(first==NULL)
	{
		printf("No nodes\n");
		return;
	}
	temp=first;
	while(temp!=NULL)
	{
		printf("The details are:\n");
		dis(temp);
		temp=temp->rlink;
	}
}
void count(EMP first)
{
	int c=0;
	EMP cur=first;
	while(cur!=NULL)
	{
		c++;
		cur=cur->rlink;
	}
	printf("No of details:%d\n",c);
}
int main()
{
	EMP first=NULL;
	int ch;
	while(1)
	{
		printf("1.Ins_rear	2.Ins_front	3.Del_rear	4.Del_front	5.Display	6.Count	\nelse Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:first=ins_front(first);
				display(first);
				break;
			case 2:first=ins_rear(first);
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
