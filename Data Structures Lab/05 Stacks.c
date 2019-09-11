#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* link;
    int data;
}node;

typedef struct list{
    node* head;
}list;

void insert_head(list* l,int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=l->head;
    l->head=temp;
    return;
}

void delete_head(list* l)
{
    if(l->head==NULL)
        return;
    node* temp=l->head;
    l->head=l->head->link;
    free(temp);
}

void print(node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->link;
    }
    printf("\n");

}

void destroy_stack(list* l)
{
    node* prev=NULL,*temp=l->head;
    while(temp!=NULL)
    {
        prev=temp->link;
        free(temp);
        temp=prev;
    }
}
int main()
{
    list l;
    l.head=NULL;
    int data;
    int choice=1,pos;
    while(1)
    {

            scanf("%d",&choice);
            switch(choice)
            {
                case 0:scanf("%d",&data);
                        insert_head(&l,data);
                        break;
                case 1:if(l.head==NULL)
                            printf("UNDERFLOW\n");
                        else
                            delete_head(&l);
                        break;
                case 2:if(l.head==NULL)
                            printf("EMPTY STACK\n");
                        else
                            printf("%d\n",l.head->data);
                        break;
                case 3:destroy_stack(&l);
                        return 0;
                default:return 0;
            }
    }
}

