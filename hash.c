#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define HZ 3
struct emp
{
	int eid;
	char en[20];
	int sal;
};
typedef struct emp E;
struct hashtable
{
	int key;
	int addr;
};
typedef struct hashtable ht;
int hash(int num)
{
	int index;
	index=num%HZ;
	return index;
}
void insert(FILE *fp,ht h[HZ],int n)
{
	E E1;
	int i,hval,countindex;
	for(i=0;i<n;i++)
	{
		printf("Enter EID,EName,ESal\n");
		scanf("%d%s%d",&E1.eid,E1.en,&E1.sal);
		hval=hash(E1.eid);
		countindex=hval;
		while(h[hval].key!=-1)
		{
			hval=(hval+1)%HZ;
			if(hval==countindex)
			{			
				printf("Hashtable is full\n");
				return;
			}
		}
		fseek(fp,0,SEEK_END);
		h[hval].addr=ftell(fp);
		h[hval].key=E1.eid;
		fwrite(&E1,sizeof(E),1,fp);
	}
	
}
void search(FILE *fp,ht h[HZ])
{
	E E1;
	int hval,countindex;
	printf("Enter EID to be searched\n");
	scanf("%d",&E1.eid);
	
	hval=hash(E1.eid);
	countindex=hval;
	while(h[hval].key!=E1.eid)
	{
		hval=(hval+1)%HZ;
		if(hval==countindex)
		{			
			printf("Search unsuccessfull\n");
			return;
		}
	}
	fseek(fp,h[hval].addr,SEEK_SET);
	fread(&E1,sizeof(E),1,fp);
	printf("\tEID:%d\n\tEName:%s\n\tEsal:%d\n",E1.eid,E1.en,E1.sal);
}
void display(FILE *fp,ht h[HZ])
{
	E E1;
	int i,hval;
	for(i=0;i<HZ;i++)
	{
		hval=h[i].key;
		if(h[i].key!=-1)
		{
			fseek(fp,h[i].addr,SEEK_SET);
			fread(&E1,sizeof(E),1,fp);
			printf("\tEID:%d\n\tEName:%s\n\tEsal:%d\n\n\n",E1.eid,E1.en,E1.sal);
		}
	}
}
int main()
{
	ht h[HZ];
	int n,i,ch;
	FILE *fp;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	fp=fopen("EMP.txt","w+");
	for(i=0;i<HZ;i++)
	{
		h[i].key=-1;
	}
	while(1)
	{
		printf("Enter your choice\n");
		printf("1.Insert\n2.Search\n3.Display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(fp,h,n);
				break;
			case 2:search(fp,h);
				break;
			case 3:display(fp,h);
				break;
			default:exit(0);
		}
	}
}

	
