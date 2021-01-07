#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 20
struct node
{
	char c;
	struct node *llink,*rlink;
};
typedef struct node *NODE;
int f(char ele);
int g(char ele);
void convert(char infix[30],char postfix[30]);
void push(char s[20],int *top,char symbol);
char pop(char s[20],int *top);
NODE getnode();
NODE bst_exp(char postfix[max]);
void preorder(NODE root);
NODE getnode();

NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		exit(0);
	
	}
	return temp;
}

int f(char ele)
{
	switch(ele)
	{
		case '+':
		case '-':return 2;
		case '*':
		case '/':
		case '%':return 4;
		case '(':return 0;
		case '^':
		case '$':return 5;
		case '#':return -1;
		default:return 8;
	}
}


int g(char ele)
{
	switch(ele)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':
		case '%':return 3;
		case '(':return 9;
		case '^':
		case '$':return 6;
		case ')':return 0;
		default:return 7;
	}
}



void convert(char infix[30],char postfix[30])
{
	int top=-1,pindex=0,i;
	char symbol,pop_ele;
	char s[20];
	//push # into the stack
	push(s,&top,'#');
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(f(s[top])>g(symbol))
		{
			//pop the elements
			postfix[pindex]=pop(s,&top);
			pindex++;
		}
		if(f(s[top])!=g(symbol))
		{
			//push the elements
			push(s,&top,symbol);
		}
		else
		{
			// pop ')'
			pop(s,&top);
		}
	}
		pop_ele=pop(s,&top);
		while(pop_ele!='#')
		{
			postfix[pindex]=pop_ele;
			pindex++;
			pop_ele=pop(s,&top);
		}
	
	postfix[pindex]='\0';	
	printf("Postfix Expression is \t");
	puts(postfix);
}


void push(char s[20],int *top,char symbol)
{
	//check overflow condition
	if((*top)==max-1)
	{
		printf("overflow condition\n");
		return;
	}
	(*top)++;
	s[*top]=symbol;
}

char pop(char s[20],int *top)
{
	int ele;
	//check underflow condition
	if((*top)==-1)
	{
		printf("Underflow condition\n");
		return -1;
	}
	ele=s[*top];
	(*top)--;
	return ele;
}

NODE bst_exp(char postfix[max])
{
	NODE s[max],temp,pop1,pop2;
	int top=-1,i=0;
	char symbol;
	while(postfix[i]!='\0')
	{
		symbol=postfix[i];
		if(isalpha(symbol))
		{
			temp=getnode();
			temp->llink=temp->rlink=NULL;
			temp->c=symbol;
			s[++top]=temp;
		}
		else
		{
			temp=getnode();
			pop1=s[top--];
			pop2=s[top--];
			temp->llink=pop2;
			temp->rlink=pop1;
			temp->c=symbol;
			s[++top]=temp;
		}
		i++;
	}
	return s[top--];
}
void preorder(NODE root)
{
	//empty BST
	if(root==NULL)
	{
		return;
	}
	printf("%c\n",root->c);
	preorder(root->llink);
	preorder(root->rlink);
	
}

int main()
{
	int i,top=-1,s[20];
	NODE root=NULL;
	char infix[max],postfix[max];
	
	int op1,op2,res;
	//accept the infix expression
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	convert(infix,postfix);
	
	root=bst_exp(postfix);
	preorder(root);
	
}






