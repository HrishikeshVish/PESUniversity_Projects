#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int a[100];
    int top;
}stack;

void stack_push(stack*s ,int data)
{
    s->a[++s->top]=data;
    return;
}

int  stack_pop(stack *s)
{
    int x=-1;
    if(s->top!=-1)
        x=s->a[s->top--];
    return x;
}

int stack_peek(stack* s)
{
    return s->a[s->top];
    return;
}

int stack_empty(stack *s)
{
    return s->top==-1;
}

int stack_prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '$':return 5;
        case '(':
        case '[':
        case '{':return 0;
        case '#':return -1;
        default:return 8;

    }
}

int input_prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '$':return 6;
        case '(':
        case '[':
        case '{':return 9;
        case '}':return 0;
        case ']':return 0;
        case ')':return 0;
        default:return 7;

    }
}



void convert(char* infix)
{
    char ch,postfix[100];
    int i=0,j=0;
    stack s;
    s.top=-1;
    stack_push(&s,'#');
    while(infix[i]!='\0')
    {
        char ch1=infix[i];
        i++;
        while(stack_prec(stack_peek(&s))>input_prec(ch1))
        {
            postfix[j++]=stack_peek(&s);
            stack_pop(&s);
        }
        if(stack_prec(stack_peek(&s))!=input_prec(ch1))
            stack_push(&s,ch1);
        else
            stack_pop(&s);
    }
    while(stack_peek(&s)!='#')
    {
            postfix[j++]=stack_peek(&s);
            stack_pop(&s);
    }
    postfix[j]='\0';
    printf("%s",postfix);
}

int main()
{
    char a[100];
    scanf("%[^\n]",a);
    convert(a);
    return 0;
}
