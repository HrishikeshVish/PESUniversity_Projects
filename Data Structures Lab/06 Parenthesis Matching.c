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
int check(char *a)
{
    int i=0;
    stack s;
    s.top=-1;
    while(a[i]!='\0')
    {
        char ch=a[i];
        i++;
        switch(ch)
        {
            case '{':
            case '[':
            case '(':stack_push(&s,ch);
                    break;
            case '}':if(!stack_empty(&s))
                    {
                        if(stack_peek(&s)=='{')
                        {
                                stack_pop(&s);
                                break;
                        }
                        else
                            return 0;
                    }
                    else
                        return 0;
                case ']':if(!stack_empty(&s))
                    {
                        if(stack_peek(&s)=='[')
                        {
                                stack_pop(&s);
                                break;
                        }
                        else
                            return 0;
                    }
                    else
                    return 0;
                   case ')':if(!stack_empty(&s))
                    {
                        if(stack_peek(&s)=='(')
                        {
                                stack_pop(&s);
                                break;
                        }
                        else
                            return 0;
                    }
                    else
                    return 0;

        }
    }
    if(stack_empty(&s))
        return 1;
    return 0;
}

int main()
{
    char a[100];
    scanf("%[^\n]",a);
    if(check(a))
        printf("Yes");
    else
        printf("No");
    return 0;
}
