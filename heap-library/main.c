#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mHeap.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printMenu();
heap* getRandomHeap();
heap* getHeapFromInput();
void printOpMenu();
void sortArray();

int main(int argc, char *argv[]) {
	int choice=-1,value;
	srand(time(NULL));
	heap *h=NULL;
	
	printf("Welcome to min Heap library example \n\n");
	while(choice<0 || choice>4){
		printMenu();
		scanf("%d",&choice);
		if(choice<0 || choice>4){
			printf("NOT A VALID VALUE \n");
			system("pause");
		}
		system("cls");
	}
	
	switch(choice){
		case 0 : printf("goodbye\n");
				 return 0;
		case 1 : h=getRandomHeap();
				 printHeap(h);
				 break;
		case 2 : h=getHeapFromInput();
				 printHeap(h);
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
			case 3 : 
					 break;
			case 4 : /* TO FIX
					 value=0;
					 printf("Are you sure?(Y or N)\n");
					 while(value!='Y' || value!='N'){
					 	scanf("%c",&value);
					 }
					 if(value=='Y') freeheap(h);*/
					 break;
			case 5 : printf("Currently heap has %d elements \n",size(h));
					 break;
			case 6 : if(isEmpty(h))
						printf("Heap is empty\n");
					 else
					 	printf("Heap is not empty\n");
					 break;
			case 7 : printf("Min value in the heap : %d\n",min(h));
					 break;
			case 8 : printHeap(h);
					 break;
			default : printf("NOT A VALID VALUE \n");
		}
		system("pause");
		system("cls");
	}
	printf("Goodbye\n");
	if(h) freeheap(h);
	return 0;
}

void printMenu(){
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

void printOpMenu(){
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

heap* getRandomHeap(){
	int i,dim,*array;
	heap* h;
	dim=rand()%30;
	array=(int *) malloc(dim*sizeof(int));
	
	for(i=0;i<dim;i++)
		array[i]=rand();
	h = buildHeap(array,dim);
	
	free(array);
	return h;
}

void sortArray(){
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

heap* getHeapFromInput(){
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
