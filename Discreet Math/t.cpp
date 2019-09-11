#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

struct queue{
	node *head;
};

typedef struct queue queue;

void enqueue(queue *q, int);
void  display(queue *q);


int main(){
	
	queue * q = (queue*)malloc(sizeof(queue));
	q->head = NULL;
	int a;scanf("%d", &a);
	enqueue(q,a);
	display(q);
}

void enqueue(queue*q, int a){
	int i;
	for(i=1;i<=a;i++){
		node *n = (node *)malloc(sizeof(node));
		n->data = i;
		if(q->head == NULL){
			q->head = n;
			q->head->next = NULL;
		}
		
		else{
			node *t = q->head;
			while(t->next!=NULL){
				t = t ->next;
			}
			t->next = n;
			t->next->next = NULL;
		}
		if(i==a){
		
			n->next = q->head;
		}
		
	}
	
}

void display(queue *q){
	
	if(q->head == NULL){
		return;
	}
	
	if(q->head->data == q->head->next->data){
		return;
	}
	
	node *t = q->head;
	node *prev = t;
	
	while(t!=NULL){
		

		
		printf("%d ", t->next->data);
		prev = t->next;
		
		t->next = t->next->next;
		free(prev);
		t = t->next;
		
		
	
	if(t->data == t->next->data){
			printf("NINE\n");
			return;
		}		

		
	}
	

}
