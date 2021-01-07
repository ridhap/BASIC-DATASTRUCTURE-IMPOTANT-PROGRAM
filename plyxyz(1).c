//ploynomial
#include<stdio.h>
typedef struct poly
{
	int cf,px,py,pz;
}P;
void accept(P p[6],int *n)
{
	int i;
	printf("Enter no of terms:");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
		printf("Enter cf,px,py,pz:");
		scanf("%d%d%d%d",&(p[i].cf),&(p[i].px),&(p[i].py),&(p[i].pz));
	}
}
void display(P p[],int n)
{
	int i;
	printf("The expression: ");
	for(i=0;i<n;i++)
	{
		if(p[i].cf>0)
		{
			printf("+%d(x^%d)(y^%d)(z^%d)",(p[i].cf),(p[i].px),(p[i].py),(p[i].pz));
		}
		else
			printf("%d(x^%d)(y^%d)(z^%d)",(p[i].cf),(p[i].px),(p[i].py),(p[i].pz));
	}
	printf("\n");
}
int chk(P p[],P term, int m)
{
	int i;
	for(i=0;i<m;i++)
		if(p[i].px==term.px && p[i].py==term.py && p[i].pz==term.pz)
			return i;
	return -1;
}
int add(P a[6],P b[6], P p[12],int m, int n)
{
	int i, index=0,check;
	for(i=0;i<m;i++)
		p[i]=a[i];
	index=i;
	for(i=0;i<n;i++)
	{
		check=chk(p,b[i],m);
		if(check==-1)
		{
			p[index++]=b[i];
		}
		else
		{
			p[check].cf+=b[i].cf;
		}
	}
	return index;
}
int main()
{
	P a[6],b[6],r[12];
	int m,n,k;
	accept(a,&m);
	accept(b,&n);
	display(a,m);
	display(b,n);
	k=add(a,b,r,m,n);
	display(r,k);
}
