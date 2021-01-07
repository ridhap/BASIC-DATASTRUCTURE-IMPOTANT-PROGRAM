//Program to add two polynomial
#include<stdio.h>
typedef struct poly
{
	int cf;
	int px;
}P;
//Accept the terms
void accept(P p[], int n)
{
	int i;
	printf("Enter the coefficients and power:\n");
	for(i=0;i<n;i++)
	{
		//Accept the coefficients and power
		scanf("%d",&p[i].cf);
		scanf("%d",&p[i].px);
	}
}
//Display function
void dis(P p[], int n)
{
	int i;
	printf("The expression is: ");
	for(i=0;i<n;i++)
	{
		if(p[i].cf>0)
		{
			printf("+%dx^%d",p[i].cf,p[i].px);
		}
		else
			printf("%dx^%d",p[i].cf,p[i].px);
	}
	printf("\n");
}
//Check for occurence
int chk(P c[],int term,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(c[i].px==term)
			return i;
	}
	return -1;
}
//add the polynomial
int add(P a[],P b[],P c[], int m, int n)
{
	int i,index,check;
	for(i=0;i<m;i++)
		c[i]=a[i];
	index=i;
	for(i=0;i<n;i++)
	{
		check=chk(c,b[i].px,n);
		//check if power is already present
		if(check==-1)
		{
			c[index]=b[i];
			index++;
		}
		else
		{
			c[check].cf+=b[i].cf;
		}
	}
	return (index);
}
int main()
{
	P a[10],b[10],c[10];
	int m,n,k;
	printf("Enter number of terms in a: ");
	scanf("%d",&m);
	accept(a,m);
	printf("Enter number of terms in b: ");
	scanf("%d",&n);
	accept(b,n);
	printf("a, ");
	dis(a,m);
	printf("b, ");
	dis(b,n);
	printf("Sum, ");
	k=add(a,b,c,m,n);
	dis(c,k);
}
