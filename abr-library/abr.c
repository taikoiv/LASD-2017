#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "abr.h"

int ABRERROR;

//SUPPORT METHODS PROTOTIPES
tree* staccaMin(tree *node,tree *father);
tree* delete(tree* node);
tree* lRotation(tree* t); //IT APPLIES THE LEFT ROTATION ON THE BST
tree* rRotation(tree* t); //IT APPLIES THE RIGHT ROTATION ON THE BST
tree* rBalance(tree* t);  //THIS FUNCTION BALANCES THE BST IN CASE THE RIGHT SUB-TREE IS NOT ALREADY BALANCED
tree* lBalance(tree* t);  //THIS FUNCTION BALANCES THE BST IN CASE THE left SUB-TREE IS NOT ALREADY BALANCED
int height(tree* t);      //RETURNS THE HEIGHT OF THE BST
void updateH(tree* t);    //THIS FUNCTION UPDATES THE BST'S HEIGHT

/*--------------------------------BALANCE FUNCTIONS----------------------------------*/
tree* rBalance(tree* t){ // WHEN THE TREE IS NOT BALANCED BEACAUSE OF THE RIGHT SUB-TREE
	tree *dx=t->right;
	if(dx!=NULL){
		if(height(dx->right)<height(dx->left)){
			t->right=rotation(t->right,1,0); //LEFT ROTATION ON THE RIGHT SUB-TREE	
		}
		t=rotation(t,1,1); //RIGHT ROTATION ON THE ROOT
	}
	return t;
}

tree* lBalance(tree* t){ // WHEN THE TREE IS NOT BALANCED BEACAUSE OF THE LEFT SUB-TREE
	tree *sx=t->left;
	if(sx!=NULL){
		if(height(sx->left)<height(sx->right)){
			t->left=rotation(t->left,1,1); //RIGHT ROTATION ON THE LEFT SUB-TREE	
		}
		t=rotation(t,1,0); //LEFT ROTATION ON THE ROOT
	}
	return t;
}

tree *balanceBst(tree *t){
	if(t!=NULL){
		while(abs(height(t->left)-height(t->right))>1){ //WHILE BST IS NOT BALANCED
			if(height(t->left)>height(t->right)) //VIOLATION IS ON THE LEFT SUB-TREE
					t=lBalance(t);
			else t=rBalance(t); //VIOLATION IS ON THE RIGHT SUB-TREE
		}	
	}
	return t;
}

/*------------------------------------------------------------------------------*/

void updateH(tree* t){
	if(height(t->left)>height(t->right))
		t->h=height(t->left)+1;
	else t->h=height(t->right)+1;
}

/*-------------------ROTATION FUNCTIONS--------------------------------------------*/

tree *rotation(tree* t,int n,int direction){
	if(direction<0 || direction>1){
		ABRERROR=-1;
		return t;
	}
	if(t==NULL){
		ABRERROR=-2;
		return t;
	}
	while(n>0){
		if(direction==0){ //LEFT ROTATION
			t=lRotation(t);
		} else { // RIGHT ROTATION
			t=rRotation(t);
		}
		n--;
	}
	return t;
}

tree* rRotation(tree* t){ 
	tree* dx=NULL;
	if(t->right!=NULL){
		dx=t->right;
		t->right=dx->left;
		dx->left=t;
		
		updateH(t);
		updateH(dx);
	} else {
		ABRERROR=-3;
		return t;
	}
	return dx;
}

tree* lRotation(tree* t){
	tree* sx=NULL;
	if(t->left!=NULL){
		sx=t->left;
		t->left=sx->right;
		sx->right=t;

		updateH(t);
		updateH(sx);
	} else {
		ABRERROR=-4;
		return t;	
	}
	return sx;
}

/*------------------------------------------------------------------*/

int height(tree* t){
	if(t!=NULL) return t->h;
	return -1;
}

/*----------------INSERT AND CREATE BST WITH DUPLICATES-----------------*/

tree *insertNode(tree *head, int val){
	if(head!=NULL){
		if(head->info>val)
			head->left=insertNode(head->left, val);
		else 
			head->right=insertNode(head->right, val); //if val already exists it will be inserted in the right sub-tree
			
		updateH(head);
	}else{ //creation of a new node
		head = (tree *)malloc(sizeof(tree));
		if(head==NULL){
			printf("THERE IS NO SPACE TO ALLOCATE A NEW NODE. TRY LATER\n");
			return NULL;
		}
		head->info = val;
		head->left = NULL;
		head->right = NULL;
		head->h=0;
	}
	return head;
}

tree *newRandomTree(int nNodes){
	tree *head = NULL;
	while(nNodes>0){
		head = insertNode(head, rand());
		nNodes--;
	}
	return head;
}

/*-----------------------------------------------------------------------*/

/*-----------------------DRAW FUNCTIONS----------------------------------*/

void print(tree *head, int spaces, int height){
	int i=0;
	if (head != NULL){
    	if (height == 1){ //IF THE NODE IS ON THE LEVEL THAT WE ARE CURRENTLY PRINTING ON
    		for(i=spaces; i>0; i--)
    			printf(" "); //PRINT SOME SPACES
        	printf("%d", head->info);
        }
    	else if (height > 1){ //GO TO THE LEFT AND THE RIGHT SUB-TREES
    		print(head->left, spaces/2, height-1);
    		print(head->right, (spaces)+(sizeof(int)), height-1);
		}
	} 
}

void printBst(tree *head){
	int h = height(head);
	int area = pow(2,h); // SPACES IS EQUALS TO THE NUMBER OF THE LEAVES IN A FULL BST
    int i;
    int base = (area*2)/h;
    for (i=1; i<=h; i++){ //TO DRAW IN LEVELS
		print(head,base,i);
		printf("\n\n");
	}
}

/*--------------------------------------------------------------------------------------*/

/*-----------------------------MERGE FUNCTION-------------------------------------------*/

tree *merge(tree *t1, tree *t2){
	tree* temp;
	if(t1!=NULL){
		if(t2==NULL){ //ATTACHES THE SUB-TREE
			t2=t1;
		} else if(t1->info>t2->info){ 
			temp=t1->left;
			t1->left=NULL; //BREAKS THE BST
			t2->right=merge(t1,t2->right);
			t2=merge(temp,t2);
		} else if(t1->info<t2->info){
			temp=t1->right;
			t1->right=NULL;
			t2->left=merge(t1,t2->left);
			t2=merge(temp,t2);
		} else {
			t2->left=merge(t1->left,t2->left);
			t2->right=merge(t1->right,t2->right);
			free(t1); //DELETES THE DUPLICATES IN T1
		}
	}
	if(t2!=NULL) updateH(t2); //UPDATES THE HEIGHT OF THE BST
	return t2;
}

/*------------------------------------------------------------------------*/

/*-------------------------DELETE FUNCTIONS-------------------------------*/

tree *staccaMin(tree *node, tree *father){ //RETURNS THE MINIMUM NODE IN THE RIGHT SUB-TREE
	if(node->left!=NULL)
		return staccaMin(node->right,node);
	if(node==father->right)
		father->right=node->right;
	else father->left=node->right;
	
	updateH(father);
	
	return node;
}

tree *delete(tree *node){ //DELETES THE NODE WITHOUT LOSING HIS CHILDREN
	tree *temp=NULL;
	
	if(node->left!=NULL && node->right!=NULL){
		temp=staccaMin(node->right,node);
		node->info=temp->info;
	}else if(node->left==NULL){
		if(node->right==NULL){
			temp=node;
			node=NULL;
		} else {
			temp=node;
			node=node->right;
		}
	} else{
		temp=node;
		node=node->right;
	}
	
	updateH(node);
	
	free(temp);
	
	return node;
}

tree *deleteNode(tree *head, int val){ //SEARCH THE NODE TO DELETE
	if(head!=NULL){
		if(head->info>val)
			head->left = deleteNode(head->left, val);
		else if(head->info<val) 
			head->right = deleteNode(head->right, val);
		else{
			head = delete(head);
		}
	}
	return head;
}

/*--------------------------------------------------------------------------------*/

/*----------------------INSERT AND CREATE BST WITHOUT DUPLICATES----------------------*/

tree *newRandomBst(int nNodes){
	tree *head = NULL;
	while(nNodes>0){
		head = insertBstNode(head, rand()%30);
		nNodes--;
	}
	return head;
}


tree *insertBstNode(tree *head, int val){
	if(head!=NULL){
		if(head->info>val)
			head->left=insertBstNode(head->left, val);
		else if(head->info<val)
			head->right=insertBstNode(head->right, val);
		updateH(head);
	}
	else{
		head = (tree *)malloc(sizeof(tree));
		if(head==NULL){
			printf("THERE IS NO SPACE TO ALLOCATE A NEW NODE. TRY LATER\n");
			return NULL;
		}
		head->info = val;
		head->left = NULL;
		head->right = NULL;
		head->h=0;
	}
	return head;
}

/*-----------------------------------------------------------------------*/

void freeBST(tree* t){
	if(t!=NULL){
		freeBST(t->left);
		freeBST(t->right);
		free(t);
	}
}


void inOrder(tree *t){
	if(t!=NULL){
		inOrder(t->left);
		printf("%d  ", t->info);
		inOrder(t->right);
	}
}

void preOrder(tree *t){
	if(t!=NULL){
		printf("%d  ", t->info);
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder(tree *t){
	if(t!=NULL){
		postOrder(t->left);
		postOrder(t->right);
		printf("%d  ", t->info);
	}
}
