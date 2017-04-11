#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

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
	stack *s = NULL;
	s = newStack();
	for(; i<n; i++){
		scanf("%d", &val);
	    push(s, val);
	}
	return q;
}
		

int main(int argc, char *argv[]) {
	int choice=-1, value;
	int element, n;
	srand(time(NULL));
	stack *s = NULL;

	printf("Welcome to stack library example \n\n");
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
		case 1 : q = newStack();
			break;
		case 2 : 
				 printf("How many elements do you wish to insert?\n");
				 scanf("%d", &n);
				 s = createFromInput(n);
			break;
		case 3 : s = randomStack();
			break;
	}
	choice=-1;
	printf("\n\nYour stack is created, now let's do operations on it\n");
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
				push(s,value);
				break;
			case 2 : element = pull(s);
					 system(CLS);
					 printf("%d\n", element);
					 break;
			case 3: value=-1;
				do{
					printf("Press 1 to continue or 0 to cancel\n");
					scanf("%d",&value);
					clearBuffer();
				}while(value!=0 && value!=1);
				if(value==1){
					free(s);
					printf("Stack successfully deleted\n");
					printf("Goodbye\n");
					return 0;
				} else choice=-1;
				break;
			case 4 : if(isEmpty(s))
					printf("Stack is empty\n");
				else
					printf("Stack is not empty\n");
				break;
			case 5 : printQueue(s);
				break;
			default : printf("NOT A VALID VALUE \n");
				clearBuffer();
		}
        if(S_ERROR==-2){
            printf("Error: Queue is full, you can't add any more elements\n");
            Q_ERROR=0;
            system(PAUSE);
            system(CLS);
        }else if (S_ERROR==-1){
        	printf("Error: Stack is empty, you can't extract any more elements\n");
            S_ERROR=0;
            system(PAUSE);
            system(CLS);
		}else {
            if (choice != 0) system(PAUSE);
            system(CLS);
        }
	}
	printf("Goodbye\n");
	if(s)
		free(s);
	return 0;
}

void printMenu(){ //PRINT PRIMARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Build an empty stack\n");
    printf("2) Build a stack with elements given in input\n");
    printf("3) Build a stack with random elements\n");
    printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

void printOpMenu(){ //PRINT SECONDARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Insert an element\n");
	printf("2) Extract an element\n");
	printf("3) Delete stack\n");
	printf("4) Check if stack is empty\n");
	printf("5) Print stack\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

