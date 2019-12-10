#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lNode;
    struct Node *rNode;
};
typedef struct Node node;
typedef node *pnode;

pnode CreatTree(int *array,int length)
{
    pnode a[11] = {0};
    int i;
    for(i = 0; i < length; i++)
    {
        a[i] = (pnode)malloc(sizeof(node) * 1);
        if (NULL == a[i])
        {
            printf("malloc failure!\n");
        }
        a[i]->data = array[i];
        a[i]->lNode = a[i]->rNode = NULL;
    }


    for(i = 0; i < length / 2; i++)
    {
        a[i]->lNode = a[2 * i + 1];
        a[i]->rNode = a[2 * i + 2];
    }

    return a[0];
}

void compare(pnode n, pnode m)
{
    if (n->data <= m->data)
    {
        if (NULL == m->lNode)
        {
            m->lNode = n;
            return;
        }
        compare(n, m->lNode);
    }

    if (n->data > m->data)
    {
        if (NULL == m->rNode)
        {
            m->rNode = n;
            return;
        }
        compare(n, m->rNode);
    }
}


pnode TraverseTree(int *array,int length)
{
    pnode a[11] = {0};
    int i;
    for(i = 0; i < length; i++)
    {
        a[i] = (pnode)malloc(sizeof(node) * 1);
        if (NULL == a[i])
        {
            printf("malloc failure!\n");
        }
        a[i]->data = array[i];
        a[i]->lNode = a[i]->rNode = NULL;
        if (0 != i)
        {
            compare(a[i], a[0]);
        }
    }

    return a[0];
}

int Preoder(pnode root)
{
    if (NULL == root)
    {
        return 0;
    }

    printf("%d ", root->data);
    Preoder(root->lNode);
    Preoder(root->rNode);
    
    return 0;
}

int Midorder(pnode root)
{
    if (NULL == root)
    {
        return 0;
    }

    Midorder(root->lNode);
    printf("%d ", root->data);
    Midorder(root->rNode);
    
    return 0;
}

int Lateorder(pnode root)
{
    if (NULL == root)
    {
        return 0;
    }

    Lateorder(root->lNode);
    Lateorder(root->rNode);
    printf("%d ", root->data);
    
    return 0;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7 ,8 ,9, 10};

    pnode root = CreatTree(array, sizeof(array) / sizeof(array[0]));

    Preoder(root);
    printf("\n");

    Midorder(root);
    printf("\n");

    Lateorder(root);
    printf("\n");

    int array2[] = {2, 4, 6, 1, 2, 3, 9, 5, 8, 2};
    root = TraverseTree(array2, sizeof(array2) / sizeof(array2[0]));

    Midorder(root);
    printf("\n");

    return 0;
}