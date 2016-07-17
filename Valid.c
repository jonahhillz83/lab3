/*
*
*Lab3 part 1
*Program:TO find the validity of the string
*Author: Pratyush Nepal
*Ref:Book and some programmes found online
*
*/
#include<stdio.h>
#include<string.h>
#define MAX 200
typedef struct{
	int top;
	char items[MAX];
}stack;
void push(stack *, char);
int pop(stack *);

int main()
{
	stack s;
	s.top = -1;
	int a,b;
	int validstring=1;
	printf("Enter the string you want to validate\n");
	char expression[MAX],symbol,j;
	gets(expression);
	for(a=0;a<strlen(expression);a++)
	{
		printf("%c", expression[a]);
	}
	for(a=0;a<strlen(expression);a++)
	{
		symbol=expression[a];
		if(symbol=='('||symbol=='['||symbol=='{')/*This loop checks the braces*/
		{
			push(&s,symbol);
		}
		else if(symbol==')'||symbol==']'||symbol=='}')
		{
			 if (s.top == -1)
			{
			printf("Empty\n");
			validstring = 0;
			}
			else{
				b=pop(&s);
				if((symbol == ')' && b== '[') || (symbol == ')' && b == '{'))
					validstring=0;
			}
		}
	}
	if(s.top!=-1)
	{
	validstring=0;
	}

	if(validstring==1)/*This loop checks the string validity*/
	{
		printf("The string that you are trying to enter is invalid\n");
	}
	else
		printf(" The string that you are trying to enter is valid \n");
}

void push(stack *s, char x)
{
	if(s->top == MAX-1)
	{
		printf("stack overflow\n");
		exit(1);
	}
	else
	s->items[++(s->top)] = x;
	return;
}
int pop (stack*s)
{
	if (s->top == -1)
	{
		printf("stack underflow");
		exit(1);
	}
	return s->items[s->top--];
}
