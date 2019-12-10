#include "SeqQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    pque queue;
    int ret = InitQueue(&queue);
    if (SUCCESS == ret)
    {
        printf("Init Success!\n");
    }
    else
    {
        printf("Init Failure!\n");
    }

    ret = EmptyQueue(queue);
    if (TRUE == ret)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue is not empty!\n");
    }

    srand(time(NULL));
    int i = 0,data;
    for (i = 0; i < 5; i++)
    {
        data = rand() % 100;
        ret = EnQueue(queue, data);
        printf("Insert element %d success!\n", data);
    }
    for (i = 0; i < queue->rear; i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");

    ret = LengthQueue(queue);
    printf("The length of the queue is %d\n", ret);

    for(i = 0; i < 4; i++)
    {
        ret = DeQueue(queue);
        printf("The element %d is out of the queue!\n", ret);
    }
    ret = LengthQueue(queue);
    printf("The length of the queue is %d\n", ret);

    for (i = 0; i < 7; i++)
    {
        data = rand() % 100;
        ret = EnQueue(queue, data);
        printf("Insert element %d success!\n", data);
    }

    ret = LengthQueue(queue);
    printf("The length of the queue is %d\n", ret);

    ret = GetHead(queue);
    printf("The head of the queue is %d\n", ret);

    ret = ClearQueue(queue);
    if(SUCCESS == ret)
    {
        printf("Clear is success!\n");
    }
    ret = LengthQueue(queue);
    printf("The length of the queue is %d\n", ret);

    ret = DestroyQueue(&queue);
    if (SUCCESS == ret)
    {
        printf("Destory is success!\n");
    }

    return 0;
}