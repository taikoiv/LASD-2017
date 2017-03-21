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
void heapSort(heap *h);
void heapify(heap *h,int i);


#endif
