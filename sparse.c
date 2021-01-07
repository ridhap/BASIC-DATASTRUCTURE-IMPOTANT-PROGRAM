//Program to print transpose of matrix
#include<stdio.h>
#include<stdlib.h>
typedef struct sparse
{
	int row;
	int col;
	int val;
}M;
//Accept the row and col
void acceptrc(int *r, int *c)
{
	printf("Enter the rows and columns: ");
	scanf("%d %d",r,c);
}
//Accept the matrix
void accept(M m[],int row, int col)
{
	int j,i,val,index=0;
	printf("Enter the elements:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&val);
			if(val!=0)
			{
				//store the elements
				index++;
				m[index].row=i;
				m[index].col=j;
				m[index].val=val;
			}
		}
	}
	m[0].row=i;
	m[0].col=j;
	m[0].val=index;
}
//Display function
void dis(M m[])
{
	int i,row,col,j,index=1;
	row=m[0].row;
	col=m[0].col;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(m[index].row==i && m[index].col==j)
			{
				printf("%d ",m[index].val);
				index++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}
//Transpose
void transpose(M m[], M n[])
{
	int i,j,row,col,index=0,n1;
	row=m[0].row;
	col=m[0].col;
	n1=m[0].val;
	for(i=0;i<col;i++)
	{
		//chk for all elements
		for(j=1;j<=n1;j++)
		{
			if(i==m[j].col)
			{
				index++;
				n[index].row=m[j].col;
				n[index].col=m[j].row;
				n[index].val=m[j].val;			
			}
		}
	}
	n[0].row=m[0].col;
	n[0].col=m[0].row;
	n[0].val=m[0].val;
}
int main()
{
	M a[10],b[10];
	int row,col;
	acceptrc(&row,&col);
	accept(a,row,col);
	printf("The matrix is:\n");
	dis(a);
	printf("The transpose is:\n");
	transpose(a,b);
	dis(b);
}
