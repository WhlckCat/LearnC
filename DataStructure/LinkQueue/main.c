#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

int main()
{
    int ret,i;
    queue que;
    ret = InitLinkQueue(&que);
    if (SUCCESS == ret)
    {
        printf("Init success!\n");
    }
    else
    {
        printf("Init failure!\n");
    }

    for (i = 0; i < 10; i++)
    {
        ret = EnLinkQueue(&que,i);
        if (SUCCESS == ret)
        {
            printf("Insert element %d success!\n", i);
        }
        else
        {
            printf("Insert element %d failure!\n", i);
        }
    }

    for (i = 0; i < 5; i++)
    {
        ret = DeLinkQueue(&que);
        if (FAILURE == ret)
        {
            printf("The element output is failure!\n");
        }
        else
        {
            printf("THe element %d output success!\n", ret);
        }
    }

    return 0;
}