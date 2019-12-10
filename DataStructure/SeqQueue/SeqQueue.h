#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#define SIZE    10
#define SUCCESS 10001
#define FAILURE 10000
#define TRUE    10002
#define FALSE   10003

struct Queue
{
    int data[SIZE];
    int front;
    int rear;
};
typedef struct  Queue que;
typedef que *pque;

int InitQueue(pque *q);
int EnQueue(pque q, int e);
int EmptyQueue(pque q);
int LengthQueue(pque q);
int DeQueue(pque q);
int GetHead(pque q);
int ClearQueue(pque q);
int DestroyQueue(pque *q);

#endif