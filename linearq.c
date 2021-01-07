//Program to implement Linear Queue
#include<stdio.h>
#include<stdlib.h>
void insert(int q[],int *rear, int me)
{
	int ele;
	printf("Enter the element: ");
	scanf("%d", &ele);
	if(*rear==me-1)
	{
		printf("Queue is full\n");
		return;
	}
	(*rear)++;
	q[*rear]=ele;
}
void delete(int q[], int *front, int rear)
{
	int ele;
	if(*front>rear)
	{
	 	printf("Queue is empty\n");
		return;
	}
	ele=q[*front];
	(*front)++;
	printf("%d is deleted\n",ele);
}
void display(int q[],int front, int rear)
{
	int i;
	if(front>rear)
	{
		printf("Empty queue\n");
		return;
	}
	printf("The elements are: ");
	for(i=front;i<=rear;i++)
		printf("%d ",q[i]);
	printf("\n");
}
int main()
{
	int front=0,rear=-1,me,q[30],ch;
	printf("Enter max no of elements:");
	scanf("%d",&me);
	while(1)
	{
		printf("1.Insert 2.Delete 3.Display else Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(q,&rear,me);
				display(q,front,rear);
				break;
			case 2:delete(q,&front,rear);
				display(q,front,rear);
				break;
			case 3:display(q,front,rear);
				break;
			default:exit(0);
		}
	}
}
