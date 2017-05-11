#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	srand(time(NULL));
	tree *head, *other;
	other = newRandomBst(10);
	head = newRandomBst(150);
	//stampa(head);
	printBst(head);
	printf("\n-------------------------------------------------\n");
	head=balanceBst(head);
	printBst(head);
	printf("\n");
	//stampa(head);

	return 0;

}
