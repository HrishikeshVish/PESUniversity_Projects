#include<stdio.h>
#include<stdlib.h>
struct heap{
	int size;
	int capacity;
	int *elements;
};

typedef struct heap heap;

heap *con(int init){
	
	heap * h = (heap*)malloc(sizeof(heap));
	h->size = 0;
	h->capacity = init;
	h->elements = (int*)malloc(sizeof(int)*(init+2));
	return h;
}

int parent(int i){
	return ((i-1)/2);
}

int left(int i ){
	return (2*i + 1)	;
}

int right(int i){
	return (2*i + 2);
}

int ins(heap*heap, int data){
	if(heap->size == heap->capacity){
		return 0;
	}
	
	heap->elements[heap->size] = data;
	int z = heap->size;
	(heap->size)++;
	
	if(z == 0){
		return 1;
	}
	else{
		while(z!=0 && (heap->elements[parent(z)] > heap->elements[z])){
			int s = heap->elements[z];
			heap->elements[z] = heap->elements[parent(z)];
			heap->elements[parent(z)] = s;
			z = parent(z);
		}
	}
	return 1;
}

int heapify(heap *heap, int i){
	
	int l = left(i);
	int r = right(i);
	int smallest  = i;
	if(l<heap->size && heap->elements[i]>heap->elements[l]){
		smallest = l;
	}
	if(r<heap->size && heap->elements[i]>heap->elements[r]){
		smallest = r;
	}
	if(smallest !=i){
		int z = heap->elements[i];
		heap->elements[i] = heap->elements[smallest];
		heap->elements[smallest] = z;
	
		heapify(heap, smallest);
	}
}

void print(heap *heap){
	int i;
	for(i=0;i<heap->size;i++){
		printf("%d ", heap->elements[i]);
	}
}

int main(){
	int i;
	heap *heap = con(9);
	for (i=10;i>1;i--){
		ins(heap, i);
	}
	print(heap);
}

