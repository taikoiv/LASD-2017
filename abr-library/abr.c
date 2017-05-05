#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"

tree* staccaMin(tree *node,tree *father);
tree* delete(tree* node);
tree* lRotation(tree* t);
tree* rRotation(tree* t);

/*int *createqueue(){
	
}
int *enqueue(int *q, val);
int dequeue(int *q);*/

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

tree* lRotation(tree* t){
	tree* dx=NULL;
	if(t->right!=NULL){
		dx=t->right;
		t->right=dx->left;
		dx->left=t;
	} else {
		printf("IT'S NOT POSSIBLE TO ROTATE BEACAUSE THERE IS NO RIGHT CHILD IN THIS BST\n");
		return t;
	}
	return dx;
}

tree* rRotation(tree* t){
	tree* sx=NULL;
	if(t->left!=NULL){
		sx=t->left;
		t->left=sx->right;
		sx->right=t;
	} else {
		printf("IT'S NOT POSSIBLE TO ROTATE BEACAUSE THERE IS NO LEFT CHILD IN THIS BST\n");
		return t;	
	}
	return sx;
}

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

void print(tree *head, int enters){
	int i=0;
	if(head!=NULL){
		print(head->left, enters);
		printf("%d ", head->info);
		print(head->right, enters);
	}
}

/*void bfs_bintree (tree *head)
{
  queue_t *q;
  tree *temp;

  q = queue_allocate ();
  queue_insert (q, head);

  while (!queue_is_empty (q))
  {
    temp = queue_remove (q);

    if (temp->left)
      queue_insert (temp->left);

    if (temp->right)
      queue_insert (temp->right);
  }
  queue_free (q);
  return;
}*/

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
	
}


tree *insertBstNode(tree *head, int val){
	
}

