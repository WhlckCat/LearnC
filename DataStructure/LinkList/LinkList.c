#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
�������ܣ���ʼ�������ͷ
������������ͷ��ַ
��������ֵ��SUCCESS FAILURE
*/
int InitLink(pnode *h)  //������Ҫ�޸�ʵ��ָ�����ݣ����Ժ���������Ҫ˫��ָ��
{
    if (h == NULL)
    {
        printf("��ʼ��ʧ��\n");
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
�������ܣ��������ֵ
������������ͷ ����λ�� ����Ԫ��
��������ֵ��FAILURE SUCCESS
*/
int InsertLink(pnode h, int p, int e)   //�����������ֵ�����Ҫ�����λ��ǰ�治���ڣ��Ͳ���ʧ��
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
�������ܣ�ȷ�������Ƿ�Ϊ��
������������ͷ
��������ֵ��FAILURE SUCCESS
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
�������ܣ��������
������������ͷ
��������ֵ��SUCCESS FAILURE
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
�������ܣ���λԪ��
������������ͷ Ԫ�� Ԫ��λ��
��������ֵ��SUCCESS FAILURE
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
�������ܣ���ȡԪ��λ��
������������ͷ Ԫ��λ��
��������ֵ��FAILURE SUCCESS Ԫ��
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
�������ܣ�ɾ��Ԫ��
������������ͷָ�� Ԫ������
��������ֵ��FAILURE(ʧ��) n_count(�ڵ�λ��) FALSE(δ�ҵ�Ԫ��)
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
                pro_n = pro_n->next; //Ҳ�Ǵ�1��ʼ��
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
�������ܣ�ɾ������
������������ͷָ��
��������ֵ��SUCCESS FAILURE
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
�������ܣ���ת����
������������ͷ
��������ֵ��FAILURE SUCCESS
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

/*����*/
int ts(pnode h)
{
    h->next = h->next->next->next;
}

/*
�������ܣ����ǰ��Ԫ��
������������ͷ Ԫ��
��������ֵ��FAILURE SUCCESS
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
�������ܣ�������Ԫ��
������������ͷ Ԫ��
��������ֵ��FAILURE SUCCESS
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