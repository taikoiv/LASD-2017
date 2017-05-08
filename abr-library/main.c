#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"

#define X 1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void stampa(tree *t){
	if(t!=NULL){
		
		stampa(t->left);
		printf("%d ", t->info,t->h);
		stampa(t->right);
	}
}

int main() {
	srand(time(NULL));
	tree *head, *other;
	//other = newRandomBst(10);
	head = newRandomBst(30);
	printf("altezza : %d\n\n", height(head)); 
	stampa(head);
	printf("\n-------------------------------------------------\n");
	printBst(head);
	return 0;

}
