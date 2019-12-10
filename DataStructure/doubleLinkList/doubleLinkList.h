#ifndef _DOUBLELINKLIST_H
#define _DOUBLELINKLIST_H

#define SUCCESS    10001
#define FAILURE    10000

struct dulNode
{
    int data;
    struct dulNode *preNode;
    struct dulNode *nextNode;
};
typedef struct dulNode dul;
typedef dul *pdul; 
//int dulLength = 0;    Á´±í³¤¶È

int Init_dulLinkList(pdul *h, pdul *t);
int InsertElem(pdul h, int e);
int getElem(pdul h, pdul *elem, int e);
int DeleteElem(pdul h, int e);
int printLinkList(pdul h);
int DeleteList(pdul h, pdul t);

#endif