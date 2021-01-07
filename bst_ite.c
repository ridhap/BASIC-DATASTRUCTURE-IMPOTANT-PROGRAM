//program to find preorder inorder and postorder using iterative approach
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node * llink;
	int info;
	struct node * rlink;
};
typedef struct node *NODE;
void preorder_ite(NODE);
void inorder_ite(NODE);
void postorder_ite(NODE);
NODE insert_bst(NODE ,int);
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
		exit(0);
	return temp;
}
int main()
{
	NODE root=NULL;
	int ch,n,i,item;
	while(1)
	{
		printf("Enter\n1.insert\n2.preorder\n3.inorder\n4.postorder\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the no of elements\n");
				scanf("%d",&n);
				printf("Enter all the %d elements\n",n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&item);
					root=insert_bst(root,item);
				}
				break;
			case 2:  //printf("preorder:");
				 preorder_ite(root);
				 printf("\n");
				 break;
			case 3:  //printf("\ninorder:");
				 inorder_ite(root);
				  printf("\n");
				 break;
				 
			case 4:	  //printf("\npostorder:");
				  postorder_ite(root);
				   printf("\n");
				  break;
			default :exit(1);
		}
	}
}
//function to insert element to bst
NODE insert_bst(NODE root,int item)
{
	NODE temp,prev,cur;
	//int item;
	cur=root;
	prev=NULL;
	temp=getnode();
	temp->llink=NULL;
	temp->rlink=NULL;
	temp->info=item;
	//printf("enter the item\n");
	//scanf("%d",&(temp->info));
	if(root==NULL)
	{
		return temp;
	}
	while(cur!=NULL)
	{	
		prev=cur;
		if(cur->info>item)
		{
			cur=cur->llink;
		}
		else
		{
			cur=cur->rlink;
		}
	}
	if(prev->info>item)
	{
		prev->llink=temp;
	}
	else
	{
		prev->rlink=temp;
	}
	return root;
}
//function to perform preorder traversal
void preorder_ite(NODE root)
{
	NODE cur=root;
	NODE s[20];
	int top=-1;
	for( ; ; )
	{
		while(cur!=NULL)
		{
			printf(" %d",cur->info);
			s[++top]=cur;
			cur=cur->llink;
		}
		if(top!=-1)
		{
			
			cur=s[top--];
			cur=cur->rlink;
			
		}
		else
			 return;
		 
	}
}
//function to perform inorder traversal
void inorder_ite(NODE root)
{
	NODE cur,s[20];
	int top=-1;
	cur=root;
	if(root==NULL)
	{
		printf("bst is empty\n");
		return;
	}
	while(1)
	{
		while(cur!=NULL)
		{
			s[++top]=cur;
			cur=cur->llink;
		}
		if(top!=-1)
		{
			cur=s[top--];
			printf(" %d",cur->info);
			cur=cur->rlink;
		}
		else
			return;
	}
}
//function to perform postorder traversal
void postorder_ite(NODE root)
{
	struct stack
	{
		NODE address;
		int flag;
	};
	NODE cur;
	int top=-1;
	struct stack s[20];
	if(root==NULL)
	{
		printf("bst is empty\n");
		return;
	}
	cur=root;
	for( ; ; )
	{
		while(cur!=NULL)
		{
			top++;
			s[top].address=cur;
			s[top].flag=1;
			cur=cur->llink;
		}
		while(s[top].flag<0)
		{
			cur=s[top].address;
			top--;
			printf(" %d",cur->info);
			if(top==-1) return;
		}
		cur=s[top].address;
		cur=cur->rlink;
		s[top].flag=-1;
	}
}
