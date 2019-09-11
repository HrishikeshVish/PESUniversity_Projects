#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* prev,*next;
    int data;
}node;

typedef struct list{
    node* head,*tail;
    int count;
}list;


node* getNode(int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;

}

void print_rev(node* tail)
{
    while(tail!=NULL)
    {
        printf("%d ",tail->data);
        tail=tail->prev;
    }
    printf("\n");
}


void insert_pos(list* l,int data,int pos)
{
    if(pos<0 || pos>l->count)
        return;
    node* temp=getNode(data);
    if(pos==0)
    {
        temp->next=l->head;
        if(l->head!=NULL)
            l->head->prev=temp;
        l->head=temp;
        l->count++;
        if(l->tail==NULL)
            l->tail=l->head;
        return;
    }
    else if(pos==l->count)
    {
        l->tail->next=temp;
        temp->prev=l->tail;
        l->tail=temp;
        return;
    }
    int i=0;
    node* curr=l->head;
    while(i!=pos)
    {
        i++;

        curr=curr->next;
    }

    curr->prev->next=temp;
    temp->prev=curr->prev;
    temp->next=curr;
    curr->prev=temp;
    l->count++;
}


void delete_tail(list* l)
{
    if(l->head==NULL)
        return;
    if(l->head->next==NULL)
    {
        free(l->head);
        l->head=l->tail=NULL;
        l->count=0;
    }
    node* curr=l->head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->prev->next=NULL;
    free(curr);
    l->count--;
    return;
}
void print(node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    list l;
    l.head=NULL;
    l.tail=NULL;
    l.count=0;
    int data;
    int choice=1,pos;
    while(1)
    {

            scanf("%d",&choice);
            switch(choice)
            {
                case 0:scanf("%d",&data);
                        scanf("%d",&pos);
                        insert_pos(&l,data,pos);
                        break;
                case 1:delete_tail(&l);
                        break;
                case 2:print_rev(l.tail);
                        break;
                case 3:print(l.head);
                        break;
                case 4: return 0;
                default:return 0;
            }
    }
}
