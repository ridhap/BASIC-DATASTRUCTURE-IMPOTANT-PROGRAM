//dynamic stack implement
#include<stdio.h>
#include<stdlib.h>
void push(int *s, int *top, int *me)
{
	int ele,*p;
	printf("Enter the element:");
	scanf("%d",&ele);	
	if(*top==*me-1)
	{
		printf("Overflow.Memory reallocated");
		(*me)++;
		s=(int *)realloc(s,(*me)*sizeof(int));
	}
	(*top)++;
	p=s+(*top);
	*p=ele;	
}
void pop(int *s,int *top,int *me)
{
	int ele;
	if(*top==-1)
	{
		printf("Underflow");	
		return;
	}
	(*me)--;
	ele=*(s+(*top));
	(*top)--;
	s=(int *)realloc(s,(*me)*sizeof(int));
	printf("%d is popped",ele);
}
void display(int *st, int top)
{
	int i;
	if(top==-1)
		printf("No elements");
	else
		for(i=top;i>=0;i--)
			printf("%d\t",*(st+i));
	printf("\n");
}
int main()
{
	int *st,me=1,top=-1,ch;
	st=(int *)malloc(sizeof(int));
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\nelse Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push(st,&top,&me);
				break;
			case 2:pop(st,&top,&me);
				break;
			case 3:display(st,top);
				break;
			default:exit(0);
		}
	}
}
