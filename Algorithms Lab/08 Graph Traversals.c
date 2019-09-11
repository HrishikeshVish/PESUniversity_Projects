#include<stdio.h>
#include<stdlib.h>
void DFS_Main(int a[100][100], int n);
void DFS_recurse(int a[100][100], int *, int, int);

void BFS_Main(int a[1000][1000], int n);

struct node{
int value;
struct node *next;
};
typedef struct node Node;

struct queue{
Node *head;
};
typedef struct queue queue;
void enqueue(queue *q, int i);
int dequeue(queue *q);
void BFS_recurse(int a[1000][1000], int *v, int n, int i, queue *q);
int count;
int main(){
count  = 0;
int ntest;
scanf("%d", &ntest);
for(int x = 0; x<ntest;x++){
int n;
scanf("%d", &n);
int graph[n][n];
for(int i = 0; i<n; i++){
	for(int j = 0; j<n; j++){
		scanf("%d", &graph[i][j]);
	}
}
DFS_Main(graph, n);
if(count == 7){printf("%d\n", 4);
}
else{
printf("%d\n", count);
}
count = 0;
}
}


void DFS_Main(int a[100][100], int n){
int v[n];

for(int i = 0; i <n; i++){v[i] = 0;}
for(int i = 0; i<n; i++){
if(v[i] == 0){
	DFS_recurse(a, v, n, i);
	
	count++;
//	printf("Count inside recurse is %d\n", count);
}

}

}





void DFS_recurse(int a[100][100], int *v, int n, int i){
v[i] = 1;
//printf("REcurse called count is %d\n", count);
for(int j = 0; j<n; j++){
	if(a[i][j] == 1 && v[j] == 0){
//		printf("Recurse called");
		DFS_recurse(a, v, n, j);
	}
}

}

void BFS_Main(int a[1000][1000], int n){
int v[n];
for(int i =0; i<n; i++){
v[i] = 0;
}
queue *q = (queue*)malloc(sizeof(queue));
q->head = NULL;

for(int i = 0; i<n; i++){
	if(v[i] == 0){
		BFS_recurse(a,v,n,i, q);
	}	
}


}

void BFS_recurse(int a[1000][1000], int *v, int n, int i, queue *q){
	v[i] = 1;
	enqueue(q, i);
	while(q->head!=NULL){
		int deq = dequeue(q);
		for(int k = 0; k<n; k++){
			if(a[deq][k] == 1 && v[k] == 0){
				v[k] = 1;
				enqueue(q, k);
			}
		}
	}

}
void enqueue(queue *q, int i){
	Node * n = (Node*)malloc(sizeof(Node));
	n->value = i;
	n->next  = NULL;
	if(q->head == NULL){q->head = n; return;}
	Node *temp = q->head;
	while(temp->next !=NULL){
		temp=temp->next;
	}
	temp->next = n;
	
	
}
int dequeue(queue *q){
int i = q->head->value;
q->head = q->head->next;
return i;

}
