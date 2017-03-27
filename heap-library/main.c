#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mHeap.h"

/* THIS FILE IS JUST AN EXAMPLE THAT EXPLAIN HOW TO USE mHeap LIBRAY */

void printMenu(); //PRINT PRIMARY MENU
heap* getRandomHeap(); //CREATE AN HEAP WITH RANDOM VALUES
heap* getHeapFromInput(); //CREATE AN HEAP WITH INPUT VALUES
void printOpMenu(); //PRINT SECONDARY MENU
void sortArray(); //CREATE AND SORT AN ARRAY FROM INPUT

void clearBuffer(){ //clear the stdin when user write an invalid input data
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { };
}

int main(int argc, char *argv[]) {
	int choice=-1,value;
	srand(time(NULL));
	heap *h=NULL;
	
	printf("Welcome to min Heap library example \n\n");
	while(choice<0 || choice>4){
		printMenu();
		scanf("%d",&choice);
		if(choice<0 || choice>4){
			clearBuffer();
			printf("NOT A VALID VALUE \n");
			system("pause");
		}
		system("cls");
	}
	
	switch(choice){
		case 0 : printf("Goodbye\n");
				 return 0;
		case 1 : h=getRandomHeap();
				 break;
		case 2 : h=getHeapFromInput();
				 break;
		case 3 : h=buildHeap(NULL,0);
				 break;
		case 4 : sortArray();
				 system("pause");
				 return 0;
	}
	
	choice=-1;
	printf("\n\nHeap is created, now let's do operations on it\n");
	system("pause");
	system("cls");
	while(choice!=0){
		printOpMenu();
		scanf("%d",&choice);
		switch(choice){
			case 0 : break;
			case 1 : printf("Enter the value to insert : ");
					 scanf("%d",&value);
					 insert(h,value);
					 break;
			case 2 : printf("Enter the value to delete : ");
					 scanf("%d",&value);
					 delete(h,value);
					 break;
			case 3 : value=-1;
					 do{
					 	printf("Press 1 to continue or 0 to cancel\n");
					 	scanf("%d",&value);
					 	clearBuffer();
					 }while(value!=0 && value!=1);
					 if(value==1){
					 	freeheap(h);
					 	printf("Heap successfully deleted\n");
					 	printf("Goodbye\n");
					 	return 0;
					 } else choice=-1;
					 break;
			case 4 : printf("Heap has %d elements \n",size(h));
					 break;
			case 5 : if(isEmpty(h))
						printf("Heap is empty\n");
					 else
					 	printf("Heap is not empty\n");
					 break;
			case 6 : printf("Min value in the heap : %d\n",min(h));
					 break;
			case 7 : printHeap(h);
					 break;
			default : printf("NOT A VALID VALUE \n");
					  clearBuffer();
		}
		if(choice!=0) system("pause");
		system("cls");
	}
	printf("Goodbye\n");
	if(h) freeheap(h);
	return 0;
}

void printMenu(){ //PRINT PRIMARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Build a random heap\n");
	printf("2) Build an heap with input values\n");
	printf("3) Build an empty heap\n");
	printf("4) Heapsort!\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

void printOpMenu(){ //PRINT SECONDARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Insert an element\n");
	printf("2) Delete element\n");
	printf("3) Delete heap\n");
	printf("4) Get heap size\n");
	printf("5) Check if heap is empty\n");
	printf("6) Get min value\n");
	printf("7) Print heap\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

heap* getRandomHeap(){ //BUILD A RANDOM HEAP WITH RANDOM DIMENSION AND VALUES
	int i,dim,*array;
	heap* h;
	dim=rand();
	array=(int *) malloc(dim*sizeof(int));
	
	for(i=0;i<dim;i++)
		array[i]=rand();
	h = buildHeap(array,dim);
	
	free(array);
	return h;
}

void sortArray(){ //GET AND ORDER AN ARRAY OF INTEGERS
	int *array=NULL;
	int i,dim=0;
	do{
		printf("What's the sequence size?\n");
		scanf("%d",&dim);
	}while(dim<0);
	
	array=malloc(dim*sizeof(int));
	for(i=0;i<dim;i++){
		printf("Element %d : ",i+1);
		scanf("%d",&array[i]);
	}
	heapSort(array,dim);
	printf("\n| ");
	for(i=0;i<dim;i++)
		printf("%d | ",array[i]);
	printf("\n");
}

heap* getHeapFromInput(){ // GET HEAP VALUES AND DIMENSION FROM STDIN
	int dim,i,*array;
	heap *h=NULL;
	dim=-1;
	
	while(dim<0){
		printf("How many elements to insert?\n");
		scanf("%d",&dim);
	}
	array=(int*)malloc(dim*sizeof(int));
	for(i=0;i<dim;i++){
		printf("Element %d ",i+1);
		scanf("%d",array+i);
	}
	
	h=buildHeap(array,dim);
	free(array);
	return h;
}
