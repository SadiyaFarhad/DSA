/*2.Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximumsize MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate Overflow and Underflow situations on Stack
d. Display the status of Stack
e. Exit*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int s[MAX];
int top=-1;
void push();
int pop();
void display();
int isoverflow();
int isunderflow();

int main()
{
	int ch,e;
	do
		{
			printf("\n1.push\n2.pop\n3.display\n4.exit\n");
			printf("enter your choice:");
			scanf("%d",&ch);
				switch(ch)
					{
						case 1:if(isoverflow())
								printf("stack overflow");
							else
								push();
							break;
						case 2:if(isunderflow())
								printf("stack underflow");
							else
								{
								e=pop();
								printf("deleted element is %d",e);
								}
							break;
						case 3:if(isunderflow())	
								printf("stack underflow");
							else
								display();
							break;
						case 4:	exit(0);
						default:printf("invalid choice\n");
					}
		}while(ch!=5);
	return 0;
}

int isoverflow()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}

int isunderflow()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push()
{
	int e;
	printf("enter the element to be pushed:");
	scanf("%d",&e);
	s[++top]=e;
}

int pop()
{
	int e;
	e=s[top--];
	return e;
}


void display()
{
	int i;
	printf("content of stack are\n");
	for(i=top;i>=0;i--)
		printf("%d\n",s[i]);
}

