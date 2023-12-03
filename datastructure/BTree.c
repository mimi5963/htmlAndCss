#include<stdlib.h>
#include"BTree.h"

BTreeNode* MakeBTreeNode(void){
    BTreeNode* new = (BTreeNode*)malloc(sizeof(BTreeNode));
    new->left = NULL;
    new->right = NULL;
    return new;
}
BTdata GetData(BTreeNode* bt){
return bt->data;
}
void SetData(BTreeNode* bt, BTdata data){
 bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt){
return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt){
return bt->right;

}
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub){
    if(main->left != NULL){ //순회 필요함
        free(main->left);
        //Delete(main->left);
    }
    main->left = sub;

}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub){

 if(main->right != NULL){
        free(main->right);
        //Delete(main->right);
    }
    main->right = sub;
}

void InorderTraverse(BTreeNode* bt,VisitFuncPtr action){
    if(bt == NULL) return;
    InorderTraverse(bt->left,action);
    action(bt->data);
    InorderTraverse(bt->right,action);
}
void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action){
    if(bt == NULL) return;
    action(bt->data);
    PreorderTraverse(bt->left,action);
    PreorderTraverse(bt->right,action);
}
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action){
    if(bt == NULL) return;
    PostorderTraverse(bt->left,action);
    PostorderTraverse(bt->right,action);
    action(bt->data);
}

void DeleteTree(BTreeNode * bt)
{
    if(bt == NULL) return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}