#include <stdio.h>
#include <stdlib.h>

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

int parent(int i){
	return i/2;
}

heap* buildHeap(int* data,int size){
	heap *h;
	h = (heap *)malloc(sizeof(heap));
	h->data = data;
	h->size = h->heapsize = size;
	
	
}



void heapify(heap *h, int i){
	
	
}


void insert(heap *h,int k){
	
}


int isEmpty(heap *h){
	
}
