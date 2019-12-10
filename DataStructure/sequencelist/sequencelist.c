#include <stdio.h>
#include <stdlib.h>
#include "sequencelist.h"

int InitList (List *l)         //初始化
{
    l->data = (int *)malloc(sizeof(int) * 128);     //内存管理没那么严格，但最好不要写超过
    if (NULL == l->data)
    {
        return FAILURE;
    }

    l->length = 0;

    return SUCCESS;
}

int InsertList(List *l, int p, int a)     //插入元素
{
    if (l->length >= SIZE || l->data == NULL)
    {
        return FAILURE;
    }
    if (p > l->length + 1)
    {
        return FAILURE;
    }

    int i;
    for (i = 0; i < l->length - p + 1; i++)     //插入方式依次压入
    {
        l->data[l->length - i] = l->data[l->length - i - 1];
    }
    l->data[p - 1] = a;
    l->length++;
    return SUCCESS;
    
}
/*
普通版
int locateElem(List l, int e, int *p)
{
    if (l.data == NULL)
    {   
        return FAILURE;
    }

    int i;
    for (i = 0; i < l.length; i++)
    {
        if (l.data[i] == e)
        {
            *p = i + 1;
            return SUCCESS;
        }
    }
    return FAILURE;
}
*/

//函数指针版
int locateElem(List l, int e, int *p, int (*f)(int ,int))
{
    if (l.data == NULL)
    {   
        return FAILURE;
    }

    int i;
    int j = 0;
    int flag = 0;
    for (i = 0; i < l.length; i++)
    {
        if (f(l.data[i],e))
        {
            flag = 1;
            printf("%d 在第%d位\n", e, i + 1);
        }
    }
    if (1 == flag)
    {
        return SUCCESS;
    }
    return FAILURE;
}

//清空顺序表
int ClearList(List *l)
{
    if (NULL == l)
    {
        return FAILURE;
    }

    l->length = 0;
    return SUCCESS;
}

//摧毁顺序表
int DesList(List *l)
{
    if (NULL == l || NULL == l->data)
    {
        return FAILURE;
    }

    free(l->data);
    l->data = NULL;
    return SUCCESS;
}