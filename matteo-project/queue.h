#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct queue_elem{
	int k;
	float weight;
} queue_elem;

typedef struct queue{
	int allocated;
	int heapsize;
	queue_elem *heap;
	int *pos;
} queue;

queue* newQueue(int n);
void insertElem(queue* q,int k,float w);
int extract(queue* q);
void updateElem(queue* q,int k,float w);
void freeQueue(queue* q);
int isEmpty(queue* q);
int size(queue* q);
void printQueue(queue* q);

#endif
