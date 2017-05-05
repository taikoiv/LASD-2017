#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"

#define X 1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	srand(time(NULL));
	tree *head;
	head = newRandomTree(10);
	print(head, 0);
	return 0;
}
