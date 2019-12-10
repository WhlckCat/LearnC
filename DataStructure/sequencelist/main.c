#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sequencelist.h"

int equal(int a, int b)
{
    return a == b;
}

int main()
{
    List list;
    int ret = InitList(&list);
    if (SUCCESS == ret)
    {
        printf("初始化成功\n");
    }
    else
    {
        printf("初始化失败\n");
    }

    int i, num;
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)   //循环插入数据
    {
        num = rand() % 10;
        ret = InsertList(&list, i + 1, num);
        if (FAILURE == ret)
        {
            printf("插入%d失败\n", num);
        }
        else
        {
            printf("插入%d成功\n", num);
        }
    }

    int p;
    num = 6;
    ret = locateElem(list, num, &p, &equal);   //函数指针�?
    //ret = locateElem(list, num, &p)    //普通版
    if (ret == FAILURE)
    {
        printf("未找到数据\n");
    }
    if (ret == SUCCESS)
    {
        printf("已成功找到\n");
    }

    ret = ClearList(&list);
    if (FAILURE == ret)
    {
        printf("清空失败\n");
    }
    if (SUCCESS == ret)
    {
        printf("清空成功\n");
    }

    ret = DesList(&list);
    if (FAILURE == ret)
    {
        printf("摧毁失败\n");
    }
    if (SUCCESS == ret)
    {
        printf("摧毁成功\n");
    }

    srand(time(NULL));
    for (i = 0; i < SIZE; i++)   //循环插入数据
    {
        num = rand() % 10;
        ret = InsertList(&list, i + 1, num);
        if (FAILURE == ret)
        {
            printf("插入%d失败\n", num);
        }
        else
        {
            printf("插入%d成功\n", num);
            
        }
    }
    //printf("���Ǵ����\n");
    return 0;
}