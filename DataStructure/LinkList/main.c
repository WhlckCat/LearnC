#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkList.h"

int main()
{
    node *head = NULL;     //������ͷ

    //��ʼ����ͷ
    int ret = InitLink(&head);
    if (SUCCESS == ret)
    {
        printf("��ʼ���ɹ�\n");
    }
    else
    {
        printf("��ʼ��ʧ��\n");
    }

    //��ʼ������������������ݣ�
    int i, p, num;
    srand(time(NULL));
    for (i = 0; i < 100; i++)
    {
        p = rand() % (i + 1);
        num = rand() % 10;
        ret = InsertLink(head, p, num);
        if (SUCCESS == ret)
        {
            printf("��%dλ����%d�ɹ�\n", p, num);
        }
        else
        {
            printf("��%dλ����%dʧ��\n", p, num);
        }
    }
    
    //ȷ�������Ƿ�Ϊ��
    ret = LinkEmpty(head);
    if (TURE == ret)
    {
        printf("����Ϊ��\n");
    }
    else if (FAILURE == ret)
    {
        printf("�ж�ʧ��\n");
    }
    else
    {
        printf("����Ϊ��\n");
    }

    //�������
    printf("�����������£�");
    ret = TraverseLink(head);
    if (SUCCESS == ret)
    {
        printf("�������ɹ�\n");
    }
    else
    {
        printf("�������ʧ��\n");
    }

    //��λԪ��λ��
    int elem = 6;
    int posi = 1;
    ret = LocateElem(head, elem, &posi);
    if (SUCCESS == ret)
    {
        printf("Ԫ��%d��λ��Ϊ%d\n", elem, posi);
    }
    else if (FAILURE == ret)
    {
        printf("Ѱ��Ԫ��ʧ��\n");
    }
    else
    {
        printf("δ�ҵ�Ԫ��\n");
    }

    //��ȡĳλ�õ�Ԫ��
    posi = 10;
    ret = GetElem(head, posi);
    if (FAILURE == ret)
    {
        printf("��λԪ��ʧ��\n");
    }
    else if (FALSE == ret)
    {
        printf("��%d��Ԫ�ز�����\n", posi);
    }
    else
    {
        printf("��%d��Ԫ��Ϊ%d\n", posi, ret);
    }
    
    //ɾ��Ԫ��
    int deleteElem = 5;
    ret = DeleteElem(head, deleteElem);
    if (FALSE == ret)
    {
        printf("�ڵ�δ�ҵ�\n");
    }
    else if (FAILURE == ret)
    {
        printf("�ڵ�ɾ��ʧ��\n");
    }
    else
    {
        printf("����Ϊ%d�ĵ�%d�Žڵ�ɾ���ɹ�\n", deleteElem, ret);
    }
    
    printf("�����������£�");
    ret = TraverseLink(head);
    if (SUCCESS == ret)
    {
        printf("�������ɹ�\n");
    }
    else
    {
        printf("�������ʧ��\n");
    }

/*
    //ɾ������
    ret = DeleteList(&head);
    if(SUCCESS ==  ret)
    {
        printf("����ɾ���ɹ�\n");
    }
    else
    {
        printf("����ɾ��ʧ��\n");
    }
*/

    printf("�����������£�");
    ret = TraverseLink(head);
    if (SUCCESS == ret)
    {
        printf("�������ɹ�\n");
    }
    else
    {
        printf("�������ʧ��\n");
    }

    ReverseList(head);
    printf("�������");
    TraverseLink(head);
    printf("\n");
/*
    ts(head);
    printf("�������");
    TraverseLink(head);
    printf("\n");
*/

    return 0;
}