#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "arrayStatici.h"

int main(){
	srand(time(NULL));
	tree *t = NULL;
	t = newRandomTree();
	print(t);
	return 0;
}
