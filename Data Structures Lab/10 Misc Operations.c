#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        struct node* link;
        int data;
}node;

typedef struct list
{
    node* tail;
}list;


void insert_tail(list* l,int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=temp;
    if(l->tail==NULL)
    {
        l->tail=temp;
        return;
    }
    temp->link=l->tail->link;
    l->tail->link=temp;
    l->tail=temp;
    return;

}


void  delete_pos(list* l)
{
    if(l->tail==NULL)
        return;
    node* prev=l->tail,*curr=l->tail->link;
    node* q=curr;
    int i=1;
    while(1)
    {   if(i%2==1)
        {   prev=curr;
            curr=curr->link;
        }
        else
        {
            printf("%d ",curr->data);
            prev->link=curr->link;
            if(curr==l->tail)
                l->tail=prev;
            free(curr);
            if(l->tail->link==l->tail)
                break;

            curr=prev->link;
        }
        i++;

    }
    return;
}

void print(node* tail)
{
    node* q=tail->link;
    while(q!=tail)
    {
        printf("%d",q->data);
        q=q->link;
    }
     printf("%d",q->data);
}
int main()
{
    list l;
    l.tail=NULL;
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        insert_tail(&l,i);
    //print(l.tail);
    delete_pos(&l);
    return 0;
}
