//proram for binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* llink;
	int info;
	struct node*rlink;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("memory is not exist\n");
		exit(0);
	}
	return temp;
}
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
void preorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}
void inorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->llink);
	printf("%d\t",root->info);
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
	printf("%d\t",root->info);
}
NODE search_bst(NODE root)
{
	NODE cur;
	int key;
	printf("enter the key element\n");
	scanf("%d",&key);
	if(root==NULL)
	{
		printf("empty binary search tree\n");
		return NULL;
	}
	else
	{
		cur=root;
		while(cur!=NULL)
		{
			if(cur->info==key)
			{
				printf("search is successful\n");
				return NULL;
			}
			else if(cur->info<key)
			{
				cur=cur->rlink;
			}
			else
			{
				cur=cur->llink;
			}
		}
		printf("search is unsuccessful\n");
		return NULL;
	}
}
NODE delete_bst(NODE root,int elem)
{
	NODE cur,parent,suc,next;
	//int key;
	//printf("enter key element\n");
	//scanf("%d",&key);
	if(root==NULL)
	{
		printf("binary search tree is empty\n");
		return NULL;
	}
	parent=NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(cur->info==elem)
		{
			break;
		}
		parent=cur;
		if(cur->info<elem)
		{
			cur=cur->rlink;
		}
		else
		{
			cur=cur->llink;
		}
	}
	if(cur==NULL)
	{
		printf("element does not exist\n");
		return root;
	}
	if(cur->llink==NULL)
	{
		next=cur->rlink;
	}
	else if(cur->rlink==NULL)
	{
		next=cur->llink;
	}
	else
	{
		suc=cur->rlink;
		while(suc->llink!=NULL)
		{
			suc=suc->llink;
		}
		suc->llink=cur->llink;
		next=cur->rlink;
	}
	if(parent==NULL)
	{
		free(cur);
		return next;
	}
	if(cur==parent->llink)
	{
		parent->llink=next;
	}
	else
	{
		parent->rlink=next;
	}
	free(cur);
	return root;
}
int main()
{
	NODE root=NULL;
	int ch,n,i,c,elem,item;
	while(1)
	{
		printf("enter choice\n1.create a bst of n integer\n2.traverse\n3.search bst\n4.delete bst\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the values for n\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("enter item\n");
					scanf("%d",&item);
					root=insert_bst(root,item);
				}
				break;
			case 2:printf("enter choice\n1.inorder\n2.preorder\n3.postorder\n");
				scanf("%d",&c);
				switch(c)
				{
					case 1:inorder(root);
						break;
					case 2:preorder(root);
						break;
					case 3:postorder(root);
						break;
				}
				break;
			case 3:search_bst(root);
				break;
			case 4:printf("enter the elem to be deleted \n");
				scanf("%d",&elem);
				root=delete_bst(root,elem);
				break;
			default:exit(0);
		}
	}
}
		
