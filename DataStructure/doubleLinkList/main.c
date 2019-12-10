#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkList.h"

int main()
{
    //��ʼ��
    pdul head, tail, elem;
    elem = (pdul)malloc(sizeof(dul) * 1);
    int ret;
    Init_dulLinkList(&head, &tail);

    //��ӡ����
    printLinkList(head);
    //����Ԫ��
    int i;
    for (i = 0; i < 20; i++)
    {
        InsertElem(head, i);
    }
    //��ӡ����
    printLinkList(head);

    //����Ԫ��
    i = 15;
    ret = getElem(head, &elem, i);
    if (SUCCESS == ret)
    {
        printf("��ȡԪ�سɹ�\n");
        printf("Ԫ��Ϊ��%d\n", elem->data);
    }
    else
    {
        printf("��ȡԪ��ʧ��\n");
    }

    //ɾ��Ԫ��
    i = 10;
    DeleteElem(head, i);
    //��ӡ����
    printLinkList(head);

    //ɾ������
    ret = DeleteList(head, tail);
    if (SUCCESS == ret)
    {
        printf("ɾ���ɹ�");
    }
    //��ӡ����
    printLinkList(head);
    
    return 0;
}