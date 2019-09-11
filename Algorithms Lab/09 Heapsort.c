
#include<stdio.h>
struct h{
int id;
int val;
};
void bottomup(struct h*);
void heapify(struct h*,int);
 
void main()
{
	int n,i;
	struct h last,temp;
	
	scanf("%d",&n);
	struct h heap[n];
	for(i=1;i<=n;i++)
		scanf("%d %d",&heap[i].id, &heap[i].val);
	
	//create a heap
	heap[0].id=n;
	bottomup(heap);
	
	//sorting
	while(heap[0].id > 1)
	{
		//swap heap[1] and heap[last]
		last=heap[0];
		temp=heap[1];
		heap[1]=heap[last.id];
		heap[last.id]=temp;
		heap[0].id--;
		heapify(heap,1);
	}
 
	//print sorted data
	printf("\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		printf("%d %d\n",heap[i].id, heap[i].val);
}
 
void bottomup(struct h* heap)
{
	int i;
	struct h n;
	n=heap[0]; //no. of elements
	for(i=(n.id)/2;i>=1;i--)
		heapify(heap,i);
}
 
void heapify(struct h* heap,int i)
{
	int j,flag=1;
	struct h temp;
	struct h n=heap[0];
	
	while(2*i<=n.id && flag==1)
	{
		j=2*i;	//j points to left child
		if(j+1<=n.id && heap[j+1].id > heap[j].id)
			j=j+1;
		if(heap[i].id > heap[j].id)
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}
