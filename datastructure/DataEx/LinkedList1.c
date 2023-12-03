#include "LinkedList1.h"
#include <stdio.h>


void Listinit(List* plist){
    plist->cur =-1;
    plist->numofdata =0;
}
void Linsert(List* plist, Ldata data){
   if(plist->numofdata >= MAX_LEN){
        exit(1);
   }
   plist->arr[(plist->numofdata)++] = data; 

}

int LFirst(List* plist, Ldata* data){
   if(plist->numofdata == 0){
    printf("참조할 데이터 없음");
    return 0;
   }
   
   plist->cur =0;
   *data = plist->arr[plist->cur];
   return 1;
}
int Lnext(List* plist, Ldata* data){
    if(plist->cur >= (plist->numofdata)-1)
    {
        printf("더 이상 참조할 데이터 없음");
        return 0;
    }
    *data =plist->arr[++(plist->cur)];
    return 1;
}

Ldata LRemove(List* plist){
   Ldata rdata = plist->arr[plist->cur];
   int rindex = plist->cur;

   for(int i=rindex; i<(plist->numofdata)-1;i++){
       plist->arr[i] = plist->arr[i+1];
   }
   (plist->cur)--;
   (plist->numofdata)--;

    return rdata;
}
void Lclear(List* plist){
    plist->numofdata=0;   
}