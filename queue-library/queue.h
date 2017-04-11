#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

typedef struct {
  int head;
  int tail;
  int data[MAX];
  //int *data for dynamic method
} queue;

extern int Q_ERROR;//CONTAINS AN ERROR CODE
/*
  ERROR CODES:
    -1 : EMPTY QUEUE (IT IS NOT POSSIBLE TO DEQUEUE)
    -2 : FULL QUEUE (IT IS NOT POSSIBLE TO ENQUEUE)
*/

queue* newQueue(); //INITIALIZE A QUEUE
int isEmpty(queue* q); //CHECK IF QUEUE IS EMPTY (RETURN 0 IF NOT, ELSE 1)
void enqueue(queue* q,int k); //ADD AN ELEMENT IN THE QUEUE
int dequeue(queue* q); //EXTRACT AN ELEMENT FROM THE QUEUE
void printQueue(queue* q); //PRINT THE QUEUE
queue* randomQueue(); //CREATE A QUEUE WITH RANDOM VALUES

#endif
