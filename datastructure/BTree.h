#ifndef __BTree_H
#define __BTree_H


typedef int BTdata;

typedef void VisitFuncPtr(BTdata data);

typedef struct _btreeNode{
    BTdata data;
    struct _btreeNode* left;
    struct _btreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTdata GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTdata data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);  
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt,VisitFuncPtr action);




#endif