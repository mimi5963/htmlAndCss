#ifndef __LINKED_LIST_ARRAY
#define __LINKED_LIST_ARRAY

#define MAX_LEN 100
typedef int Ldata;

typedef struct _ArrayList{
    Ldata arr[MAX_LEN];
    int numofdata;
    int cur;
}ArrayLinkedList;

typedef ArrayLinkedList List;

void Listinit(List* plist);
void Linsert(List* plist, Ldata data);

int LFirst(List* plist, Ldata* data);
int Lnext(List* plist, Ldata* data);

Ldata LRemove(List* plist);
void Lclear(List* plist);

#endif