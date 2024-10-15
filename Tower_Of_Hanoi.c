/*Solving Tower of Hanoi problem with n disks*/
#include<stdio.h>
void tower(int,char,char,char);
int main()
{
	int n;
	printf("enter no of disks:");
	scanf("%d",&n);
		if(n==0)
		{
			printf("no disk found\n");
			return 0;
		}		
	printf("moves involed in tower of hanio\n");
	tower(n,'A','C','B');
return 0;
}

void tower(int n,char source,char dest,char temp)
{
	if(n==1)
	{
		printf("move %d disk from %c to %c\n",n,source,dest);
		return;
	}
	tower(n-1,source,temp,dest);
	printf("move %d disk from %c to %c\n",n,source,dest);
	tower(n-1,temp,dest,source);
}

