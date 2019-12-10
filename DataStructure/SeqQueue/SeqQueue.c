#include "SeqQueue.h"
#include <stdio.h>
#include <stdlib.h>

/*
�������ܣ���ʼ������
��������������ָ���ַ
��������ֵ��FAILURE SUCCESS
*/
int InitQueue(pque *q)
{
    if (NULL == q)
    {
        return FAILURE;
    }

    (*q) = (pque)malloc(sizeof(que) * 1);

    (*q)->front = 0;
    (*q)->rear = 0;
    return SUCCESS;
}

/*
�������ܣ�����Ԫ��
��������������ָ��
��������ֵ��FAILURE SUCCESS
*/
int EnQueue(pque q, int e)
{
    if (NULL == q || q->front == (q->rear + 1) % SIZE)
    {
        return FAILURE;
    }


    q->data[q->rear] = e;
    if(SIZE - 1 == q->rear)
    {
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }

    return SUCCESS;
}

/*
�������ܣ��ж��Ƿ�Ϊ�ն�
��������������ָ��
��������ֵ��TRUE FALSE
*/
int EmptyQueue(pque q)
{
    return (q->front == q->rear) ? TRUE : FALSE;
}

/*
�������ܣ��鿴�ӳ�
��������������ָ��
��������ֵ�����г���
*/
int LengthQueue(pque q)
{
    return NULL == q ? FAILURE : (q->rear - q->front + SIZE) % SIZE;
}

/*
�������ܣ��鿴��ͷ
��������������ָ��
��������ֵ����ͷ FAILURE
*/
int GetHead(pque q)
{
    return ((NULL == q) || (q->front == q->rear)) ? FAILURE : q->data[q->front];
}

/*
�������ܣ�Ԫ�س���
��������������ָ��
��������ֵ������Ԫ�� FAILURE
*/
int DeQueue(pque q)
{
    if(NULL == q || q->front == q->rear)
    {
        return FAILURE;
    }

    int e = q->data[q->front];
    if (q->front < SIZE - 1)
    {
        q->front++;
    }
    else
    {
        q->front = 0;
    }
    
    return e;
}

/*
�������ܣ���ն���
��������������ָ��
��������ֵ��SUCCESS FAILURE
*/
int ClearQueue(pque q)
{
    if (NULL == q)
    {
        return FAILURE;
    }

    while(q->front != q->rear)
    {
        q->data[q->front] = 0;
        q->front++;
    }

    return SUCCESS;
}

/*
�������ܣ��ݻٶ���
��������������ָ��
��������ֵ��SUCCESS FAILURE
*/
int DestroyQueue(pque *q)
{
    if(NULL == q)
    {
        return FAILURE;
    }

    free(*q);
    (*q) = NULL;

    return SUCCESS;
}

