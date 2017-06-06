#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct list{
	int k;
	struct list* next;
} list;

list* insertTop(list* l,int k);
void freeList(list* l);

#endif
