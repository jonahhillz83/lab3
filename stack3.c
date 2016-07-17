#include<stdio.h>
int top=0,pos=0;
char stack[20];
void push(char a)
{
stack[top++]=a;
}
char pop()
{
return stack[--top];
}
int prec(char op)
{
if(op=='^'||op=='$')
return 3;
else if (op=='*'||op=='/')
return 2;
else if (op=='+'||op=='-')
return 1;
else
return 0;
}

int main()
{
int i,xyz[20];
char in[20],ch,s,b,a;
printf("enter infix expression");
gets(in);
for(i=0;i<strlen(in);i++)
{
ch=in[i];
switch(ch)
{
case '(':push(ch);
break;
case'^':case'$':case'*':case'/':case'+':case'-':
if(stack[top-1]=='*'||stack[top-1]=='/'||stack[top-1]=='+'||stack[top-1]=='-')
{if(prec(stack[top-1])>=prec(ch))
{do
{b=pop();
xyz[pos++]=b;
}while(prec(stack[top-1])>=prec(ch));
}
}
push(ch);
break;
case')':
do{
s=pop();
if(a!='(')
xyz[pop++]=s;

}while(s!='(');
break;
default:xyz[pos++]=ch;
}
printf("stack=%s \tpostfix:%s\n",stack,xyz);
}
while(top>0)
{
xyz[pos++]=pop();
}
xyz[pos]='\0';
printf("postfix expression=%s",xyz);
}

