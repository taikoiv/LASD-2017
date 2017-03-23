#ifndef MHEAP_H
#define MHEAP_H

typedef struct{
	int size;
	int *data;	
} heap;

int isEmpty(heap *h);
int size(heap *h);
int min(heap *h);
void insert(heap *h,int k);
void delete(heap *h,int k);
heap* buildHeap(int* data,int dim);
void heapSort(int *data, int dim);
void freeheap(heap *h);
void printHeap(heap *h);

#endif
