#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#define FAILURE    1000
#define SUCCESS    1001
#define SIZE       20
#define TRUE       1003
#define FALSE      1004

struct SeqStack
{
    int *data;
    int top;
};
typedef struct SeqStack stack;
typedef stack *pstack;

int InitStack(stack *s);
int Pushdata(pstack s, int data);
int EmptyStack(stack s);
int StackTop(stack s);
int PopStack(pstack s);
int LengthStack(stack s);
int DestroyStack(pstack s);
int ClearStack(pstack s);
int delStack(pstack s);

#endif 