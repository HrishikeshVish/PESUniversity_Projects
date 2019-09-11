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

void del_pos(list* l,int pos)
{
    if(pos<0 || pos>=l->count)
        return;
    int i=0;
    node* curr=l->head,*prev=NULL;
    if(pos==0)
    {
      l->head=l->head->link;
      free(curr);
      l->count--;
      return;
    }
    while(curr!=NULL && i!=pos)
    {
        prev=curr;
        curr=curr->link;
        i++;
    }
    prev->link=curr->link;
    free(curr);
    l->count--;
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

void add_end(list* l,int data)
{
    node*curr=l->head;
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=NULL;
    if(l->head==NULL)
        {
            l->head=temp;
            l->count++;
            return;
        }
    while(curr->link!=NULL)
    {
        curr=curr->link;
    }
    curr->link=temp;
    l->count++;
}

int main()
{
    list l;
    l.head=NULL;
    l.count=0;
    int data;
    int choice=1;
    while(1)
    {

            scanf("%d",&choice);
            switch(choice)
            {
                case 0:scanf("%d",&data);
                        del_pos(&l,data);
                        break;

                case 1:scanf("%d",&data);
                        add_end(&l,data);
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

