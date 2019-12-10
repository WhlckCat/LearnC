#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"
#include <time.h>

int main()
{
    stack seq;
    int ret = InitStack(&seq);  //初始化栈
    if (SUCCESS == ret)
    {
        printf("初始化成功！\n");
    }
    else
    {
        printf("初始化失败！\n");
    }

    ret = EmptyStack(seq);  //判断栈是否为空
    if (TRUE == ret)
    {
        printf("空栈！\n");
    }
    else
    {
        printf("不是空栈！\n");
    }
    
    srand(time(NULL));
    int data,i = 0;
    for (i = 0; i < SIZE + 10; i++)
    {
        data = rand() % 1000;
        ret = Pushdata(&seq, data);     //入栈
        if (SUCCESS == ret)
        {
            printf("数据%d入栈成功！\n", data);
        }
        else
        {
            printf("数据%d入栈失败！\n", data);
        }
    }

    ret = EmptyStack(seq);  //判断栈是否为空
    if (TRUE == ret)
    {
        printf("空栈！\n");
    }
    else
    {
        printf("不是空栈！\n");
    }

    ret = StackTop(seq);    //栈顶元素
    if (FAILURE == ret)
    {
        printf("空栈\n");
    }
    else
    {
        printf("栈顶元素为%d\n", ret);
    }

    ret = LengthStack(seq);     //栈的长度
    printf("栈长度为：%d\n",ret);
    
    for(i = 0; i < 5; i++)
    {
        ret = PopStack(&seq);   //出栈
        if (FAILURE == ret)
        {
            printf("出栈失败！\n");
        }
        else
        {
            printf("元素%d出栈成功！\n", ret);
        }
    }

    ret = LengthStack(seq);     //栈的长度
    printf("栈长度为：%d\n", ret);
    
    delStack(&seq);     //删除栈顶元素

    ret = LengthStack(seq);     //栈的长度
    printf("栈长度为：%d\n", ret);

    ClearStack(&seq);   //清栈

    ret = LengthStack(seq);     //栈的长度
    printf("栈长度为：%d\n", ret);

    DestroyStack(&seq);     //销毁栈
    ret = EmptyStack(seq);  //判断栈是否为空
    if (TRUE == ret)
    {
        printf("空栈！\n");
    }
    else
    {
        printf("不是空栈！\n");
    }

    for (i = 0; i < 5; i++)
    {
        data = rand() % 1000;
        ret = Pushdata(&seq, data);     //入栈
        if (SUCCESS == ret)
        {
            printf("数据%d入栈成功！\n", data);
        }
        else
        {
            printf("数据%d入栈失败！\n", data);
        }
    }

    return 0;
}