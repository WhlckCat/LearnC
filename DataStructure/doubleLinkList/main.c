#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkList.h"

int main()
{
    //初始化
    pdul head, tail, elem;
    elem = (pdul)malloc(sizeof(dul) * 1);
    int ret;
    Init_dulLinkList(&head, &tail);

    //打印链表
    printLinkList(head);
    //插入元素
    int i;
    for (i = 0; i < 20; i++)
    {
        InsertElem(head, i);
    }
    //打印链表
    printLinkList(head);

    //调用元素
    i = 15;
    ret = getElem(head, &elem, i);
    if (SUCCESS == ret)
    {
        printf("获取元素成功\n");
        printf("元素为：%d\n", elem->data);
    }
    else
    {
        printf("获取元素失败\n");
    }

    //删除元素
    i = 10;
    DeleteElem(head, i);
    //打印链表
    printLinkList(head);

    //删除链表
    ret = DeleteList(head, tail);
    if (SUCCESS == ret)
    {
        printf("删除成功");
    }
    //打印链表
    printLinkList(head);
    
    return 0;
}