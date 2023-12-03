#include <stdio.h>
#include <stdlib.h>
#include"StLinked.h"

void stinit(Stack* st){
    st->head =NULL;
}
int isEmpth(Stack* st){
    if(st->head == NULL) return 1;
    return 0;
}
void push(Stack* st,Data data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data =data;
    newnode -> next = st->head;
    st->head = newnode;
}
Data pop(Stack* st){
    if(isEmpty(st)){
        printf("스택 메모리 오류");
        exit(-1);
    }
    node* rnode = st->head;
    Data rdata = st->head->data;
    st->head = st->head->next;
    free(rnode);
    return rdata;
}
Data peek(Stack* st){
    if(isEmpth(st)){
        printf("스택 메모리 오류");
        exit(-1);
    }
    return st->head->data;
}