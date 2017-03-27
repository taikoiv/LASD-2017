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
	if(i==1) return i;
	return i/2;
}

int climbheap(heap *h, int i) { //swap element with his parent until is possible
	int temp;
	if (i!=1 && h->data[i] < h->data[parent(i)]) {
		temp = h->data[i];
		h->data[i] = h->data[parent(i)];
		h->data[parent(i)] = temp;
		return climbheap(h, parent(i));
	}else{
		return i;
	}
}

void heapify(heap *h, int i){ //restore heap properties
	if(!isEmpty(h)){
		int min = i, scambio =0;
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
			heapify(h, min);
		}
	}
}

heap* buildHeap(int* data,int dim){ 
	int i = 0, *array;
	heap *h;
	h = (heap *)malloc(sizeof(heap));
	array = (int *)malloc((dim+1)*sizeof(int));
	h->data = array;
	h->size = dim;
	h->data[0] = dim;
	for(i=1; i<=dim; i++)
		array[i]=data[i-1];
	h->data = array;
	for(i = size(h)/2; i>=1; i--){
		heapify(h, i);
	 }
	return h;
}

void insert(heap *h, int k){
	if(h!=NULL){
		if(h->data[0]==h->size){
			int *array, i, *temp;
			array = (int *)malloc(h->size*2*sizeof(int));
			for(i=0; i<=h->size; i++)
				array[i]=h->data[i];
			temp = h->data;
			h->data=array;
			free(temp);
			h->size = (h->size)*2;
		}
		h->data[0]++;
		h->data[size(h)] = k;
		heapify(h, climbheap(h, size(h)));
	}
}

int isEmpty(heap *h){
	return (size(h)==0);
}


int min(heap *h){
	if(!isEmpty(h))
		return h->data[1];
	return 0;
}

void delete(heap *h,int k){
	int i = 1;
	int temp;
	while(i<=size(h) && h->data[i]!=k){
		i++;
	}
	if(i <= size(h)){
		temp = h->data[i];
		h->data[i] = h->data[size(h)];
		h->data[size(h)] = temp;
		h->data[0]--;
		if(h->data[0]==h->size/3){
			h->size=2*size(h)+1;
			h->data = (int*)realloc(h->data,(2*size(h)+1)*sizeof(int));
		}
		int newpos = climbheap(h,i);
		heapify(h,newpos);
	}
}

void freeheap(heap *h){
	free(h->data);
	free(h);
}

int size(heap *h){
	return h->data[0];
}

void printHeap(heap *h){
	int i;
	int dim=size(h);
	if(dim==0){
		printf("HEAP IS EMPTY!\n");
		return;
	}
	printf("\nHeap values :\n |");
	for(i=1;i<=dim;i++)
		printf(" %d |",h->data[i]);
	printf("\n");
}

void heapSort(int *data, int dim){
	heap *h=buildHeap(data,dim);
	int i,temp;
	
	for(i=size(h);i>1;i--){
		data[i-1]=min(h);
		
		temp=h->data[size(h)];
		h->data[size(h)]=h->data[1];
		h->data[1]=temp;
		h->data[0]--;
		
		heapify(h,1);
	}
	data[0]=h->data[1];
}
