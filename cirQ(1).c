#include<stdio.h>
#include<stdlib.h>
#define ME 3
void insert(int q[ME],int *rear,int *count)
{
	int elem;
	printf("enter element\n");
	scanf("%d",&elem);
	if(*count==ME)
	{
		printf("queue full\n");
		return;
	}
	(*rear)=((*rear)+1)%ME;
	q[*rear]=elem;
	(*count)++;
	display(q,*front,*count);
}		
void delete(int q[ME],int *front,int *count)
{
	int elem;
	if(*count==0)
	{
		printf("queue is empty\n");
		return;
	}
	elem=q[*front];
	(*front)=((*front)+1)%ME;
	(*count)--;
	printf("deleted element is %d",elem);
	display(q,*front,*count);
}
void display(int q[ME],int front,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		printf("%d ",q[front]);
		front=(front+1)%ME;
	}
	printf("\n");	
}
int main()
{
	int q[ME],ch,me=30,count=0,rear=ME-1,front=0;
	while(1)
	{
		printf("enter your choice\n");
		printf("1-insert 2-delete 3-display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(q,&rear,&count);
				break;
			case 2:	delete(q,&front,&count);
				break;
			case 3: display(q,front,count);
				break;
			default:exit(0);
		}
	}
}			
					
