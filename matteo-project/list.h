#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct list{
	int k;
	struct list* next;
} list;

extern int LIST_ERROR;

list* insertTop(list* l,int k);
void freeList(list* l);

#endif
