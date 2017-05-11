#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"

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
int ABRERROR;
void printMenu(); //PRINT PRIMARY MENU
void printOpMenu(); //PRINT SECONDARY MENU

void clearBuffer(){ //clear the stdin when user write an invalid input data
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { };
}

int main(int argc, char *argv[]) {
	int choice=-1,value;
	int min;
	tree *g = NULL;
	srand(time(NULL));
	tree *h=NULL;

	printf("Welcome to ABR library example \n\n");
	while(choice<0 || choice>4){
		printMenu();
		scanf("%d",&choice);
		if(choice<0 || choice>4){
			clearBuffer();
			printf("NOT A VALID VALUE \n");
			system(PAUSE);
		}
		system(CLS);
	}

	switch(choice){
		case 0 : printf("Goodbye\n");
			return 0;
		case 1 : h=newRandomBst(rand());
			break;
		case 2 : h=newRandomTree(rand());
			break;
		default:
			break;
	}
	choice=-1;
	printf("\n\nAn ABR is created, now let's do operations on it\n");
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
				insertNode(h,value);
				break;
			case 2 : printf("Enter the value to delete : ");
				scanf("%d",&value);
				clearBuffer();
				deleteNode(h,value);
				break;
			case 3 : value=-1;
				do{
					printf("Press 1 to continue or 0 to cancel\n");
					scanf("%d",&value);
					clearBuffer();
				}while(value!=0 && value!=1);
				if(value==1){
					freeBST(h);
					printf("tree successfully deleted\n");
					printf("Goodbye\n");
					return 0;
				} else choice=-1;
				break;
			case 4 : balanceBst(h);
				printf("tree successfully balanced\n");
				break;
			case 5 : 
				g = newRandomBst(rand());
				printf("New tree successfully Created\n");
				printBst(g);
				h = merge(g,h);
				printf("trees  successfully merged\n");
				printBst(h);
				break;
			case 6 :
				printBst(h);
				break;
			case 7 :
				printf("PreOrder view : \n");
				preOrder(h);
				break;
			case 9 :
				printf("InOrder view : \n");
				inOrder(h);
				break;
			case 8 :
				printf("PostOrder view : \n");
				postOrder(h);
				break;
			case 10 :	
				value=-1;
				do{
					printf("How many rotation?\n");
					scanf("%d",&value);
					clearBuffer();
				}while(value<=0);
				int dir = -1;
				do{
					printf("Press 1 to rotate right or 0 to left\n");
					scanf("%d",&dir);
					clearBuffer();
				}while(dir!=0 && dir!=1);
				printf("trees  successfully rotated\n");
				rotation(h,value,dir);
				break;
			default : printf("NOT A VALID VALUE \n");
				clearBuffer();
		}
		if (choice != 0) system(PAUSE);
		system(CLS);
	}
	printf("Goodbye\n");
	if(h) freeBST(h);
	return 0;
}

void printMenu(){ //PRINT PRIMARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Build a tableau with random values (wihtout duplicates)\n");
	printf("2) Build a tableau with random values\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

void printOpMenu(){ //PRINT SECONDARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Insert an element\n");
	printf("2) Delete an element\n");
	printf("3) Delete tree\n");
	printf("4) Balance tree\n");
	printf("5) Merge trees\n");
	printf("6) Print tree\n");
	printf("7) PreOrder Print\n");
	printf("8) PostOrder Print\n");
	printf("9) InOrder Print\n");
	printf("10) Rotate Tree\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

