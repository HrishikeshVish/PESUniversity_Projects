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

void delete_pos(list* l,int pos)
{
    if(pos<0 || pos>=l->count)
        return;
    if(pos==0)
    {
        node* temp=l->head;
        l->head=l->head->next;
        if(l->head!=NULL)
            l->head->prev=NULL;
        else
            l->tail=NULL;
        l->count--;
        free(temp);
        return;
    }
    else if(pos==l->count-1)
    {
        node* temp=l->tail;
        l->tail=l->tail->prev;
        if(l->tail!=NULL)
            l->tail->next=NULL;
        else
            l->head=NULL;
        free(temp);
        l->count--;
        return;
    }
    int i=0;
    node* temp=l->head;
    while(i!=pos)
    {
        i++;
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return;
}


void insert_tail(list* l,int data)
{
    node* temp=getNode(data);
    temp->next=NULL;
    temp->prev=l->tail;
    if(l->tail!=NULL)
        l->tail->next=temp;
    l->tail=temp;
    if(l->head==NULL)
        l->head=temp;
    l->count++;
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
                        delete_pos(&l,data);
                        break;
                case 1:scanf("%d",&data);
                        insert_tail(&l,data);
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

