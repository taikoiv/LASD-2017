#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mHeap.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printMenu();
heap* getRandomHeap();

int main(int argc, char *argv[]) {
	int choice=-1;
	srand(time(NULL));
	heap *h=NULL;
	
	printf("Welcome to min Heap library example \n");
	while(choice<0 || choice>3){
		printMenu();
		scanf("%d",&choice);
		if(choice<0 || choice>3){
			printf("NOT A VALID VALUE \n");
			system("pause");
		}
		system("cls");
	}
	
	switch(choice){
		case 0 : return 0;
		case 1 : h=getRandomHeap();
				 printHeap(h);
				 break;
		case 2 : 
				 break;
		case 3 : 
				 break;
	}
	return 0;
}

void printMenu(){
	printf("ENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Build a random heap\n");
	printf("2) Build an heap with input values\n");
	printf("3) Build an empty heap\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

heap* getRandomHeap(){
	int i;
	int dim=rand()%30;
	int *array=(int *) malloc(dim*sizeof(int));
	
	for(i=0;i<dim;i++)
		array[i]=rand();
		
	return buildHeap(array,dim);
}
