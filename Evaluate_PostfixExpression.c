
#include<stdio.h>
#include<ctype.h>
#include<math.h>
int s[20];
int top=-1;
void push(int);
int pop();
int main()
{
	char postfix[20];
	int op1,op2,res,i;
	printf("enter the postfix expression:");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
		{
			if(isdigit(postfix[i]))
				push(postfix[i]-'0');
			else
				{
					op2=pop();
					op1=pop();
						switch(postfix[i])
							{
								case '+':res=op1+op2;
									push(res);
									break;
								case '-':res=op1-op2;
									push(res);
								break;
								case '*':res=op1*op2;
									push(res);
									break;
								case '/':res=op1/op2;
									push(res);
									break;
								case '%':res=op1%op2;
									push(res);
									break;
								case '^':res=pow(op1,op2);
									push(res);
									break;						
							}	
				}		
		}
	printf("postfix expression is:%d",res);
return 0;
}
void push(int ch)
{
	s[++top]=ch;
}

int pop()
{
	return(s[top--]);
}
