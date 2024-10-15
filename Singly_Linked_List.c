/*Design, Develop and Implement a menu driven Program in C for the followingoperations on Singly Linked List (SLL) of Student Data with the fields: USN,Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit*/
#include<stdio.h>
#include<stdlib.h>
typedef struct  node
{
	char usn[10];
	char name[10];
	char branch[10];
	int sem;
	int phno;
	struct node *next;
}node;
node *first=NULL;
node *read_data();
void front_insert();
void front_del();
void end_insert();
void end_del();
void display();
main()
{
int ch;
do
{
printf("1.front_insert\n2.front_delete\n3.end_insert\n4.end_delete\n5.display\n6.exit\n");
printf("enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:front_insert();
	break;
case 2:front_del();
	break;
case 3:end_insert();
	break;
case 4:end_del();
	break;
case 5:display();
	break;
case 6:exit(0);
default:printf("invalid choice");
}
}while(ch!=6);
return 0;
}



node*read_data()
{
	node *nn;
	nn=(node *)malloc(sizeof(node));
	printf("enter the usn:");
	scanf("%s",nn->usn);
	printf("enter the name:");
	scanf("%s",nn->name);
	printf("\nenter the branch:");
	scanf("%s",nn->branch);
	printf("\nenter the semester:");
	scanf("%d",&nn->sem);
	printf("enter the phno:");
	scanf("%d" ,&nn->phno);
	nn->next=NULL;
return(nn);
}

void front_insert()
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp=read_data();
	if(first==NULL)
		first=temp;
	else
		{
			temp->next=first;
			first=temp;
		}	
}

void end_insert()
{
	node *temp,*curr;
	temp=(node *)malloc(sizeof(node));
	temp=read_data();
	if(first==NULL)
		first=temp;
	else
		{
			curr=first;
				while(curr->next!=NULL)
					curr=curr->next;
				curr->next=temp;
		}
}

void front_del()
{
	node *temp;
	if(first==NULL)
		printf("list is empty\n");
	else
		{
			temp=first;
			first=first->next;
			free(temp);
		}	
}

void end_del()
{
	node *curr,*prev;
	if(first==NULL)
		printf("list is empty\n");
	if(first->next==NULL)
		{
			curr=first;
			first=NULL;
			free(curr);
		}
	else
		{
			curr=first;
				while(curr->next!=NULL)
					{
						prev=curr;
						curr=curr->next;
					}
			prev->next=NULL;
			free(curr);			
		}
}





void display()
{
	int count=0;
	node *temp;
	if(first==NULL)
		printf("list is empty");
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			printf("\nusn:%s",temp->usn);
			printf("\nname:%s",temp->name);
			printf("\nbranch:%s",temp->branch);
			printf("\nsem:%d",temp->sem);
			printf("\nphno:%d\n",temp->phno);
			count++;
			temp=temp->next;
		}
	printf("no of nodes:%d",count);
	}
}

