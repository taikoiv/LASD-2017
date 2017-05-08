#ifndef ABR_H
#define ABR_H


struct Tree{
	int info;
	int h;
	struct Tree *right;
	struct Tree *left; 		
};

typedef struct Tree tree;

tree *newRandomTree(int nNodes);
tree *insertNode(tree *head, int val);
tree *merge(tree* head, tree* other);
void print(tree *head, int enters);
tree *deleteNode(tree *head, int val);
tree *rotation(tree* t,int n,int direction);
tree *newRandomBst(int nNodes);
tree *insertBstNode(tree *head, int val);
tree *balanceBst(tree *t);

#endif	
