//Program to implement DECK
#include<stdio.h>
#include<stdlib.h>
void ins_fro(int q[],int *front)
{
	int ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	if(*front==0)
	{
		printf("Element cannot be inserted\n");
		return;
	}
	(*front)--;
	q[*front]=ele;
}
void ins_rear(int q[], int *rear, int me)
{
	int ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	if(*rear==me-1)
	{
		printf("Element inserted at front\n");		
		return;
	}
	(*rear)++;
	q[*rear]=ele;
}
void del_rear(int q[], int *rear, int f)
{
	int ele;
	if(f>*rear)
	{
		printf("Empty queue\n");
		return;
	}
	ele=q[*rear];
	printf("%d is deleted\n",ele);
	(*rear)--;
}
void del_fro(int q[], int *front, int r)
{
	int ele;
	if(*front>r)
	{
		printf("Empty queue\n");
		return;
	}
	ele=q[*front];
	printf("%d is deleted\n", ele);
	(*front)++;
}
void display(int q[], int front, int rear)
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
	int q[30],me,front=0,rear=-1,ch;
	int *p;
	printf("Enter the number of elements:");
	scanf("%d",&me);
	while(1)
	{
		printf("1.Insert front  2.Insert rear 3.Delete rear 4.Delete front 5.Display else Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins_fro(q,&front);
				display(q,front,rear);				
				break;
			case 3:del_rear(q,&rear,front);
				display(q,front,rear);
				break;
			case 2:ins_rear(q,&rear,me);
				display(q,front,rear);
				break;
			case 4:del_fro(q,&front,rear);
				display(q,front,rear);
				break;
			case 5:display(q,front,rear);
				break;
			default:exit(0);
		}
	}

}
				

