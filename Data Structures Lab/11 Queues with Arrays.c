#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int s1[100],s2[100];
    int top1,top2;
}queue;

void enqueue(queue* q,int data)
{
    q->s1[++q->top1]=data;
}


int pop(queue *q,int a)
{
    int x;
    if(a==1)
    {
        x=q->s1[q->top1];
        q->top1--;
    }
    else
    {
        x=q->s2[q->top2];
        q->top2--;
    }
    return x;
}
void dequeue(queue* q)
{
    if(q->top2==-1 && q->top1==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    if(q->top2==-1)
    {
        int i=0;
        for(i=q->top1;i>=0;i--)
            q->s2[++q->top2]=pop(q,1);
    }
        pop(q,2);
}

int  peek(queue *q)
{
    if(q->top2==-1 && q->top1==-1)
    {
        return -1;
    }
    if(q->top2==-1)
    {
        int i=0;
        for(i=q->top1;i>=0;i--)
            q->s2[++q->top2]=pop(q,1);
    }
    return q->s2[q->top2];
}

int main()
{
    queue q;
    q.top1=q.top2=-1;
    int choice,data;
    while(1)
    {
        scanf("%d",&coice);
        switch(choice)
        {
            case 0:scanf("%d",&data);
                    enqueue(&q,data);
                    break;
            case 1:dequeue(&q);
                    break;
            case 2:int x=peek(&q);
                    if(x==-1)
                        printf("EMPTY QUEUE\n");
                    else
                        printf("%d\n",x);
                    break;
            default:return 0;
        }
    }
}
