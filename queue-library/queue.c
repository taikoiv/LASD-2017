#include <stdlib.h>
#include "queue.h"

int Q_ERROR=0;

void reverse(queue* q); //REVERSE QUEUE ORDER

queue* newQueue(){
	queue *q=(queue*) malloc(sizeof(queue));
	q->head=0;
	q->tail=1;
}

int isEmpty(queue* q){
	if(head==0)
		return 1;
	return 0;
}

void enqueue(queue* q,int k){
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
	while(!isEmpty(q)){
		k=dequeue(q);
		reverse(q);
		enqueue(e,k);
	}
}

void printQueue(queue* q){
	int k;
	printf("QUEUE :");
	while(!isEmpty(q)){
		k=dequeue(q);
		printf(" %d",k);
		enqueue(q,k);
	}
	printf("\n");
	reverse(q);
}

queue* randomQueue(){
	queue* q=newQueue();
	int i;
	for(i=0;i<rand()%MAX){
		enqueue(q,rand());
	}
	return q;
}
