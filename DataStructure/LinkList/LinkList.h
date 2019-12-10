#ifndef _LINKLIST_H
#define _LINKLIST_H

#define SUCCESS    10001
#define FAILURE    10000
#define TURE       10002
#define FALSE      10003

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
typedef node *pnode;

int InitLink(pnode *h);
int InsertLink(pnode h, int p, int e);
int LinkEmpty(pnode h);
int TraverseLink(pnode h);
int LocateElem(pnode h, int e, int *p);
int GetElem(pnode h, int p);
int DeleteElem(pnode h, int e);
int DeleteList(pnode *h);
int ReverseList(pnode h);
int ts(pnode h);
int PriorLink(pnode h, int e);
int NextLink(pnode h, int e);

#endif