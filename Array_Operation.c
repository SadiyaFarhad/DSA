/*1. Design, Develop and Implement a menu driven Program in C for the following Array operations
a. Creating an Array of N Integer Elements
b. Display of Array Elements with Suitable Headings
c. Inserting an Element (ELEM) at a given valid Position (POS)
d. Deleting an Element at a given valid Position(POS)
e. Exit.	
Support the program with functions for each of the above operations.*/

#include<stdio.h>
#include<stdlib.h>
int a[10],n;
void create();
void insert();
void del();
void display();
int main()
{
	int ch;
	printf("array creation\n");
	create();
	do
	{
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
			switch(ch)	
				{
					case 1 :insert();
						break;
					case 2 :del();
						break;
					case 3 :display();
						break;
					case 4 :exit(0);
					default:printf("invalid choice");					
				}
	}while(ch!=4);
   return 0;			
}

void  create()
{
	int i;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("enter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);	
}
void display()
{
	int i;
	printf("array elements are\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
}

void insert()
{
	int i,e,pos;
	printf("enter the position where element is to be inserted\n");
	scanf("%d",&pos);
	printf("enter the element to be inserted:");
	scanf("%d",&e);
	for(i=n;i>pos;i--)
		a[i]=a[i-1];
	a[pos]=e;
	n=n+1;
}

void del()
{
	int i,e,pos;
	printf("enter the position to be deleted\n");
	scanf("%d",&pos);
	e=a[pos];
	for(i=pos;i<n-1;i++)
		a[i]=a[i+1];
	n=n-1;
	printf("deleted element is %d",e);
}

