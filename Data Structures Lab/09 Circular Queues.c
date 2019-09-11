#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int front;
	int rear;
	int capacity;
	int *array;
	}circular;


circular* create(int size);
int qfull(circular*q);
int qempty(circular*q);
void enqueue(circular *q,int data);
void dequeue(circular *q);
void dis(circular*q);
int main()
{
	int n,data;
	scanf("%d",&n);
	circular*q=create(n);
	int choice;
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:scanf("%d",&data);
				enqueue(q,data);
				break;
			case 1:dequeue(q);
				break;
			case 2:	dis(q);
				printf("\n");
				break;
			default:
				exit(0);
		}
	}



}

circular* create(int size)
{
	circular*q=(circular*)malloc(sizeof(circular));
	q->array=(int*)malloc(sizeof(int)*size);
	q->front=-1;
	q->rear=-1;
	q->capacity=size;
	return q;
}


int qfull(circular*q)
{
	if((q->front==q->rear+1) ||((q->front==0)&&(q->rear==q->capacity-1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int qempty(circular*q)
{
	if(q->front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(circular *q,int data)
{
	if(qfull(q)!=1)
	{
		if(q->front==-1)
		{
			q->front=q->front+1;
		}
		q->rear=(q->rear+1)%(q->capacity);
		q->array[q->rear]=data;
		//printf("%d\n",q->array[q->rear]);

		
	}
	else
	{
		puts("overflow");
	}
}

void dequeue(circular *q)
{
	if(qempty(q))
	{
		puts("underflow");
	}
	else if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
	{
		q->front=(q->front+1)%q->capacity;
	}
}

void dis(circular*q)
{
	if(qempty(q)==1)
	{
		puts("empty");
	}

	else
	{
		//printf("%d\n",q->rear);
		for(int i=q->front;i!=q->rear;i=(i+1)%(q->capacity))
		{
			//printf(" i value %d \n",i);

			printf("%d ",q->array[i]);
		}
		printf("%d",q->array[q->rear]);
	}
}

