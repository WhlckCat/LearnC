#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#define SUCCESS 10001
#define FAILURE 10000
#define TRUE    10002
#define FALSE   10003

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

struct Queue
{
    node *front;
    node *rear;
};
typedef struct Queue queue;

int InitLinkQueue(queue *q);
int EnLinkQueue(queue *q, int e);
int DeLinkQueue(queue *q);
#endif