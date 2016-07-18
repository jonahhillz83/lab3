#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAXITEMS 100
typedef struct{
	int top;
	int items[MAXITEMS];
}stack;
void push(stack *, int);
int pop(stack *);
int oper(char,int,int);
int main()
{
	int i;
	int opnd1,opnd2,value;
	stack s;
	s.top= -1;
	char exp[MAXITEMS];
	int symb;
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		printf("%c", exp[i]);
	}
	for(i=0;i<strlen(exp);i++)
	{
		symb=exp[i];
		if ((symb>='0')&&(symb<='9'))

			push(&s, (symb-'0'));
		else if(symb=='+'||symb=='-'||symb=='*'||symb=='/'||symb=='$')
			{
				opnd2= pop(&s);
				opnd1= pop(&s);
				value = oper(symb,opnd1,opnd2);
				push(&s,value);
			}



	}

	printf("\n%d", pop(&s));
}
void push(stack *s, int x)
{
	if(s->top == MAXITEMS-1)
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
int oper(char sign, int op1,int op2)
{
	switch(sign)
	{
		case '+':return(op1+op2);
		case '-':return(op1-op2);
		case '*':return(op1*op2);
		case '/':return(op1/op2);
		case '$':return(pow(op1,op2));
		default : printf("invalid");
	}
}


