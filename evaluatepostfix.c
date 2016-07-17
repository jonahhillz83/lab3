/*
*
*Lab3 part 2
*Program:To calculate the string
*Author: Pratyush Nepal
*Ref:Book and some programmes found online
*
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200
typedef struct{
	int top;
	int items[MAX];
}stack;
void push(stack *, int);
int pop(stack *);
int oper(char,int,int);
int main()
{
	int a;
	int operand1,operand2,value;
	stack s;
	s.top= -1;
	char exp[MAX];
	int symbol;
	gets(exp);
	for(a=0;a<strlen(exp);a++)
	{
		printf("%c", exp[a]);
	}
	for(a=0;a<strlen(exp);a++)
	{
		symbol=exp[a];
		if ((symbol>='0')&&(symbol<='9'))

			push(&s, (symbol-'0'));
		else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='$')
			{
				operand2= pop(&s);
				operand1= pop(&s);
				value = oper(symbol,operand1,operand2);
				push(&s,value);
			}



	}

	printf("\n%d", pop(&s));
}
void push(stack *s, int x)
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
int oper(char signvalue, int operand1,int operand2)
{
	switch(signvalue)
	{
		case '+':
		return(operand1+operand2);
		break;
		case '-':
		return(operand1-operand2);
		break;
		case '*':
		return(operand1*operand2);
		break;
		case '/':
		return(operand1/operand2);
		break;
		case '$':
		return(pow(operand1,operand2));
		break;
		default :
		printf("the string is invalid");
		break;
	}
}

