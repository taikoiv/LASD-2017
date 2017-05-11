#ifndef ABR_H
#define ABR_H
/*---------------------------------------------------------------------------------------------------------------------
	PROGETTO #2 - Laboratiorio Algoritmi e Strutture Dati	                                             GRUPPO:11
		
	Francesco Borrelli N86/2055
	Alessandro Grieco  N86/1314
	Camilla Zampella   N86/1390
-----------------------------------------------------------------------------------------------------------------------*/

extern int ABRERROR; //MANAGES ERROR IN THE LIBRARY FUNCTIONS
/*----------------------------------------------------------------------------------------------------------------------
	                                             ABRERROR CODES AND MEANING :
	- ABRERROR =  0 EVERYTHING IS OK
	- ABRERROR = -1 NOT A VALID FOR ROTATATION SELECTED
	- ABRERROR = -2 ROTATION WAS CALLED ON AN EMPTY BST
	- ABRERROR = -3 RIGHT ROTATION CALLED ON A BST WITHOUT RIGHT CHILD
	- ABRERROR = -4 LEFT ROTATION CALLED ON A BST WITHOUT LEFT CHILD
----------------------------------------------------------------------------------------------------------------------*/

struct Tree{  
	int info; //THE DATA STORED INTO THE NODE
	int h; //BST HEIGHT 
	struct Tree *right; //RIGHT CHILD
	struct Tree *left; 	//LEFT CHILD	
};

typedef struct Tree tree;

tree *newRandomTree(int nNodes); //CREATES A RANDOM BST THAT ALLOWS TO HAVE DUPLICATES 
tree *insertNode(tree *head, int val); //INSERT A NODE EVEN IF IT ALREADY EXISTS
tree *merge(tree* t1, tree* t2); //IN-PLACE FUCTION THAT MARGES TWO BST WITHOUT DUPLICATES
void printBst(tree *head); //BST DRAWER
tree *deleteNode(tree *head, int val); //DELETES A NODE INTO A BST WITH DUPLICATES OR NOT
tree *rotation(tree* t,int n,int direction); //APPLIES N TIME THE SELECTED ROTATION ( 0 FOR LEFT ROTATION AND 1 FOR RIGHT ROTATION )
tree *newRandomBst(int nNodes); //CREATE A RANDOM BST WITHOUT DUPLICATES
tree *insertBstNode(tree *head, int val); //BST INSERT FUNCTION
tree *balanceBst(tree *t); //BALANCE A BST
void freeBST(tree* t); //FREE ALL THE STRUCT RECURSIVELY
void inOrder(tree* t);//PRINTS A TREE IN ORDER
void preOrder(tree* t);//PRINTS A TREE IN PREORDER
void postOrder(tree *t);//PRINTS A TREE IN POSTORDER
#endif	
