#include "SimpleHeap.h"

void HeapInit(Heap* hp){
    hp->numofdata =0;
}
int HisEmpty(Heap* hp){
    if(hp->numofdata ==0) return 1;
    else return 0;
}
void HInsert(Heap* hp, Hdata data,Priority pr){
    int lastIndex = hp->numofdata +1;
    helem hem = {data,pr};
    int Parent = GetParentIndex(lastIndex);

    
    while(lastIndex != 1){
        if(pr < hp->helemarr[Parent].pr){
             //새로 들어오는 데이터의 우선순위가 Parent의 우선순위보다 높다면
             hp->helemarr[lastIndex] = hp->helemarr[Parent];
             //마지막 자리에 부모노드를 옮김
             lastIndex = Parent; // 이제 새로운 데이터가 들어갈 수 있는 마지막 자리는 부모노드의 고유번호
             Parent = GetParentIndex(lastIndex); // 새로운 부모노드 
        }else break;
    }

    
    hp->helemarr[lastIndex] =hem;
    hp->numofdata +=1; 

}
Hdata HDelete(Heap* hp){
    Hdata Ddata = hp->helemarr[1].data;
    helem lastElem = hp->helemarr[hp->numofdata];
    
    
    int Parentnode =1; //빈 부모자리 (지금은 1번)
    int Childnode; // 1번자리두고 마지막 노드랑 경쟁할 우선순위 큰 자식노드  

    while(Childnode = GetTopPriorityChildIndex(hp,Parentnode)){
        if(lastElem.pr <= hp->helemarr[Childnode].pr)
        break;
        else{
            hp->helemarr[Parentnode] = hp->helemarr[Childnode];
            Childnode = Parentnode;
        }
    }

    hp->helemarr[Parentnode] = lastElem;
    hp->numofdata--;
    return Ddata;
}

int GetParentIndex(int idx){
    return idx/2;
}
int GetLeftChildIndex(int idx){
    return idx*2;
}
int GetRightChildIndex(int idx){
        return idx*2+1;
}
int GetTopPriorityChildIndex(Heap* hp,int Parentidx){ //좌 우 자식중 우선순위 높은 노드의 고유번호 return
    //idx는 우선순위에 중복이 없고 순차적 변화라면, 우선순위될 수 있음
    //아니라면, 우선순위에 따라 정렬된 노드의 고유번호 
    //여기서는 자식을 비교하고싶은 부모의 고유번호 매개변수로 받음 
    //다만 힙의 성질에 의해(완전이진트리) idx로 자식노드가 있는지 하나인지는 판단 가능
    //마지막 인덱스 == 마지막 노드의 고유번호 && 마지막 고유번호 == 저장된 노드의 수 
    if(GetLeftChildIndex(Parentidx) > hp->numofdata)
    return 0;
    else if(GetLeftChildIndex(Parentidx) == hp->numofdata)
    return GetLeftChildIndex(Parentidx);
    if(hp->helemarr[GetLeftChildIndex(Parentidx)].pr > hp->helemarr[GetRightChildIndex(Parentidx)].pr)
        return GetRightChildIndex(Parentidx);
    else
        return GetLeftChildIndex(Parentidx);    
    

}