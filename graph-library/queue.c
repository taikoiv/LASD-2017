#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int Q_ERROR=0;

void reverse(queue* q); //REVERSE QUEUE ORDER
void printQueueSub(queue* q); //SUBFUNCTION OF PRINTQUEUE

queue* newQueue(){
	queue *q=(queue*) malloc(sizeof(queue));
	q->data=calloc(1024,sizeof(int));
	q->allocated=1024;
	q->head=0;
	q->tail=0;
}

int isEmpty(queue* q){
	if(q->head==q->tail)
		return 1;
	return 0;
}

void enqueue(queue* q,int k){
	
	q->data[q->tail]=k;
	q->tail=(q->tail+1)%q->allocated;
	if(q->tail==q->head){
		int i, newDim=q->allocated*2;
		q->data=realloc(q->data,q->allocated*2);
		for(i=0;i<q->head;i++){
			q->data[(q->allocated+i)%newDim]=q->data[i];
		}
		q->allocated=newDim;
	}
}

int dequeue(queue* q){
	if(isEmpty(q)){
		Q_ERROR=-1;
		return Q_ERROR;
	}
	int ret=q->data[q->head];
	q->head=(q->head+1)%q->allocated;

	return ret;
}

void reverse(queue* q){
	int k;
	if(!isEmpty(q)){
		k=dequeue(q);
		reverse(q);
		enqueue(q,k);
	}
}

void printQueue(queue* q){
	printf("CODA :");
	if(!isEmpty(q)){
		printQueueSub(q);
		reverse(q);
	}
	printf("\n");
}

queue* randomQueue(){
	queue* q=newQueue();
	int i,n=rand()%q->allocated;
	
	for(i=0; i<n; i++){
		enqueue(q,rand());
	}
	return q;
}

void printQueueSub(queue* q){
	int k;
	if(!isEmpty(q)){
		k=dequeue(q);
		printf("%d ",k);
		printQueueSub(q);
		enqueue(q,k);
	}
}

void freeQueue(queue* q){
	free(q->data);
	free(q);
}
