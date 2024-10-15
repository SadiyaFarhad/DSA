/*Design, Develop and Implement a menu driven Program in C Language for the following operations on Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 3
char cq[20];
int  f=-1,r=-1;
void insert();
void del();
void display();
int  main()
{
	int ch;
	do
	{
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:del();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("invalid choice");				
		}
	}while(ch!=4);
	return 0;
}

void insert()
{
	char e;
	if((r+1)%MAX==f)
	{
		printf("cq is full");
		return;
	}
	printf("enter the item:");
	scanf(" %c",&e);  /*give one space before %c*/
	r=(r+1)%MAX;
	cq[r]=e;
	if(f==-1)
	f=0;	
}


void del()
{
	char e;
	if(f==-1)
	{
		printf("cq is empty");
		return;
	}
	else
	{
		e=cq[f];
		if(f==r)
		   f=r=-1;
		else
		   f=(f+1)%MAX;
		printf("deleted item:%c",e);   
	}
}

void display()
{
	int i;
	if(f==-1)
	{
		printf("cq is empty");
		return;
	}
	else
	{
		i=f;
		while(i!=r)
		{
			printf("%c\n",cq[i]);
			i=(i+1)%MAX;
			
		}
		printf("%c\n",cq[r]);
	}
}
