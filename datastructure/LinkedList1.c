#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int data;
    struct _node* next;
}node;


int main(){
    node* head =NULL;
    node* tail =NULL;
    node* cur =NULL;

    node* newnode = NULL;
    int readData;

    //데이터 읽기
    while(1){
        printf("자연수를 입력 하시오 종료하려면 0 입력");
        scanf("%d",&readData);
        if(readData<1) break;

        //노드추가
        newnode = (node*)malloc(sizeof(node));
        newnode->data =readData;
        newnode->next = NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
           tail->next =newnode;
        }
        tail = newnode;

    }
    printf("\n");

    //데이터 출력
    if(head == NULL){
        printf("출력할 데이터가 없습니다.");
    }else{
        cur=head;
        printf("%d\n",cur->data);
        while(cur->next != NULL){
            cur = cur->next;
            printf("%d\n",cur->data);
        }
    }
    printf("\n");

    //메모리 해체//
    if(head == NULL){
        return 0;
    }else{
        node* delnode = head;
        node* del_next = delnode->next;
        printf("%d를 삭제 ",delnode->data);
        free(delnode);
        while(del_next != NULL){
            delnode = del_next;
            //다음꺼 담아뒀다가 다시 delnode에게 줌 
            del_next = delnode->data;
            printf("%d를 삭제 ",delnode->data);
            free(delnode);
        }


    }

}