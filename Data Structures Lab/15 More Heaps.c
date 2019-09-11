#include<stdio.h>
#include<stdlib.h>
typedef struct heap
{
    int *a,size,capacity;
}heap;
void insert(heap *h,int data)
{
        if(h->size==h->capacity)
        {
            printf("OVERFLOW\n");
            return;
        }
        int i=h->size;
        h->a[i]=data;
        h->size++;
        if(i==0)
            return;
        int j=(i-1)/2;
        int key=h->a[i];
        int temp;
        while(i>0 && key<h->a[j])
        {
            h->a[i]=h->a[j];
            i=j;
            j=(i-1)/2;
        }
        h->a[i]=key;
        return;
}


void removeAndheapify(heap* h)
{
    int n=h->size-1;
    int j=0;
    int i=2*j+1;
    int key=h->a[j];
    while(i<=n)
    {
        if(i+1<=n)
        {
            if(h->a[i+1]<h->a[i])
                i++;
        }
            if(h->a[i]<key)
            {
                h->a[j]=h->a[i];
                j=i;
                i=2*j+1;
            }
            else
                break;
        }

    h->a[j]=key;

}

int remove1(heap* h)
{
    int key=h->a[0];
    h->a[0]=h->a[h->size-1];
    h->size--;
    removeAndheapify(h);
    return key;
}
int main()
{
    heap h;
    scanf("%d",&h.capacity);
    h.a=(int*)malloc(sizeof(int)*h.capacity);
    h.size=0;int i;
    while(1)
    {
        int choice,data;
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:scanf("%d",&data);
                    insert(&h,data);
                    break;
            case 1:if(h.size==0)
                        printf("UNDERFLOW\n");
                    else
                        printf("%d\n",remove1(&h));
                        break;
            case 2:return 0;
            default:return 0;

        }
    }

    return 0;
}

