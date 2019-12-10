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

int InitStack1(stack *h);
int PushStack1(stack *h, int data);
int LengthStack1(stack h);
int PopStack1(stack *h);
int clearStack(stack *h);

#endif