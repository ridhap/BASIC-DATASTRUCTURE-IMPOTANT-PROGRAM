//program to implement dll
#include<stdio.h>
#include<stdlib.h>
struct det
{
	int info;
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
	printf("Enter info:\n");
	scanf("%d",&(temp->info));
	return temp;
}
void dis(DET temp)
{
	printf("%d\n",temp->info);
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

void display(DET first)
{
	DET temp;
	if(first==NULL)
	{
		printf("No nodes\n");
		return;
	}
	temp=first;
	printf("The list is:\n");
	while(temp!=NULL)
	{		
		dis(temp);
		temp=temp->rlink;
	}
}
DET insert(DET first)
{
	int pos,info,i=1;
	DET temp,cur,prev;
	temp=getnode();
	printf("Enter position and info:");
	scanf("%d%d",&pos,&(temp->info));
	temp->llink=temp->rlink=NULL;
	cur=first;
	while(i!=pos && cur->rlink!=NULL)
	{
		i++;		
		cur=cur->rlink;
	}
	if(i==pos)
	{	
		prev=cur->llink;
		prev->rlink=temp;
		temp->rlink=cur;
		temp->llink=prev;
		cur->llink=temp;
	}	
	else
		printf("Invalid postion.\n");	
	return first;
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
int main()
{
	DET first=NULL;
	int ch;
	while(1)
	{
		printf("1.Ins_front	2.Ins_pos	3.Ins_rear	4.Display	else Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:first=ins_front(first);
				display(first);
				break;
			case 2:first=insert(first);
			case 4:display(first);
				break;
			case 3:first=ins_rear(first);
				display(first);
				break;			
			default:exit(0);
		}
	}
}
