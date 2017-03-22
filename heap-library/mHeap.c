#include <stdio.h>
#include <stdlib.h>
#include "mHeap.h"

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

int parent(int i){
	return i/2;
}

int climbheap(heap *h, int i) {
	int temp;
	if (h->data[i] > h->data[parent(i)]) {
		temp = h->data[i];
		h->data[i] = h->data[parent(i)];
		h->data[parent(i)] = temp;
		return climbheap(h, parent(i));
	}else{
		return i;
	}
}

heap* buildHeap(int* data,int size){ 
	int i = 0, *array;
	heap *h;
	h = (heap *)malloc(sizeof(heap));
	array = (int *)malloc(size*sizeof(int));
	h->data = array;
	h->size = h->heapsize = size;
	for(i=0; i<size; i++)
		array[i]=data[i];
	h->data = array;
	for(i = h->heapsize/2; i>=0; i--){
		heapify(h, i);
	 }
	return h;
}

void heapify(heap *h, int i){
	if(!isEmpty(h)){
		int min = i, scambio =0;
		int l = left(i);
		int r = right(i);
		if(l < h->heapsize&& h->data[l]<h->data[i])
			min = l;
		if(r < h->heapsize &&h->data[r]<h->data[min])
			min = r;
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
		h->data[h->heapsize] = k;
		heapify(h, parent(h->heapsize));
	}
}

int isEmpty(heap *h){
	return (h->heapsize==0);
}


int min(heap *h){
	return h->data[0];
}

void delete(heap *h,int k){
	int i = 0;
	int temp;
	while(i<h->heapsize && h->data[i]!=k){
		i++;
	}
	if(i < h->heapsize){
		temp = h->data[i];
		h->data[i] = h->data[h->heapsize-1];
		h->data[h->heapsize-1] = temp;
		h->heapsize = h->heapsize-1;
		h->data = (int*)realloc(h->data,h->heapsize*sizeof(int)); //SECONDO ME FA SCHIFO
		int newpos = climbheap(h,i);
		heapify(h,newpos);
	}
	/*
	secondo il teorema di un tizio francese la giusta proporzione per il resize durante la cancellazione � quando :
	1/3 dell'array � pieno e 2/3 vuoti => deallocare 1/3 vuoto.
	in questo modo per ogni resize di ha SEMPRE la met� dell'array pieno e l'altra vuota.
	*/
}

void freeheap(heap *h){
	free(h->data);
	free(h);
}

int size(heap *h){
	return h->heapsize;
}

void printHeap(heap *h){
	int i;
	int dim=size(h);
	printf("\nHeap values :\n |");
	for(i=0;i<dim;i++)
		printf(" %d |",h->data[i]);
	printf("\n");
}

void heapSort(int *data,int dim){
	heap *h=buildHeap(data,dim);
	int i=size(h)-1,temp;
	for(;i>0;i--){
		printf("%d \n",min(h));
		data[i]=min(h);
		
		temp=h->data[h->heapsize-1];
		h->data[h->heapsize-1]=h->data[0];
		h->data[0]=temp;
		
		h->heapsize=h->heapsize-1;
		heapify(h,0);
	}
	data[0]=h->data[0];
	
	freeheap(h);
}
