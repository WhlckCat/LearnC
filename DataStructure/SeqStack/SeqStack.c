#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

/*
函数功能：初始化栈
函数参数：栈指针
函数返回值： FAILURE SUCCESS
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
函数功能：入栈
函数参数：栈指针 入栈元素
函数返回值：FAILURE SUCCESS
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
函数功能：判断是否为空栈
函数参数：栈
函数返回值：TRUE FALSE
*/
int EmptyStack(stack s)
{
    return (s.top == -1) ? TRUE : FALSE;
}

/*
函数功能：栈顶元素
函数参数：栈
函数返回值：栈顶元素 FAILURE
*/
int StackTop(stack s)
{
    return (s.top == -1) ? FAILURE : s.data[s.top];
}

/*
函数功能：出栈
函数参数：栈
函数返回值：FAILURE 出栈元素
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
函数功能：查询栈长度
函数参数：栈
函数返回值：栈长度
*/
int LengthStack(stack s)
{
    return s.top + 1;
}

/*
函数功能：清栈
函数参数：栈
函数返回值：FAILURE SUCCESS
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
函数功能：销毁栈
函数参数：栈
函数返回值：FAILURE SUCCESS
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
函数功能：删除栈顶元素
函数参数：栈
函数返回值：FAILURE SUCCESS
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