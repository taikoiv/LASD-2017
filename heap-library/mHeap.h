#ifndef MHEAP_H
#define MHEAP_H

typedef struct{
	int size;
	int heapsize;
	int *data;	
} heap;

int isEmpty(heap *h);
int size(heap *h);
int min(heap *h);
void insert(heap *h,int k);
void delete(heap *h,int k);
heap* buildHeap(int* data,int size);
void heapify(heap *h,int i);
void freeheap(heap *h);
void printHeap(heap *h);
void heapSort(int *data,int dim);

#endif
