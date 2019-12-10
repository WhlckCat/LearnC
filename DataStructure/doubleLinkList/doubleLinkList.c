#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkList.h"

/*
函数功能：初始化双向链表
函数参数：表头地址 表尾地址
函数返回值：SUCCESS FAILURE
*/
int Init_dulLinkList(pdul *h, pdul *t)
{
    if(NULL == h || NULL ==t)
    {
        return FAILURE;
    }

    (*h) = (pdul)malloc(sizeof(dul) * 1);
    (*t) = (pdul)malloc(sizeof(dul) * 1);
    if (NULL == *h || NULL == *t)
    {
        return FAILURE;
    }

    (*h)->nextNode = *t;
    //(*h)->preNode = *t;   //循环链表
    (*h)->preNode = NULL;

    (*t)->nextNode = NULL;
    //(*t)->preNode = *h;   //循环链表
    (*t)->preNode = *t;
    return SUCCESS;
}

/*
函数功能：插入元素(前插法)
函数参数：表头 元素数据
函数返回值：SUCCESS FAILURE
*/
int InsertElem(pdul h, int e)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    pdul m = (pdul)malloc(sizeof(dul) * 1);

    m->data = e;

    m->nextNode = h->nextNode;
    m->preNode = h;

    h->nextNode->preNode = m;
    h->nextNode = m;

    //dulLength++;  链表长度加1
    return SUCCESS;
}

/*
函数功能：调用元素
函数参数：表头 元素指针地址 元素信息匹配
函数返回值：SUCCESS FAILURE
*/
int getElem(pdul h, pdul *elem, int e)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    (*elem) = (pdul)malloc(sizeof(dul) * 1);
    (*elem) = h->nextNode;

    while(*elem)
    {
        if((*elem)->data == e)
        {
            return SUCCESS;
        }
        else
        {
            (*elem) = (*elem)->nextNode;
        }
    }

    return FAILURE;
}

/*
函数功能：删除元素
函数参数：表头 元素信息匹配
函数返回值：SUCCESS FAILURE
*/
int DeleteElem(pdul h, int e)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    h = h->nextNode;
    while(h)
    {
        if (h->data == e)
        {
            //维持删除元素后的链表
            h->nextNode->preNode = h->preNode;
            h->preNode->nextNode = h->nextNode;
            free(h);
            return SUCCESS;
        }
        else
        {
            h = h->nextNode;
        }
    }

    return FAILURE;
}

/*
函数功能：输出链表元素（从表头打印）
函数参数：表头
函数返回值：SUCCESS FAILURE
*/
int printLinkList(pdul h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    h = h->nextNode;
    while(h)
    {
        if (h->nextNode == NULL)
        {
            break;
        }
        printf("%d ", h->data);
        h = h->nextNode;
    }
    printf("\n");

    return SUCCESS;
}

/*
函数功能：删除链表（从头开始删）
函数参数：表头 表尾
函数返回值：SUCCESS FAILURE
*/
int DeleteList(pdul h, pdul t)
{
    if (NULL == h || NULL == t)
    {
        return FAILURE;
    }

    h = h->nextNode;
    pdul m;
    while(h)
    {
        if (h->nextNode == NULL)
        {
            break;
        }
        //维持删除元素后的链表
        h->preNode->nextNode = h->nextNode;
        h->nextNode->preNode = h->preNode;

        m = h->nextNode;
        free(h);
        h = m;
    }

    return SUCCESS;
}