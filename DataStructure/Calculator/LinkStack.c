#include "LinkStack.h"
#include <stdlib.h>

int initStack1(stack *h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    h->top = (node *)malloc(sizeof(node) * 1);
    h->length = 0;
    h->top = NULL;

    return SUCCESS;
}

int pushStack1(stack *h, int data)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    h->length++;
    node *m;
    m = (node *)malloc(sizeof(node) * 1);
    m->next = h->top;
    m->data = data;
    h->top = m;

    return SUCCESS;
}

int lengthStack1(stack h)
{
    return (NULL == h.top) ? FAILURE : h.length;
}

int popStack1(stack *h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    node *m;
    m = h->top;
    int i;
    i = m->data;
    h->top = h->top->next;
    free(m);
    h->length--;
    return i;
}

int clearStack(stack *h)
{
    if (NULL == h)
    {
        return FAILURE;
    }

    node *n = h->top;
    while(n)
    {
        h->top = h->top->next;
        free(n);
        n = h->top;
    }

    h->length = 0;
    return SUCCESS;
}

int emptyStack(stack s)
{
    return (NULL == s.top) ? SUCCESS : FAILURE;
}

int gettop(stack s)
{
    return s.top->data;
}