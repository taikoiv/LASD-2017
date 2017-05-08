#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"
tree* staccaMin(tree *node,tree *father);
tree* delete(tree* node);


int height(tree* t){
	int hsx,hdx,h=0;
	if(t!=NULL){
		hsx=height(t->left);
		hdx=height(t->right);
		if(hsx>hdx) h=hsx+1;
		else h=hdx+1;
	}
	return h;
}

tree *insertNode(tree *head, int val){
	if(head!=NULL){
		if(head->info>val)
			head->left=insertNode(head->left, val);
		else head->right=insertNode(head->right, val);
	}
	else{
		head = (tree *)malloc(sizeof(tree));
		head->info = val;
		head->left = NULL;
		head->right = NULL;
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

void print(tree *head, int *spaces, int height){
	int i=0;
	if (head != NULL){
    	if (height == 1){
    		for(i=spaces; i>0; i--)
    			printf(" ");
        	printf("%d\t", head->info);
        }
    	else if (height > 1){
    		spaces=spaces-height;
    		print(head->left, &spaces, height-1);
    		spaces=spaces+2*height;
    		print(head->right, &spaces, height-1);
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

tree *merge(tree *head, tree *other){
	if(head!=NULL && other!=NULL){
		if(head->info==other->info){
			  
		}
	}
	else if(head!=NULL&&other==NULL){
		
	}
	else if(head==NULL&&other!=NULL){
		
	}
	
	return head;
}

tree *staccaMin(tree *node, tree *father){
	if(node->left!=NULL)
		return staccaMin(node->right,node);
	if(node==father->right)
		father->right=node->right;
	else father->left=node->right;
	
	return node;
}

tree *delete(tree *node){
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
	
	free(temp);
	return node;
}

tree *deleteNode(tree *head, int val){
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
	}
	else{
		head = (tree *)malloc(sizeof(tree));
		head->info = val;
		head->left = NULL;
		head->right = NULL;
	}
	return head;
}

