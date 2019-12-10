#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"
#include <time.h>

int main()
{
    stack seq;
    int ret = InitStack(&seq);  //��ʼ��ջ
    if (SUCCESS == ret)
    {
        printf("��ʼ���ɹ���\n");
    }
    else
    {
        printf("��ʼ��ʧ�ܣ�\n");
    }

    ret = EmptyStack(seq);  //�ж�ջ�Ƿ�Ϊ��
    if (TRUE == ret)
    {
        printf("��ջ��\n");
    }
    else
    {
        printf("���ǿ�ջ��\n");
    }
    
    srand(time(NULL));
    int data,i = 0;
    for (i = 0; i < SIZE + 10; i++)
    {
        data = rand() % 1000;
        ret = Pushdata(&seq, data);     //��ջ
        if (SUCCESS == ret)
        {
            printf("����%d��ջ�ɹ���\n", data);
        }
        else
        {
            printf("����%d��ջʧ�ܣ�\n", data);
        }
    }

    ret = EmptyStack(seq);  //�ж�ջ�Ƿ�Ϊ��
    if (TRUE == ret)
    {
        printf("��ջ��\n");
    }
    else
    {
        printf("���ǿ�ջ��\n");
    }

    ret = StackTop(seq);    //ջ��Ԫ��
    if (FAILURE == ret)
    {
        printf("��ջ\n");
    }
    else
    {
        printf("ջ��Ԫ��Ϊ%d\n", ret);
    }

    ret = LengthStack(seq);     //ջ�ĳ���
    printf("ջ����Ϊ��%d\n",ret);
    
    for(i = 0; i < 5; i++)
    {
        ret = PopStack(&seq);   //��ջ
        if (FAILURE == ret)
        {
            printf("��ջʧ�ܣ�\n");
        }
        else
        {
            printf("Ԫ��%d��ջ�ɹ���\n", ret);
        }
    }

    ret = LengthStack(seq);     //ջ�ĳ���
    printf("ջ����Ϊ��%d\n", ret);
    
    delStack(&seq);     //ɾ��ջ��Ԫ��

    ret = LengthStack(seq);     //ջ�ĳ���
    printf("ջ����Ϊ��%d\n", ret);

    ClearStack(&seq);   //��ջ

    ret = LengthStack(seq);     //ջ�ĳ���
    printf("ջ����Ϊ��%d\n", ret);

    DestroyStack(&seq);     //����ջ
    ret = EmptyStack(seq);  //�ж�ջ�Ƿ�Ϊ��
    if (TRUE == ret)
    {
        printf("��ջ��\n");
    }
    else
    {
        printf("���ǿ�ջ��\n");
    }

    for (i = 0; i < 5; i++)
    {
        data = rand() % 1000;
        ret = Pushdata(&seq, data);     //��ջ
        if (SUCCESS == ret)
        {
            printf("����%d��ջ�ɹ���\n", data);
        }
        else
        {
            printf("����%d��ջʧ�ܣ�\n", data);
        }
    }

    return 0;
}