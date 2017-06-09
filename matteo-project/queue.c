#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int HEAP_ERROR=0;

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

int parent(int i){
	return i/2;
}

int isEmpty(heap *h){
	return (h->size<0);
}

void swap(heap *h, int s, int t){
	if(h!=NULL){
		float temp;
		int sw = 0;
		temp = h->data[s].priority;
		h->data[s].priority = h->data[t].priority;
		h->data[t].priority = temp;
		sw = h->pos[h->data[s].id];
		h->pos[h->data[s].id] = h->pos[h->data[t].id];
		h->pos[h->data[t].id] = sw;
		sw=h->data[s].id;
		h->data[s].id=h->data[t].id;
		h->data[t].id=sw;
	}
}

void heapify(heap *h, int i){ //restore heap properties
	if(!isEmpty(h)){
		int min = i;
		int l = left(i);
		int r = right(i);
		if(l <= h->size && h->data[l].priority<h->data[i].priority)
			min = l;
		if(r <= h->size && h->data[r].priority<h->data[min].priority)
			min = r;
		if(min!=i){
			swap(h, i, min);
			heapify(h, min);
		}
	}
}

heap *createHeap(int n){
	heap *h = NULL;
	h = (heap *)malloc(sizeof(heap));
	if(h!=NULL){
		h->size = -1;
		h->allocated = n-1;
		h->data = (elem *)malloc((n)*sizeof(elem));
		h->pos = (int *)malloc((n)*sizeof(int));
		
	}
	else{
		HEAP_ERROR = -1;
	}
	return h;
}

int climbheap(heap *h, int i) { //swap element with his parent until is possible
	if (i>=0 && h->data[i].priority < h->data[parent(i)].priority) {
		swap(h, i, parent(i));
		return climbheap(h, parent(i));
	}else{
		return i;
	}
}

void insert(heap *h, int k, float f){
	if(h!=NULL){
		h->size++;
		h->data[h->size].priority = f;
		h->data[h->size].id = k;
		h->pos[k] = h->size;
		climbheap(h, h->size);
	}
}



int extractMin(heap *h){
	int ret = -1;
	if(!isEmpty(h)){
		ret = h->data[0].id;
		swap(h, 0, h->size);
		h->pos[h->data[h->size].id] = -1;
		h->size--;
		heapify(h, 0);
	}
	return ret;
}

void update(heap *h, int k, float p){
	if(h!=NULL){
		float temp = h->data[h->pos[k]].priority;
		h->data[h->pos[k]].priority = p;
		if(temp > p)
			climbheap(h, h->pos[k]);
		else
			heapify(h, h->pos[k]);
	}else{
		HEAP_ERROR = -2;
	}
}

void freeheap(heap *h){
	if(h!=NULL){
		if(h->pos!=NULL)free(h->pos);
		if(h->data!=NULL)free(h->data);
		free(h);
	}
}

void *heapSort(graph *g,float* info){
	heap *h=NULL;
	if(g!=NULL){
		h = createHeap(g->n);
		int i=0;
		for(; i<g->n; i++)
			insert(h, i, g->nodes[i].height);
		i=0;
		while(!isEmpty(h)){
			info[i]=h->data[0].priority;
			i++;
			extractMin(h);
		}
		freeheap(h);
	}
}
