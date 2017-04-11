#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef struct {
  int head,tail;
  int *data;
} queue;

queue* newQueue();
int isEmpty(queue* q);
void enqueue(queue* q,int k);
int dequeue(queue* q);
void printQueue(queue* q);
queue* randomQueue();

#endif
