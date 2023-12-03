#ifndef _Stack_linked
#define _Stack_linked

typedef int Data;

typedef struct _node{
    Data data;
    struct _node* next;
}node;

typedef struct _stLinked{
    node* head;
    int len;
}stLinked;

typedef stLinked Stack;

void stinit(Stack* st);
int isEmpth(Stack* st);
void push(Stack* st,Data data);
Data pop(Stack* st);
Data peek(Stack* st);

#endif