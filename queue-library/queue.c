#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int Q_ERROR=0;

void reverse(queue* q); //REVERSE QUEUE ORDER
void printQueueSub(queue* q); //SUBFUNCTION OF PRINTQUEUE

queue* newQueue(){
	queue *q=(queue*) malloc(sizeof(queue));
	q->head=0;
	q->tail=1;
}

int isEmpty(queue* q){
	if(q->head==0)
		return 1;
	return 0;
}

void enqueue(queue* q,int k){
	if(q->head==q->tail){
		Q_ERROR=-2;
		return;
	}
	q->data[q->tail]=k;
	if(q->head==0)
		q->head=1;
	q->tail=(q->tail%MAX)+1;
}

int dequeue(queue* q){
	int ret=q->data[q->head];
	
	if(isEmpty(q)){
		Q_ERROR=-1;
		return Q_ERROR;
	}
	q->head=(q->head%MAX)+1;
	if(q->head==q->tail){
		q->head=0;
		q->tail=1;
	}
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
	int i,n=rand()%MAX;
	
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
