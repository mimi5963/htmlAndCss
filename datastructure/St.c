#include<stdio.h>
#include"St.h"

void StackInit(Stack* st){
    st->index = -1;
}
int isEmpty(Stack* st){
    if(st->index == -1) return 1;
    return 0;
}

void push(Stack* st, Sdata data){
    (st->index)++;
    st->arr[st->index] =data;
}
Sdata pop(Stack* st){
    if(isEmpty(st)){ 
        printf("스택 메모리 에라\n");
        exit(-1);
        }
    int rpos = st->index;
    (st->index)--;
    return st->arr[rpos];

}
Sdata peek(Stack* st){
    if(isEmpty(st)){
        printf("스택 메모리 에라\n");
        exit(-1);
    }
    return st->arr[st->index];
}

int size(Stack* st){
    return len(st->arr);
}