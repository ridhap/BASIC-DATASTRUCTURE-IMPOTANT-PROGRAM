//Program to find fibonacci
#include<stdio.h>
int fib(int n)
{
	if(n==0 || n==1)
		return n;
	return fib(n-1)+fib(n-2);
}
int main()
{
	int i,n;
	printf("Enter the number:");
	scanf("%d",&n);
	if(n>=0)
		for(i=0;i<=n;i++)
			printf("%d ",fib(i));
	else
		printf("Invalid choice\n");
}
