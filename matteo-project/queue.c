#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int HEAP_ERROR=0;

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

int parent(int i){
	if(i==1) return i;
	return i/2;
}

int isEmpty(heap *h){
	return (h->data[0]==1);
}

void heapify(heap *h, int i){ //restore heap properties
	if(!isEmpty(h)){
		int min = i, scambio =0, scambiopos = 0;
		int l = left(i);
		int r = right(i);
		if(l <= size(h) && h->data[l]<h->data[i])
			min = l;
		if(r <= size(h) && h->data[r]<h->data[min])
			min = r;
		if(min!=i){
			scambio = h->data[i];
			h->data[i] = h->data[min];
			h->data[min] = scambio;
			scambiopos = h->pos[i];
			h->pos[i] = h->pos[min];
			h->pos[min] = scambiopos;
			heapify(h, min);
		}
	}
}

heap *createHeap(int n){
	heap *h = NULL;
	h = (heap *)malloc(sizeof(heap));
	if(h!=NULL){
		h->size = n;
		h->data = (int *)malloc((h->size+1)*sizeof(int));
		h->pos = (int *)malloc((h->size+1)*sizeof(int));
	}
	else{
		HEAP_ERROR = -1;
	}
	return h;
}

void insert(heap *h, int k, float f){
	if(h!=NULL){
		h->data[0]++;
		h->data[h->data[0]] = f;
		heapify(h, climbheap(h, size(h)));
	}
}


