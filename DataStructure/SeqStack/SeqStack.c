#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

/*
�������ܣ���ʼ��ջ
����������ջָ��
��������ֵ�� FAILURE SUCCESS
*/
int InitStack(pstack s)
{
    if (NULL == s)
    {
        return FAILURE;
    }

    s->data = (int *)malloc(sizeof(int) * SIZE);
    if (NULL == s->data)
    {
        return FAILURE;
    }

    s->top = -1;
    return SUCCESS;
}

/*
�������ܣ���ջ
����������ջָ�� ��ջԪ��
��������ֵ��FAILURE SUCCESS
*/
int Pushdata(pstack s, int data)
{
    if (NULL == s || NULL == s->data || SIZE - 1 == s->top)
    {
        return FAILURE;
    }

    s->data[++(s->top)] = data;

    return SUCCESS;
}

/*
�������ܣ��ж��Ƿ�Ϊ��ջ
����������ջ
��������ֵ��TRUE FALSE
*/
int EmptyStack(stack s)
{
    return (s.top == -1) ? TRUE : FALSE;
}

/*
�������ܣ�ջ��Ԫ��
����������ջ
��������ֵ��ջ��Ԫ�� FAILURE
*/
int StackTop(stack s)
{
    return (s.top == -1) ? FAILURE : s.data[s.top];
}

/*
�������ܣ���ջ
����������ջ
��������ֵ��FAILURE ��ջԪ��
*/
int PopStack(pstack s)
{
    if (NULL == s || -1 == s->top)
    {
        return FAILURE;
    }

    return s->data[s->top--];
}

/*
�������ܣ���ѯջ����
����������ջ
��������ֵ��ջ����
*/
int LengthStack(stack s)
{
    return s.top + 1;
}

/*
�������ܣ���ջ
����������ջ
��������ֵ��FAILURE SUCCESS
*/
int ClearStack(pstack s)
{
    if (NULL == s)
    {
        return FAILURE;
    }

    s->top = -1;
    return SUCCESS;
}

/*
�������ܣ�����ջ
����������ջ
��������ֵ��FAILURE SUCCESS
*/
int DestroyStack(pstack s)
{
    if (NULL == s)
    {
        return FAILURE;
    }

    free(s->data);
    s->data = NULL;
    return SUCCESS;
}

/*
�������ܣ�ɾ��ջ��Ԫ��
����������ջ
��������ֵ��FAILURE SUCCESS
*/
int delStack(pstack s)
{
    if (NULL == s)
    {
        return FAILURE;
    }

    s->top--;
    return SUCCESS;
}