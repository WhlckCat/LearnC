#include <stdlib.h>
#include <stdio.h>
#include "LinkStack.h"
#include <time.h>

int main()
{
    stack head;
    int ret = InitStack1(&head);
    if (FAILURE == ret)
    {
        printf("初始化失败！\n");
    }
    else
    {
        printf("初始化成功！\n");
    }

    srand(time(NULL));
    int i,data;
    for (i = 0; i < 5; i++)
    {
        data = rand() % 100;
        ret = PushStack1(&head, data);
        if (SUCCESS == ret)
        {
            printf("%d入栈成功\n", data);
        }
        else
        {
            printf("%d入栈失败\n", data);
        }
    }

    ret = LengthStack1(head);
    if (FAILURE == ret)
    {
        printf("空栈！\n");
    }
    else
    {
        printf("栈长度为：%d\n", ret);
    }
    
    ret = PopStack1(&head);
    if (FAILURE == ret)
    {
        printf("出栈失败!\n");
    }
    else
    {
        printf("%d出栈成功!\n", ret);
    }
    
    ret = LengthStack1(head);
    if (FAILURE == ret)
    {
        printf("空栈！\n");
    }
    else
    {
        printf("栈长度为：%d\n", ret);
    }

    ret = clearStack(&head);
    if (FAILURE == ret)
    {
        printf("清栈失败！\n");
    }
    else
    {
        printf("清栈成功！\n");
    }

    return 0;
}