// program to implement expression tree
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	struct node * llink;
	char ch;
	struct node * rlink;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("No memeory found\n");
		exit(0);
	}
	return temp;
}
//void push(struct node[],int *,NODE);
//NODE pop(struct node[], int *);
void con_to_postfix(char[]);
NODE create_exp_tree(char []);
int F(char);
int G(char);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
int main()
{
	char infix[20];
	NODE root;
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	con_to_postfix(infix);
	//root=create_exp_tree(infix);
}
//stack precedence for postfix conversion
int F(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 2;
		case '*':
		case '/':
		case '%':return 4;
		case '^':
		case '$':return 5;
		case '(':return 0;
		case '#':return -1;
		default:return 8;
	}
}
//input precedence for postfix conversion
int G(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':
		case '%':return 3;
		case '^':
		case '$':return 6;
		case '(':return 9;
		case ')':return 0;
		default:return 7;
	}
}
//function to convert infix to postfix
void con_to_postfix(char infix[])
{
	char s[20],postfix[20],pop_ele,symbol;
	NODE root;
	int pindex=0,i,top=-1;
	//push(s,&top,'#');
	top++;
	s[top]='#';
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(F(s[top])>G(symbol))
		{
			postfix[pindex]=s[top];   //pop(s,&top);
			top--;
			pindex++;
			
		}
		if(F(s[top])!=G(symbol))
		{
			//push(s,&top,symbol);
			top++;
			s[top]=symbol;
		}
		else
		{
			//pop(s,&top);
			top--;
		}
	}
	pop_ele=s[top--];    //pop(s,&top);
	while(pop_ele !='#')
	{
		postfix[pindex]=pop_ele;
		pindex++;
		pop_ele=s[top];    //pop(s,&top);
		top--;
	}
	
	postfix[pindex]='\0';
	//printf("Postfix expression is: ");
	puts(postfix);
	root=create_exp_tree(postfix);
	printf("Expression tree: ");
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	
}
//function to create expression tree
NODE create_exp_tree(char postfix[])
{
	int top=-1,i;
	NODE st[20],temp,root;
	char symbol;
	
	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		temp=getnode();
		temp->llink=temp->rlink=NULL;
		temp->ch=symbol;
		if(isalpha(symbol))
		{
			top++;
			st[top]=temp;
		}
		else
		{
			temp->rlink=st[top--];    //pop(st,&top);
			temp->llink=st[top--];   //pop(st,&top);
			//push(at,&top,temp);
			top++;
			st[top]=temp;
		}
	}
	return st[top--];   //pop(st,&top);
}
//function to display inorder representation
void inorder(NODE root)
{
	
	if(root==NULL)
	{
		return;
	}
	inorder(root->llink);
	printf(" %c",root->ch);
	inorder(root->rlink);
}
void postorder(NODE root)
{
	
	if(root==NULL)
	{
		return;
	}
	postorder(root->llink);
	postorder(root->rlink);
	printf( "%c",root->ch);
}
void preorder(NODE root)
{
	
	if(root==NULL)
	{
		return;
	}
	printf(" %c",root->ch);
	preorder(root->llink);
	preorder(root->rlink);
}
/*//function to perform push
void push(struct node s[],int * top,NODE temp)
{
	(*top)++;
	s[*top]=temp;
}
//function to perform pop 	
NODE pop(struct node s[],int * top)
{
	NODE cur;
	cur=s[*top];
	(*top)--;
	return cur;
}
*/
			
			
			
			
















