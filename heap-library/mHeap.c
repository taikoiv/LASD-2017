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


int min(heap *h){
	return h->data[0];
}

void delete(heap *h,int k){
	int i = 0;
	while(i<h->heapsize && h->data[i]!=k){
		i++;
	}
	if(i < h->heapsize){
		
		temp = h->data[i];
		h->data[i] = h->data[h->heapsize-1];
		h->data[h->heapsize-1] = temp;
		
		if(i<(h->heapsize/2)){
			while(h->data[parent(i)] > h->data[i] && i>0){
			
			}
		}else{
			
		}
	}
}

void freeheap(heap *h){
	free(h->data);
	free(h);
}
int size(heap *h){
	return h->heapsize;
}
