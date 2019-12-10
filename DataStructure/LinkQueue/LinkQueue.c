#include "LinkQueue.h"
#include <stdlib.h>

int InitLinkQueue(queue *q)
{
    if(NULL == q)
    {
        return FAILURE;
    }

    q->front = (node *)malloc(sizeof(node) * 1);
    q->front->next = NULL;
    q->rear = q->front;

    return SUCCESS;
}

int EnLinkQueue(queue *q, int e)
{
    if(NULL == q)
    {
        return FAILURE;
    }

    node *n = (node *)malloc(sizeof(node) * 1);
    n->data = e;
    n->next = NULL;
    q->rear->next = n;
    q->rear = n;

    return SUCCESS;
}

int DeLinkQueue(queue *q)
{
    if(NULL == q)
    {
        return FAILURE;
    }

    int e = q->front->next->data;
    node *n = (node *)malloc(sizeof(node) * 1);
    n = q->front->next;
    q->front->next = q->front->next->next;
    free(n);
    return e;
}