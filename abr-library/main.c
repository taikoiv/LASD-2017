#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abr.h"

#define X 1001
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	srand(time(NULL));
	tree *head;
	int c,i;
	float avg=0;
	printf("0 to test random insert\n");
	scanf("%d",&c);
	if(c==0){
		tree *trees[X];
		for(i=0;i<X;i++){
			trees[i]=newRandomTree(65536);
			c=height(trees[i]);
			avg+=c;
			printf("ALBERO %d - ALTEZZA = %d\n",i+1,c);
		}
		printf("ALTEZZA MEDIA FLOAT : %f - INT : %d",avg/X,(int)avg/X);
	}
	else{
		head = newRandomTree(10);
	    print(head, 0);
	}
	return 0;
}
