//circular queue using dyanmic memory allocation
#include<stdio.h>
#include<stdlib.h>
int max=4;

int*insert_rear(int*,int*,int*,int*);
void delete_front(int*,int*,int*);
void display(int*,int,int);

int main()
{
	int*a=0;
	int f=0,r=-1,cnt=0,ch;
	a=(int*)malloc(sizeof(int)*max);
	for(;;)
	{
	   printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice\t");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	      case 1:a=insert_rear(a,&r,&f,&cnt);
	      break;
	      case 2:delete_front(a,&f,&cnt);break;
	      case 3:display(a,f,cnt);break;
	      case 4:free(a); return 0;
	   }
	}
}


int*insert_rear(int*a,int*r,int*f,int*cnt)      
{
	int i,pc,j;
	if((*cnt)==max)
	{
	  printf("doubled the max size\n");
	  max*=2;
	  a=(int*)realloc(a,sizeof(int)*max);
	  if((*f)>(*r))
	  {
	    pc=max/2;
	    for(i=0;((*f)+i)<pc;i++)
	       a[pc+i]=a[(*f)+i];
	    for(i=(*r),j=1;i>=0;i--,j++)
	       a[pc-j]=a[i];
	    for(i=0;i<(pc-(*f));i++)
	       a[i]=a[pc+i];
	    (*r)=pc-(*f);
	    (*f)=0;   
	   }
	   printf("CQ overflow - memory increased\n");

	 }
	
	printf("enter element\n");
	(*r)=((*r)+1)%max;
	scanf("%d",a+(*r));
	(*cnt)++;
	return a;
}

void delete_front(int*a,int*f,int*cnt)
{
	if((*cnt)==0)
	{
	  printf("circular queue underflow\n");
	  return ;
	}
	printf("element deleted is %d\n",a[(*f)]);
	(*f)=((*f)+1)%max;
	(*cnt)--;
}

void display(int*a,int f,int cnt)
{
	if(cnt==0)
	{
	  printf("circular queue underflow\n");
	  return ;
	}
	 printf("contents of queue are\t");
	 for(;cnt>0;cnt--)
	 {
	    printf("%d\t",a[f]);
	    f=(f+1)%max;
	 }
}
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
