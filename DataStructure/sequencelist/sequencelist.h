#ifndef _SEQUENCELIST_H
#define _SEQUENCELIST_H

#define  SIZE  20
#define  SUCCESS  10000
#define  FAILURE  10001

typedef struct squencelist
{
    int *data;
    int length;
}List;

int InitList(List *l);
int InsertList(List *l, int p, int a);
int locateElem(List l , int e, int *p, int (*f)(int ,int));
int ClearList(List *l);
int DesList(List *l);

#endif