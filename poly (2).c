//program to perform polynomial addition and evaluation using circular header linked list
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
	int cf,px,py,pz;
	struct poly * link;
};
typedef struct poly * POLY;
POLY getnode()
{
	POLY temp;
	temp=(POLY)malloc(sizeof(struct poly));
	if(temp==NULL)
	{
		printf("Memory not allocated\n");
		exit(0);
	}
	return temp;
}
void insert(POLY,int,int,int,int);
void display(POLY);
void add_poly(POLY,POLY,POLY);
POLY search_power(POLY,POLY);
void evaluate(POLY);
int main()
{
	int n,m,i,cf,px,py,pz,ch;
	POLY a,b,c,d;
	a=getnode();
	a->link=a;
	printf("Enter the no.of terms in a\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the cf,px,py,pz\n");
		scanf("%d%d%d%d",&cf,&px,&py,&pz);
		insert(a,cf,px,py,pz);
	}
	printf("Polynomial a: ");
	display(a);
	b=getnode();
	b->link=b;
	printf("Enter the no.of terms in b\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("Enter the cf,px,py,pz\n");
		scanf("%d%d%d%d",&cf,&px,&py,&pz);
		insert(b,cf,px,py,pz);
	}
	printf("Polynomial b: ");
	display(b);
	c=getnode();
	c->link=c;
	d=getnode();
	d->link=d;
	while(1)
	{
		printf("Enter\n1.evaluation of given expression\n2.add and evaluate the polynomial\n3.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(d,6,2,2,1);
				insert(d,-4,0,1,4);
				insert(d,3,3,1,1);
				insert(d,2,1,5,10);
				insert(d,-2,1,1,3);
				evaluate(d);
				break;
			case 2: printf("Adding polynomial a and b\n");
				add_poly(a,b,c);
				display(c);
				evaluate(c);
				break;
			default:exit(0);
		}
	}
}
//function to insert the details
void insert(POLY head,int cf,int px,int py,int pz)
{
	POLY temp,first;
	temp=getnode();
	temp->cf=cf;
	temp->px=px;
	temp->py=py;
	temp->pz=pz;
	first=head->link;
	temp->link=first;
	head->link=temp;
}
//function to display the polynomial
void display(POLY head)
{
	POLY cur;
	cur=head->link;
	while(cur!=head)
	{
		if(cur->cf > 0)
		{
			printf(" +%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
		}
		else
			printf(" %dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
		cur=cur->link;
	}
	printf("\n");
}
//function to add the polynomial
void add_poly(POLY a,POLY b,POLY c)
{
	POLY cur,index,pos;
	index=a->link;
	while(index!=a)
	{
		pos=search_power(b,index);
		if(pos==NULL)
		{
			insert(c,index->cf,index->px,index->py,index->pz);
		}
		else
		{
			insert(c,index->cf+pos->cf,index->px,index->py,index->pz);
			pos->cf=-999;
		}
		index=index->link;
	}
	cur=b->link;
	while(cur!=b)
	{
		if(cur->cf!=-999)
		{
			insert(c,cur->cf,cur->px,cur->py,cur->pz);
		}
		cur=cur->link;
	}
	
	
}
//function to search the power
POLY search_power(POLY b,POLY term)
{
	POLY cur;
	cur=b->link;
	while(cur!=b)
	{
		if(term->px==cur->px && term->py==cur->py && term->pz==cur->pz)
			return cur;
		cur=cur->link;
	}
	return NULL;
}
//function to evaluate the polynomial
void evaluate (POLY c)
{
	double x,y,z,res=0;
	POLY cur=c->link;
	printf("Enter the values of x,y and z\n");
	scanf("%lf%lf%lf",&x,&y,&z);
	while(cur!=c)
	{
		res=cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz)+res;
		cur=cur->link;
	}
	printf("The evaluated result= %lf\n",res);
}

