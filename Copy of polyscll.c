//Program to add two polynomials using SCLL with header
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
	int cf,px,py,pz;
	struct poly *link;
};
typedef struct poly * POLY;
POLY getnode()
{
	POLY temp;
	temp=(POLY)malloc(sizeof(struct poly));
	if(temp==NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}
	return temp;
}
void insert(int cf, int px, int py,int pz,POLY head)
{
	POLY temp,first;
	temp=getnode();
	temp->link=temp;
	temp->cf=cf;
	temp->px=px;
	temp->py=py;
	temp->pz=pz;
	first=head->link;
	temp->link=first;
	head->link=temp;		
}
POLY se_pow(POLY term, POLY b)
{
	POLY cur=b->link;
	while(cur!=b)
	{
		if(cur->px==term->px && cur->py==term->py && cur->pz==term->pz)
			return cur;
		cur=cur->link;
	}
	return NULL;
}
void add(POLY a, POLY b, POLY c)
{
	POLY cindex, index;
	index=a->link;
	while(index!=a)
	{
		cindex=se_pow(index,b);
		if(cindex==NULL)
			insert(index->cf,index->px, index->py, index->pz, c);
		else
		{
			(index->cf)+=cindex->cf;
			insert(index->cf,index->px, index->py, index->pz, c);
			cindex->cf=-999;
		}
		index=index->link;
	}
	index=b->link;
	while(index!=b)
	{
		if(index->cf!=-999)
			insert(index->cf,index->px, index->py, index->pz, c);
		index=index->link;
	}
}
void display(POLY a)
{
	POLY index=a->link;
	while(index!=a)
	{
		if(index->cf<0)
			printf("%d(x^%d)(y^%d)(z^%d)",index->cf,index->px,index->py, index->pz);
		else
			printf("+%d(x^%d)(y^%d)(z^%d)",index->cf,index->px,index->py, index->pz);
		index=index->link;
	}
	printf("\n");
}
void evaluate(POLY c)
{
	double res=0,x,y,z,val=1;
	POLY index=c->link;
	printf("Enter the values of x,y,z:");
	scanf("%lf%lf%lf",&x,&y,&z);
	while(index!=c)
	{
		val=(index->cf)*pow(x,index->px)*pow(y,index->py)*pow(z,index->pz);
		res+=val;
		index=index->link;
	}
	printf("Result=%lf\n",res);
}
int main()
{
	POLY a,b,c;	
	a=getnode();
	b=getnode();
	c=getnode();
	int ch,cf,px,py,pz,i,n;
	while(1)
	{
		a->link=a;
		b->link=b;
		c->link=c;
		printf("1.Enter the expression\n2.Add the polynomials\nelse Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the number of terms:");
				scanf("%d",&n);	
				for(i=0;i<n;i++)
				{
					printf("Enter cf,px,py,pz:");
					scanf("%d%d%d%d",&cf,&px,&py,&pz);
					insert(cf,px,py,pz, c);
				}
				display(c);
				evaluate(c);
				break;
			case 2:printf("Enter the number of terms of a:");
				scanf("%d",&n);	
				for(i=0;i<n;i++)
				{
					printf("Enter cf,px,py,pz:");
					scanf("%d%d%d%d",&cf,&px,&py,&pz);
					insert(cf,px,py,pz,a);
				}
				printf("Enter the number of terms of b:");
				scanf("%d",&n);	
				for(i=0;i<n;i++)
				{
					printf("Enter cf,px,py,pz:");
					scanf("%d%d%d%d",&cf,&px,&py,&pz);
					insert(cf,px,py,pz,b);
				}
				add(a,b,c);
				display(c);
				evaluate(c);
				break;
			default:exit(0);
		}
	}
}
	
		
	
