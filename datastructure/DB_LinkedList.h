#ifndef _DB_LINKED_LIST
#define _DB_LINKED_LIST

typedef int Ldata;

typedef struct _node{
    Ldata data;
    struct _node* next;
    struct _node* pre;
}node;

typedef struct db_linked_list{
    node* head;
    node* cur;
    int size;
}dblist;

typedef dblist List;

void Listinit(List* plist);
void Linsert(List* plist, Ldata data);

int Lfirst(List* plist,Ldata* data);
int LNext(List* plist,Ldata* data);
int Lprevious(List* plist,Ldata* data);

int Lsize(List* plist);





#endif