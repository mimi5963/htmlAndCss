#include <stdio.h>
#include <stdlib.h>
#include "LinkedListDummy.h"

void ListInit(List* plist){
    plist->head = (Node*)malloc(sizeof(Node)); //더미노드 추가
    plist->head->next = NULL; 
    plist->before= NULL;
    plist->cur =NULL;
    plist->size =0;
}
void LFinsert(List* plist, Ldata data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
   
    
     newnode->next = plist->head->next; 
     plist->head->next = newnode;
     (plist->size)++;

}
void LSInsert(List* plist,Ldata data){
    Node* newnode = (Node*)malloc(sizeof(newnode));
    Node* pred = plist->head; //pred 왼쪽에는 데이터 추가 x 오른쪽에만 가능 따라서 dummy부터 시작
    newnode->data = data;
    //새노드가 들어갈 자리를 찾기위한 반복
    while(pred->next != NULL && plist->comp(data,pred->next->data) != 0){
        pred=pred->next; //head부터 다음 노드로 이동
    }
    newnode->next=pred->next;
    pred->next = newnode;

    (plist->size)++;

    //정렬기준은 0 == data<pred->next->data임 (데이터 삽입)
    //           1== data>pred->next->data인 경우 (이동)
}
void Linsert(List* plist, Ldata data){
    if(plist->comp == NULL)
    LFinsert(plist,data);
    else
    LSInsert(plist,data);
}

int Lfrist(List* plist, Ldata* data){
    if(plist->head->next =NULL){
        printf("조회할 데이터가 없습니다.\n");
        return 0;
    }
    plist->before = plist->head; //시작점에선 필요없을 것 같지만.. 첫 데이터를 삭제하는 과정에서 필요함
    plist->cur = plist->head->next;
    *data = plist->cur->data;

    return 1;

}
int LNext(List* plist, Ldata* data){
    if(plist->cur->next == NULL){
        printf("더 이상 조회할 데이터가 없습니다.\n");
        return 0;
    }
    plist->before = plist->cur;
    plist->cur= plist->cur->next;

    *data = plist->cur->data;
    return 1;
}

Ldata LRemove(List* plist){
    Node* RemoveNode = plist->cur;
    Ldata Rdata = RemoveNode->data;

    plist->before->next = RemoveNode->next; //삭제는 보통 조회와 같이 이루어짐
    plist->cur = plist->before; //삭제 후 현 위치는 before과 같음
    free(RemoveNode);
    (plist->size)--;
    
    return Rdata;

}
int Lcount(List* plist){
 return plist->size;
}

void SetSortRule(List * plist, int(*comp)(Ldata d1,Ldata d2)){
    plist->comp = comp;
    //정렬기준의 함수는 외부에서 주어짐 
}