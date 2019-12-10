#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkList.h"

int main()
{
    node *head = NULL;     //创建表头

    //初始化表头
    int ret = InitLink(&head);
    if (SUCCESS == ret)
    {
        printf("初始化成功\n");
    }
    else
    {
        printf("初始化失败\n");
    }

    //初始化链表（给链表插入数据）
    int i, p, num;
    srand(time(NULL));
    for (i = 0; i < 100; i++)
    {
        p = rand() % (i + 1);
        num = rand() % 10;
        ret = InsertLink(head, p, num);
        if (SUCCESS == ret)
        {
            printf("第%d位插入%d成功\n", p, num);
        }
        else
        {
            printf("第%d位插入%d失败\n", p, num);
        }
    }
    
    //确认链表是否为空
    ret = LinkEmpty(head);
    if (TURE == ret)
    {
        printf("链表为空\n");
    }
    else if (FAILURE == ret)
    {
        printf("判断失败\n");
    }
    else
    {
        printf("链表不为空\n");
    }

    //输出链表
    printf("链表数据如下：");
    ret = TraverseLink(head);
    if (SUCCESS == ret)
    {
        printf("输出链表成功\n");
    }
    else
    {
        printf("输出链表失败\n");
    }

    //定位元素位置
    int elem = 6;
    int posi = 1;
    ret = LocateElem(head, elem, &posi);
    if (SUCCESS == ret)
    {
        printf("元素%d的位置为%d\n", elem, posi);
    }
    else if (FAILURE == ret)
    {
        printf("寻找元素失败\n");
    }
    else
    {
        printf("未找到元素\n");
    }

    //获取某位置的元素
    posi = 10;
    ret = GetElem(head, posi);
    if (FAILURE == ret)
    {
        printf("定位元素失败\n");
    }
    else if (FALSE == ret)
    {
        printf("第%d个元素不存在\n", posi);
    }
    else
    {
        printf("第%d个元素为%d\n", posi, ret);
    }
    
    //删除元素
    int deleteElem = 5;
    ret = DeleteElem(head, deleteElem);
    if (FALSE == ret)
    {
        printf("节点未找到\n");
    }
    else if (FAILURE == ret)
    {
        printf("节点删除失败\n");
    }
    else
    {
        printf("内容为%d的第%d号节点删除成功\n", deleteElem, ret);
    }
    
    printf("链表数据如下：");
    ret = TraverseLink(head);
    if (SUCCESS == ret)
    {
        printf("输出链表成功\n");
    }
    else
    {
        printf("输出链表失败\n");
    }

/*
    //删除链表
    ret = DeleteList(&head);
    if(SUCCESS ==  ret)
    {
        printf("链表删除成功\n");
    }
    else
    {
        printf("链表删除失败\n");
    }
*/

    printf("链表数据如下：");
    ret = TraverseLink(head);
    if (SUCCESS == ret)
    {
        printf("输出链表成功\n");
    }
    else
    {
        printf("输出链表失败\n");
    }

    ReverseList(head);
    printf("输出链表：");
    TraverseLink(head);
    printf("\n");
/*
    ts(head);
    printf("输出链表：");
    TraverseLink(head);
    printf("\n");
*/

    return 0;
}