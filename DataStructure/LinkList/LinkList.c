#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
函数功能：初始化链表表头
函数参数：表头地址
函数返回值：SUCCESS FAILURE
*/
int InitLink(pnode *h)  //由于需要修改实参指针内容，所以函数参数需要双重指针
{
    if (h == NULL)
    {
        printf("初始化失败\n");
    }

    *h = (node *)malloc(sizeof(node) * 1);
    if (NULL == *h)
    {
        return FAILURE;
    }

    (*h)->next = NULL;

    return SUCCESS;
}

/*
函数功能：向链表插值
函数参数：表头 插入位置 查入元素
函数返回值：FAILURE SUCCESS
*/
int InsertLink(pnode h, int p, int e)   //向链表插入数值，如果要插入的位置前面不存在，就插入失败
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pnode n = h;
    int k = 1;
    while(k < p && n)
    {
        n = n->next;
        k++;
    }

    if (!n || p < k)
    {
        return FAILURE;
    }

    pnode m = (pnode)malloc(sizeof(node) * 1);
    if (NULL == m)
    {
        return FAILURE;
    }

    m->data = e;
    m->next = n->next;
    n->next = m;

    return SUCCESS;
}

/*
函数功能：确认链表是否为空
函数参数：表头
函数返回值：FAILURE SUCCESS
*/
int LinkEmpty(pnode h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    return (h->next == NULL) ? TURE : FALSE;
}

/*
函数功能：输出链表
函数参数：表头
函数返回值：SUCCESS FAILURE
*/
int TraverseLink(pnode h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pnode n = h->next;
    while(n)
    {
        printf("%d ", n->data);
        n = n->next;
    }

    printf("\n");

    return SUCCESS;
}

/*
函数功能：定位元素
函数参数：表头 元素 元素位置
函数返回值：SUCCESS FAILURE
*/
int LocateElem(pnode h, int e, int *p)
{
    if(NULL == h)
    {
        return FAILURE;
    }

    h = h->next;
    while(h)
    {   
        if (h->data == e)
        {
            return SUCCESS;
        }
        else
        {
            h = h->next;
            (*p)++;
        }
    }

    return FALSE;
}

/*
函数功能：获取元素位置
函数参数：表头 元素位置
函数返回值：FAILURE SUCCESS 元素
*/
int GetElem(pnode h, int p)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pnode n = h->next;
    int i;
    for (i = 0; i < p; i++)
    {
        n = n->next;
        if (NULL == n)
        {
            return FALSE;
        }
    }

    return n->data;
}

/*
函数功能：删除元素
函数参数：表头指针 元素内容
函数返回值：FAILURE(失败) n_count(节点位置) FALSE(未找到元素)
*/
int DeleteElem(pnode h, int e)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pnode n = h->next;
    int n_count = 0;
    while(n)
    {
        if (n->data == e)
        {
            pnode pro_n = h->next;
            int i;
            for (i = 0; i < n_count - 1; i++)
            {
                pro_n = pro_n->next; //也是从1开始的
            }
            pro_n->next = n->next;
            n->next = NULL;
            free(n);
            return n_count;
        }
        n = n->next;
        n_count++;
    }

    return FALSE;
}

/*
函数功能：删除链表
函数参数：表头指针
函数返回值：SUCCESS FAILURE
*/
int DeleteList(pnode *h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pnode p = (*h)->next;
    pnode q;
    while(p)
    {
    q = p->next;
    free(p);
    p = q;
    }
    (*h)->next = NULL;
    return SUCCESS;
}

/*
函数功能：反转链表
函数参数：表头
函数返回值：FAILURE SUCCESS
*/
int ReverseList(pnode h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pnode p = h->next;
    h->next = NULL;
    while(p != NULL)
    {
        pnode q = p;
        p = p->next;
        q->next = h->next;
        h->next = q;
    }
}

/*测试*/
int ts(pnode h)
{
    h->next = h->next->next->next;
}

/*
函数功能：输出前驱元素
函数参数：表头 元素
函数返回值：FAILURE SUCCESS
*/
int PriorLink(pnode h, int e)
{
    if (NULL == h || NULL == h->next)
    {
        return FAILURE;
    }

    pnode p = h->next;
    while(p)
    {
        if (p->next->data == e)
        {
            return p->data;
        }
        p = p->next;
        if (h->next->data = e)
        {
            return SUCCESS;
        }
    }

    return FAILURE;
}

/*
函数功能：输出后继元素
函数参数：表头 元素
函数返回值：FAILURE SUCCESS
*/
int NextLink(pnode h, int e)
{
    if (NULL == h || NULL == h->next)
    {
        return FAILURE;
    }

    pnode p = h->next;

    while(p)
    {
        if (p->data == e)
        {
            return p->next->data;
        }
        p = p->next;
        if (p->next == NULL)
        {
            return SUCCESS;
        }
    }

    return FAILURE;
}