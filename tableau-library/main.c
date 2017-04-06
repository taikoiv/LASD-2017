#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableau.h"

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
int TABLERROR;
void printMenu(); //PRINT PRIMARY MENU
tableau* getTabFromInput(int mode); //CREATE AN HEAP WITH INPUT VALUES
tableau* getTabFromRandomVal(); //CREATE AN HEAP WITH RANDOM VALUES
void printOpMenu(); //PRINT SECONDARY MENU
void sortArray(); //CREATE AND SORT AN ARRAY FROM INPUT

void clearBuffer(){ //clear the stdin when user write an invalid input data
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { };
}

int main(int argc, char *argv[]) {
	int choice=-1,value;
	int min;
	srand(time(NULL));
	tableau *h=NULL;

	printf("Welcome to min Tableau library example \n\n");
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
		case 1 : h=getTabFromInput(1);
			break;
		case 2 : h=getTabFromInput(0);
			break;
		case 3 : h=getTabFromRandomVal();
			break;
        case 4 :sortArray();
            system(PAUSE);
            return 0;
			break;
		default:
			break;
	}
	choice=-1;
	printf("\n\nTableau is created, now let's do operations on it\n");
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
				insert(h,value);
				break;
			case 2 : value=-1;
				do{
					printf("Press 1 to continue or 0 to cancel\n");
					scanf("%d",&value);
					clearBuffer();
				}while(value!=0 && value!=1);
				if(value==1){
					freetableau(h);
					printf("Tableau successfully deleted\n");
					printf("Goodbye\n");
					return 0;
				} else choice=-1;
				break;
			case 3 : printf("Tableau has %d elements \n",size(h));
				break;
			case 4 : if(isEmpty(h))
					printf("Tableau is empty\n");
				else
					printf("Tableau is not empty\n");
				break;
			case 5 : 
					min = extractMin(h);
					if(TABLERROR==-2){
					 	printf("Error: Tableau is empty, you can't extact any more elements\n");
					}else{
						printf("Min value in the tableau : %d\n",min);
					}			
				break;
			case 6 : printTableau(h);
				break;
			default : printf("NOT A VALID VALUE \n");
				clearBuffer();
		}
        if(TABLERROR==-1){
            printf("Error: Tableau is full, you can't add any more elements\n");
            system(PAUSE);
            system(CLS);
        }else {
            if (choice != 0) system(PAUSE);
            system(CLS);
        }
	}
	printf("Goodbye\n");
	if(h) freetableau(h);
	return 0;
}

void printMenu(){ //PRINT PRIMARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Build a tableau with input values\n");
    printf("2) Build an empty tableau\n");
    printf("3) Build a tableau with random values\n");
    printf("4) YoungSort!\n");
    printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

void printOpMenu(){ //PRINT SECONDARY MENU
	printf("\t\t\t\tENTER A CHOICE\n");
	printf("*====================================================================================*\n");
	printf("1) Insert an element\n");
	printf("2) Delete tableau\n");
	printf("3) Get tableau size\n");
	printf("4) Check if tableau is empty\n");
	printf("5) Get min value\n");
	printf("6) Print tableau\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("0) Exit\n");
	printf("*====================================================================================*\n");
}

void sortArray(){
    int *array=NULL;
    int i,dim=0;
    do{
        printf("What's the sequence size?\n");
        scanf("%d",&dim);
        clearBuffer();
    }while(dim<0);

    array=malloc(dim*sizeof(int));
    for(i=0;i<dim;i++){
        printf("Element %d : ",i+1);
        scanf("%d",&array[i]);
        clearBuffer();
    }
    YoungSort(array,dim);
    printf("\n| ");
    for(i=0;i<dim;i++)
        printf("%d | ",array[i]);
    printf("\n");
}


tableau* getTabFromRandomVal(){ //BUILD A RANDOM HEAP WITH RANDOM DIMENSION AND VALUES
    int r,c,i,tot,*array;
    tableau* h=NULL;
    r=rand();
    c=rand();
    tot = rand()%(r*c);
    array = (int *) malloc((c * r) * sizeof(int));
    for(i=0;i<(c*r);i++)
        array[i]=rand();
        
    h = createTableau(array,r,c,tot);
    free(array);
    return h;
}


tableau* getTabFromInput(int mode){ // GET HEAP VALUES AND DIMENSION FROM STDIN
	int r,c,i,tot,*array,tmp;
	tableau *h=NULL;
	r=-1;
	c =-1;
	tot = -1;
	while(r<0){
		printf("How many rows should the tableau have?\n");
		scanf("%d",&r);
		clearBuffer();
	}
	while(c<0){
		printf("How many columns should the tableau have?\n");
		scanf("%d",&c);
		clearBuffer();
	}
	array = (int *) malloc((c * r) * sizeof(int));
	if(mode==AUTOINS) {
		while (tot > c * r || tot < 0) {
			printf("How many elements to insert?\n");
			scanf("%d", &tot);
			clearBuffer();

		}
		for (i = 0; i < tot; i++) {
			printf("Element %d ", i + 1);
			scanf("%d", &array[i]);
			clearBuffer();
		}
	}else{
		tot = 0;
	}
	h=createTableau(array,r,c,tot);
	free(array);
	return h;
}

