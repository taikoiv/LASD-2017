#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int left(int i);
int right(int i);
int parent(int i);
int climbheap(queue* q, int i);
void swap(queue* q,int k,int i);
void heapify(queue *q, int i);


int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

int parent(int i){
	return i/2;
}

queue* newQueue(int n){
	int i;
	
	queue *q=(queue*)malloc(sizeof(q));
	q->pos=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		q->pos[i]=-1;
	q->heap=(queue_elem*)malloc(n*sizeof(queue_elem*));
	q->allocated=n;
	q->heapsize=0;	
}

void insertElem(queue* q,int k,float w){
	if(size(q)<q->allocated){
		q->heap[q->heapsize].k=k;
		q->heap[q->heapsize].weight=w;
		q->pos[k]=q->heapsize;
		q->heapsize++;
	}
}

int climbheap(queue* q, int i) { //swap element with his parent until is possible
	if (i!=0 && q->heap[i].weight < q->heap[parent(i)].weight) {
		swap(q,i,parent(i));
		return climbheap(q, parent(i));
	}else{
		return i;
	}
}

void swap(queue* q,int k,int i){
		int t=q->pos[q->heap[k].k];
		q->pos[q->heap[k].k]=q->pos[q->heap[i].k];
		q->pos[q->heap[i].k]=t;
		
		queue_elem temp = q->heap[k];
		q->heap[k] = q->heap[i];
		q->heap[i] = temp;
}

int extract(queue* q){
	int ret=-1;
	if(!isEmpty(q)){
		q->heapsize--;
		ret=q->heap[0].k;
		q->pos[ret]=-1;
		q->heap[0]=q->heap[q->heapsize];
		heapify(q,0);
	}
	return ret;
}

void heapify(queue *q, int i){ //restore heap properties
	if(!isEmpty(q)){
		int min = i;
		int l = left(i);
		int r = right(i);
		if(l < size(q) && q->heap[l].weight<q->heap[min].weight)
			min = l;
		if(r < size(q) && q->heap[r].weight<q->heap[min].weight)
			min = r;
		if(min!=i){
			swap(q,i,min);
			heapify(q, min);
		}
	}
}

int isEmpty(queue* q){
	return q->heapsize<=0;
}

int size(queue* q){
	return q->heapsize;
}

void updateElem(queue* q,int k,float w){
		int oldWeight=q->heap[q->pos[k]].weight;
		q->heap[q->pos[k]].weight=w;
		if(w>oldWeight){
			heapify(q,q->pos[k]);
		}
		else{
			climbheap(q,q->pos[k]);
		}
	}
}

void freeQueue(queue* q){
	free(q->heap);
	free(q->pos);
	free(q);
}

void printQueue(queue* q){
	if(q!=NULL && !isEmpty(q)){
		int i=0;
		for(i=0;i<q->heapsize;i++)
			printf(" POS %d -> nodo %d , peso %f",i,q->heap[i].k,q->heap[i].weight);
	}
}
