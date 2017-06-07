#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


typedef struct{
	int size; //the real size of the array used to represent the heap
	float *data;
	int *pos;
}heap;

extern int HEAP_ERROR;

int isEmpty(heap *h);					// IF HEAP CONTAINS 0 ELEMENTS RETURN 0 ELSE RETURN 1
int extractMin(heap *h);						// RETURN THE MINIMUM VALUE IN THE HEAP OR 0 IF HEAP IS EMPTY
void insert(heap *h,int k,float p);				// ADD k TO THE HEAP
void delete(heap *h,int k);
heap *createHeap(int n);
void update(heap *h, int k, float p);
void freeheap(heap *h);


#endif
