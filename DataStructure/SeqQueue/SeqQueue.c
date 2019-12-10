#include "SeqQueue.h"
#include <stdio.h>
#include <stdlib.h>

/*
函数功能：初始化队列
函数参数：队列指针地址
函数返回值：FAILURE SUCCESS
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
函数功能：插入元素
函数参数：队列指针
函数返回值：FAILURE SUCCESS
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
函数功能：判断是否为空队
函数参数：队列指针
函数返回值：TRUE FALSE
*/
int EmptyQueue(pque q)
{
    return (q->front == q->rear) ? TRUE : FALSE;
}

/*
函数功能：查看队长
函数参数：队列指针
函数返回值：队列长度
*/
int LengthQueue(pque q)
{
    return NULL == q ? FAILURE : (q->rear - q->front + SIZE) % SIZE;
}

/*
函数功能：查看队头
函数参数：队列指针
函数返回值：队头 FAILURE
*/
int GetHead(pque q)
{
    return ((NULL == q) || (q->front == q->rear)) ? FAILURE : q->data[q->front];
}

/*
函数功能：元素出队
函数参数：队列指针
函数返回值：出队元素 FAILURE
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
函数功能：清空队列
函数参数：队列指针
函数返回值：SUCCESS FAILURE
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
函数功能：摧毁队列
函数参数：队列指针
函数返回值：SUCCESS FAILURE
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

