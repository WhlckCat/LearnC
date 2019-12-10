#ifndef LINKSTACK_H
#define LINKSTACK_H

#define FAILURE     10000
#define SUCCESS     10001

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

struct Stack
{
    node *top;
    int length;
};
typedef struct Stack stack;

int initStack(stack *h);
int pushStack(stack *h, int data);
int lengthStack(stack h);
int popStack(stack *h);
int clearStack(stack *h);
int emptyStack(stack s);
int gettop(stack s);

#endif