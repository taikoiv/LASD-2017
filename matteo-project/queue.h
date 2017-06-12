#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "graph.h"

typedef struct elem{
	float priority;
	int id;
} elem;

typedef struct{
	int size; //the real size of the array used to represent the heap
	int allocated;
	elem *data;
	int *pos;
}heap;

int isEmpty(heap *h);					// IF HEAP CONTAINS 0 ELEMENTS RETURN 0 ELSE RETURN 1
int extractMin(heap *h);						// RETURN THE MINIMUM VALUE IN THE HEAP OR 0 IF HEAP IS EMPTY
void insert(heap *h,int k,float p);				// ADD k TO THE HEAP
heap *createHeap(int n);
void update(heap *h, int k, float p);
void freeheap(heap *h);
void heapSort(graph *g,float* info);
extern int HEAP_ERROR;

#endif
