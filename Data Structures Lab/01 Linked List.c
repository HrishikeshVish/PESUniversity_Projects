#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* link;
    int data;
}node;

typedef struct list{
    node* head;
    int count;
}list;

void add_pos(list* l,int data,int pos)
{
    if(pos<0 || pos>l->count)
        return;
    int i=0;
    node* prev=NULL,*curr=l->head;
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=NULL;
    if(pos==0)
    {
        temp->link=l->head;
        l->head=temp;
        l->count++;
        return;
    }
    while(curr!=NULL && i!=pos)
    {
        prev=curr;
        curr=curr->link;
        i++;
    }
    prev->link=temp;
    temp->link=curr;
    l->count++;
    return;
}


void print(node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->link;
    }
    printf("\n");
    return;
}


void reverse(list* l)
{

    node* curr=l->head,*prev=NULL,*next;
    while(curr!=NULL)
    {
            next=curr->link;
            curr->link=prev;
            prev=curr;
            curr=next;
    }
    l->head=prev;
    return;
}

void del_end(list* l)
{
    node* prev=NULL,*curr=l->head;
    if(l->head==NULL)
        return;
    while(curr->link!=NULL)
    {
        prev=curr;
        curr=curr->link;
    }
    prev->link=NULL;
    free(curr);
    l->count--;
}

int main()
{
    list l;
    l.head=NULL;
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
                        add_pos(&l,data,pos);
                        break;
                case 1:del_end(&l);
                        break;
                case 2:reverse(&l);
                        break;
                case 3:print(l.head);
                        break;
                case 4: return 0;
                default:return 0;
            }
    }
}
