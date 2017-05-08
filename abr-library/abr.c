#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "abr.h"

//SUPPORT METHODS PROTOTIPES
tree* staccaMin(tree *node,tree *father);
tree* delete(tree* node);
tree* lRotation(tree* t);
tree* rRotation(tree* t);
tree* rBalance(tree* t);
tree* lBalance(tree* t);
int height(tree* t);
void updateH(tree* t);

/*int *createqueue(){
	
}
int *enqueue(int *q, val);
int dequeue(int *q);*/

tree* rBalance(tree* t){
	tree *dx=t->right;
	if(dx!=NULL){
		if(height(dx->right)<height(dx->left)){
			dx=rotation(dx,1,0);
			updateH(dx);	
		}
		t=rotation(t,1,1);
		updateH(t);
	}
	return t;
}

tree* lBalance(tree* t){
	tree *sx=t->left;
	if(sx!=NULL){
		if(height(sx->left)<height(sx->right)){
			sx=rotation(sx,1,1);
			updateH(sx);	
		}
		t=rotation(t,1,0);
		updateH(t);
	}
	return t;
}

void updateH(tree* t){
	if(height(t->left)>height(t->right))
		t->h=height(t->left)+1;
	else t->h=height(t->right)+1;
}

tree *balanceBst(tree *t){
	if(t!=NULL){
		while(abs(height(t->left)-height(t->right))>1){
			if(height(t->left)>height(t->right))
				t=lBalance(t);
			else t=rBalance(t);
		}
	}
	return t;
}

tree *rotation(tree* t,int n,int direction){
	if(direction<0 || direction>1){
		printf("NOT A VALID ROTATION\n");
		return t;
	}
	if(t==NULL){
		printf("IT'S NOT POSSIBLE TO ROTATE AN EMPTY ABR!\n");
		return t;
	}
	while(n>0){
		if(rotation==0){ //LEFT ROTATION
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
		printf("IT'S NOT POSSIBLE TO ROTATE BEACAUSE THERE IS NO RIGHT CHILD IN THIS BST\n");
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
		printf("IT'S NOT POSSIBLE TO ROTATE BEACAUSE THERE IS NO LEFT CHILD IN THIS BST\n");
		return t;	
	}
	return sx;
}

int height(tree* t){
	if(t!=NULL) return t->h;
	return 0;
}

tree *insertNode(tree *head, int val){
	if(head!=NULL){
		if(head->info>val)
			head->left=insertNode(head->left, val);
		else 
			head->right=insertNode(head->right, val);
			
		updateH(head);
	}
	else{
		head = (tree *)malloc(sizeof(tree));
		head->info = val;
		head->left = NULL;
		head->right = NULL;
		head->h=1;
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

void print(tree *head, int spaces, int height){
	int i=0;
	if (head != NULL){
    	if (height == 1){
    		for(i=spaces; i>0; i--)
    			printf(" ");
        	printf("%d\t", head->info);
        }
    	else if (height > 1){
    		spaces=spaces-height;
    		print(head->left, spaces, height-1);
    		spaces=spaces+2*height;
    		print(head->right, spaces, height-1);
		}
	} 
}

void printBst(tree *head){
	int h = height(head);
	int spaces = (h*h)/2;
    int i;
    for (i=1; i<=h; i++){
    	spaces = spaces-2;
        print(head, spaces ,i);
        printf("\n");
    }
} 

tree *merge(tree *t1, tree *t2){
	tree* temp;
	if(t1!=NULL){
		if(t2==NULL){
			t2=t1;
		} else if(t1->info>t2->info){
			temp=t1->left;
			t1->left=NULL;
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
			t1->left=NULL;
			t1->right=NULL;
			free(t1);
		}
	}
	if(t2!=NULL) updateH(t2);
	return t2;
}

tree *staccaMin(tree *node, tree *father){
	if(node->left!=NULL)
		return staccaMin(node->right,node);
	if(node==father->right)
		father->right=node->right;
	else father->left=node->right;
	
	updateH(father);
	
	return node;
}

tree *delete(tree *node){ //DELETE THE NODE
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

tree *newRandomBst(int nNodes){
	tree *head = NULL;
	while(nNodes>0){
		head = insertBstNode(head, rand());
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
		head->info = val;
		head->left = NULL;
		head->right = NULL;
		head->h=1;
	}
	return head;
}

