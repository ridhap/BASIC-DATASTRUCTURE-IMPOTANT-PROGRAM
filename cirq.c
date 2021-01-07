//Program to implement circular queue
#include<stdio.h>
#include<stdlib.h>
void ins_cll(int q[], int *rear, int max, int *count)
{
	int ele;
	printf("Enter the element:");
	scanf("%d",&ele);
	if(*count==max)
	{
		printf("Queue is full\n");
		return;
	}
	(*rear)=(*rear+1)%max;
	q[*rear]=ele;
	(*count)++;
}
void del_cll(int q[], int *front, int max, int *count)
{
	int ele;
	if(*count==0)
	{
		printf("Empty queue\n");
		return;	
	}
	ele=q[*front];
	(*front)=(*front+1)%max;
	(*count)--;
	printf("%d is deleted\n",ele);
}
void display(int q[], int front, int count , int max)
{
	int i;
	if(count==0)
	{
		printf("Empty queue\n");
		return;
	}
	for(i=0;i<count;i++)
	{
		printf("%d ",q[front]);
		front=(front+1)%max;
	}
	printf("\n");
}
int main()
{
	int q[30], max, front=0, count=0,rear,ch;
	printf("Enter the max no of elements:");
	scanf("%d",&max);
	rear=max-1;
	while(1)
	{
		printf("1.Insert 2.Delete 3.Display else Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins_cll(q,&rear,max,&count);
				display(q,front, count,max);
				break;
			case 2:del_cll(q,&front,max,&count);
				display(q,front, count,max);
				break;
			case 3:display(q,front, count,max);
				break;
			default:exit(0);
		}
	}
}
