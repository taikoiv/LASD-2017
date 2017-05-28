#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct queue_elem{
	int k;
	int weight;
} queue_elem;

typedef struct queue{
	int allocated;
	int heapsize;
	queue_elem *heap;
	int *pos;
} queue;

queue* newQueue(int n);
void insertElem(queue* q,int k,int w);
int extract(queue* q);
void updateElem(queue* q,int k,int w);
void freeQueue(queue* q);
#endif
