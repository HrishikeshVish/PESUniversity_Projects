#include<stdio.h>
#include<stdlib.h>
void top_down(int *h,int n)
{

    int j=0;
    int i=0,k;
    for(k=1;k<=n;k++)
    {
        i=k;
        int key=h[i];  //store the child node
        j=(i-1)/2;    //parent node
        while(i>0 && key>h[j])
        {
            h[i]=h[j]; //move parent down
            i=j; //new child node
            j=(i-1)/2;//new parent node
        }
        h[i]=key;

    }
}


void heapify(int *h,int n)
{
    int j=0;
    int i=2*j+1;
    int key=h[j];
    while(i<=n)
    {
        if(i+1<=n) //check if the right node exists
        {
            if(h[i+1]>h[i])
                i++;    //find the largest child
        }
        if(key<h[i])
        {
            h[j]=h[i]; //move the child up
            j=i;        //new parent
            i=2*j+1; //find new child
        }
        else
            break;
    }
    h[j]=key;
}


int main()
{
    int n,i,k;
    scanf("%d",&n);
    k=n;
    int *h=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    top_down(h,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",h[0]);
        h[0]=h[k-1];
        k--;
        heapify(h,k-1);
    }
    return 0;
}
