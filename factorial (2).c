//Program to find factorial
#include<stdio.h>
int fact(int n)
{
	if(n==0)
		return 1;
	return (n*fact(n-1));
}
int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(n<0)
		printf("Invalid number\n");
	else
		printf("Factorial=%d",fact(n));
}
