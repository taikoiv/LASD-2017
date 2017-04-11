#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define EMPTY 0
#define AUTOINS 1

#ifdef _WIN32
#define CLS "cls"
#define PAUSE "pause"
#else
#define CLS "clear"
#define PAUSE "echo 'Press enter to continue...' && read "
#endif

/* THIS FILE IS JUST AN EXAMPLE THAT EXPLAIN HOW TO USE mHeap LIBRAY */
void printMenu(); //PRINT PRIMARY MENU
void printOpMenu(); //PRINT SECONDARY MENU

void clearBuffer(){ //clear the stdin when user write an invalid input data
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { };
}

queue *createFromInput(int n){
	int i = 0, val = 0;
	queue *q = NULL;
	q = newQueue();
	for(; i<n; i++){
		scanf("%d", &val);
	    enqueue(q, val);
	}
	return q;
}
		

int main(int argc, char *argv[]) {
	int choice=-1,value;
	int min, n;
	srand(time(NULL));
	queue *q = NULL;

	printf("Welcome to min Tableau library example \n\n");
	while(choice<0 || choice>3){
		printMenu();
		scanf("%d",&choice);
		if(choice<0 || choice>3){
			clearBuffer();
			printf("NOT A VALID VALUE \n");
			system(PAUSE);
		}
		system(CLS);
	}

	switch(choice){
		case 0 : printf("Goodbye\n");
			return 0;
		case 1 : q = newQueue();
			break;
		case 2 : 
				 printf("How many elements do you wish to insert?\n");
				 scanf("%d", &n);
				 q = createFromInput(n);
			break;
		case 3 : q = randomQueue();
			break;
	}
	choice=-1;
	printf("\n\nYour queue is created, now let's do operations on it\n");
	system(PAUSE);
	system(CLS);
	while(choice!=0){
		printOpMenu();
		scanf("%d",&choice);
		switch(choice){
			case 0 : break;
			case 1 : printf("Enter the value to insert : ");
				scanf("%d",&value);
                clearBuffer();
				enqueue(q,value);
				break;
			case 2 : value=-1;
				do{
					printf("Press 1 to continue or 0 to cancel\n");
					scanf("%d",&value);
					clearBuffer();
				}while(value!=0 && value!=1);
				if(value==1){
					free(q);
					printf("Queue successfully deleted\n");
					printf("Goodbye\n");
					return 0;
				} else choice=-1;
				break;
			case 3 : if(isEmpty(q))
					printf("Queue is empty\n");
				else
					printf("Queue is not empty\n");
				break;
			case 4 : printQueue(q);
				break;
			default : printf("NOT A VALID VALUE \n");
				clearBuffer();
		}
        /*if(Q_ERROR==-1){
            printf("Error: Queue is full, you can't add any more elements\n");
            Q_ERROR=0;
            system(PAUSE);
            system(CLS);
        }else {
            if (choice != 0) system(PAUSE);
            system(CLS);
        }*/
	}
	printf("Goodbye\n");
	if(q)
		free(q);
	return 0;
}

void printMenu(){ //PRINT PRIMARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Build an empty queue\n");
    printf("2) Build a queue with elements given in input\n");
    printf("3) Build a queue with random elements\n");
    printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

void printOpMenu(){ //PRINT SECONDARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Insert an element\n");
	printf("2) Delete tableau\n");
	printf("3) Check if tableau is empty\n");
	printf("4) Print tableau\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

