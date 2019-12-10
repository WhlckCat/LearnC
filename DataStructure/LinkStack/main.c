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
        printf("��ʼ��ʧ�ܣ�\n");
    }
    else
    {
        printf("��ʼ���ɹ���\n");
    }

    srand(time(NULL));
    int i,data;
    for (i = 0; i < 5; i++)
    {
        data = rand() % 100;
        ret = PushStack1(&head, data);
        if (SUCCESS == ret)
        {
            printf("%d��ջ�ɹ�\n", data);
        }
        else
        {
            printf("%d��ջʧ��\n", data);
        }
    }

    ret = LengthStack1(head);
    if (FAILURE == ret)
    {
        printf("��ջ��\n");
    }
    else
    {
        printf("ջ����Ϊ��%d\n", ret);
    }
    
    ret = PopStack1(&head);
    if (FAILURE == ret)
    {
        printf("��ջʧ��!\n");
    }
    else
    {
        printf("%d��ջ�ɹ�!\n", ret);
    }
    
    ret = LengthStack1(head);
    if (FAILURE == ret)
    {
        printf("��ջ��\n");
    }
    else
    {
        printf("ջ����Ϊ��%d\n", ret);
    }

    ret = clearStack(&head);
    if (FAILURE == ret)
    {
        printf("��ջʧ�ܣ�\n");
    }
    else
    {
        printf("��ջ�ɹ���\n");
    }

    return 0;
}