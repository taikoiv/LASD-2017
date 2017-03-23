#ifndef MHEAP_H
#define MHEAP_H

/*
============================================MIN HEAP LIBRARY======================================================================
	MADE BY Francesco Borrelli N86/2055,
			Alessandro Grieco  N86/1314,
			Camilla Zampella   N86/1390
    
    GROUP ID : 11
==================================================================================================================================
*/

typedef struct{
	int size; //the real size of the array used to represent the heap
	int *data;	//sequence of data
} heap;


int isEmpty(heap *h);					// IF HEAP CONTAINS 0 ELEMENTS RETURN 0 ELSE RETURN 1
int size(heap *h);						// RETURN HOW MANY ELEMENTS HEAP CONTAINS
int min(heap *h);						// RETURN THE MINIMUM VALUE IN THE HEAP
void insert(heap *h,int k);				// ADD k TO THE HEAP
void delete(heap *h,int k);				// DELETE k FROM THE HEAP

/* COMPLEX FUNCTIONS */
//-------------------------------------BUILD HEAP--------------------------------------------------------------------------------
heap* buildHeap(int* data, int dim);
/*	PARAMETERS :
		- DATA : an array that contains all the sequence elements
		- DIM : dimension of DATA
		
	@PRE : We assumed the sequence has not duplicate values
	@POST : Return an heap that contains all the elements of DATA
	
	TIME COMPLEXITY : THETA(N)
	SPACE COMPLEXITY : THETA(N)
---------------------------------------------------------------------------------------------------------------------------------*/

//-------------------------------------HEAP SORT---------------------------------------------------------------------------------
void heapSort(int *data, int dim);
/*	PARAMETERS :
		- DATA : an array that contains all the sequence elements
		- DIM : dimension of DATA
		
	@PRE : We assumed the sequence has not duplicate values
	@POST : Sort the sequence using an heap
	
	TIME COMPLEXITY : THETA(Nlog(N))
	SPACE COMPLEXITY : THETA(N)
---------------------------------------------------------------------------------------------------------------------------------*/

//-------------------------------------FREE HEAP---------------------------------------------------------------------------------
void freeheap(heap *h);
/*	PARAMETERS :
		- h : the heap to delete
		
	@PRE : heap has to be allocated
	@POST : free the data structur and the heap
	
	TIME COMPLEXITY : THETA(1)
	SPACE COMPLEXITY : THETA(1)
---------------------------------------------------------------------------------------------------------------------------------*/

//-------------------------------------FREE HEAP---------------------------------------------------------------------------------
void printHeap(heap *h);
/*	PARAMETERS :
		- h : the heap to print
		
	@PRE : heap has to be allocated
	@POST : heap values are printed on the screen
	
	TIME COMPLEXITY : THETA(N)
	SPACE COMPLEXITY : THETA(N)
---------------------------------------------------------------------------------------------------------------------------------*/
#endif
