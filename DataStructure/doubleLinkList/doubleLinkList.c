#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkList.h"

/*
�������ܣ���ʼ��˫������
������������ͷ��ַ ��β��ַ
��������ֵ��SUCCESS FAILURE
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
    //(*h)->preNode = *t;   //ѭ������
    (*h)->preNode = NULL;

    (*t)->nextNode = NULL;
    //(*t)->preNode = *h;   //ѭ������
    (*t)->preNode = *t;
    return SUCCESS;
}

/*
�������ܣ�����Ԫ��(ǰ�巨)
������������ͷ Ԫ������
��������ֵ��SUCCESS FAILURE
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

    //dulLength++;  �����ȼ�1
    return SUCCESS;
}

/*
�������ܣ�����Ԫ��
������������ͷ Ԫ��ָ���ַ Ԫ����Ϣƥ��
��������ֵ��SUCCESS FAILURE
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
�������ܣ�ɾ��Ԫ��
������������ͷ Ԫ����Ϣƥ��
��������ֵ��SUCCESS FAILURE
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
            //ά��ɾ��Ԫ�غ������
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
�������ܣ��������Ԫ�أ��ӱ�ͷ��ӡ��
������������ͷ
��������ֵ��SUCCESS FAILURE
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
�������ܣ�ɾ��������ͷ��ʼɾ��
������������ͷ ��β
��������ֵ��SUCCESS FAILURE
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
        //ά��ɾ��Ԫ�غ������
        h->preNode->nextNode = h->nextNode;
        h->nextNode->preNode = h->preNode;

        m = h->nextNode;
        free(h);
        h = m;
    }

    return SUCCESS;
}