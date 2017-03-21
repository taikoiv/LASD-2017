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
	int i = 0, *array;
	heap *h;
	h = (heap *)malloc(sizeof(heap));
	array = (int *)malloc(size*sizeof(int));
	h->size = h->heapsize = size;
	for(i=0; i<size; i++)
		array[i]=data[i];
	h->data = array;
	for(i = heapsize/2; i>1; i--)
		heapify(h, min);
	return h;
	
}

void heapify(heap *h, int i){
	if(!isEmpty(h)){
		int min = 0, scambio =0;
		int left = left(i);
		int right = right(i);
		if(left < h->heapsize&& h->data[left]<h->data[i])
			min = left;
		if(right < h->heapsize &&h->data[right]<h->data[min])
			min = right;
		if(min!=i){
			scambio = h->data[i];
			h->data[i] = h->data[min];
			h->data[min] = scambio;
			heapify(h, min);
		}
	}
}

void insert(heap *h, int k){
	if(h!=NULL){
		h->heapsize = h->heapsize+1;
		h->data[heapsize] = k;
		heapify(h, parent(heapsize));
	}
}

int isEmpty(heap *h){
	return (h->heapsize==0;
}
