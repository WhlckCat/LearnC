#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
�������ƣ��򵥲�������
�������ܣ���С��������
��������������ָ�룬����
��������ֵ����
*/
void InsertSort(int *a, int length)
{
    int i, j, tmp;
    for (i = 0; i < length; i++)
    {
        tmp = a[i];
        for (j = i - 1; j > 0; j--)
        {
            if (tmp < a[j])
            {
                a[j] = a[j + 1];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = tmp;
    }
}

/*
�������ƣ�ϣ������
�������ܣ���С��������
��������������ָ�룬����
��������ֵ����
*/
void HillInsertSort(int *a, int length)
{
    int i, j, tmp, h;
    for(h = length / 2; h > 0; h /= 2)
    {
        for (i = 0; i < length; i++)
        {
            tmp = a[i];
            for (j = i - h; j >= 0; j -= h)
            {
                if (tmp < a[j])
                {
                    a[j + h] = a[j + 1];
                }
                else
                {
                    break;
                }
            }
            a[j + h] = tmp;
        }
    }
}

/*
�������ƣ�ѡ������
�������ܣ���С��������
��������������ָ�룬����
��������ֵ����
*/
void SelectSort(int *a, int length)
{
    int i, j, index, min;
    for (i = 0; i < length - 1; i++)
    {
        index = i;
        min = a[i];
        for (j = i + 1; j < length; j++)
        {
            if (a[j] < min)
            {
                index = j;
                min = a[j];
            }
        }
        if (i != index)
        {
            a[i] = a[i] + a[index];
            a[index] = a[i] - a[index];
            a[i] = a[i] - a[index];
        }
    }
}

/*
�������ƣ���������
�������ܣ���С��������
��������������ָ�룬����
��������ֵ����
*/
void Quicksort(int *a, int start, int end)
{
    int x = start;
    int y = end;
    int base = a[x];

    if(x >= y)
    {
        return;
    }

    while(x < y)
    {
        if (a[y] > base && x < y)
        {
            y--;
        }
        if (a[y] <= base && x < y)
        {
            a[x++] = a[y];
            //x++;
        }
        if (a[x] < base && x < y)
        {
            x++;
        }
        if (a[x] >= base && x < y)
        {
            a[y--] = a[x];
            //y--;
        }
    }
    a[x] = base;

    Quicksort(a, start, x - 1);
    Quicksort(a, y + 1, end);

    return;
}

/*
�������ܣ������󶥶�
�����������Ѷ��±� ��β�±� �����ַ
��������ֵ����
*/
void AdjustMaxHeap(int *a, int head, int tail)
{
    int child = 2 * head + 1;
    while(child < tail)
    {
        if (child + 1 <= tail && a[child] <= a[child + 1])
        {
            child++;
        }
        if(a[child] > a[head])
        {
            a[child] = a[head] + a[child];
            a[head] = a[child] - a[head];
            a[child] = a[child] - a[head];
        }
        else
        {
            return;
        }
        head = child;
        child = 2 * head + 1;
    }
}

/*
�������ܣ������Ѷ��Ͷѵ�
��������������ָ�� �Ѷ� �ѵ� ���鳤�ȵ�ַ
��������ֵ����
*/
void swap(int *a, int head,int *length)
{
    a[head] = a[head] + a[*length];
    a[*length] = a[head] - a[*length];
    a[head] = a[head] - a[*length];

    (*length)--;
}

/*
�������ƣ�������
�������ܣ���С��������
��������������ָ�룬����
��������ֵ����
*/
void HeapSort(int *a, int length)
{
    //�����󶥶�
    int i,len = length - 1;
    for (i = length / 2; i >= 0; i--)
    {
        AdjustMaxHeap(a, i, length - 1);
    }

    //�����󶥶�
    for (i = 0; i < length - 1; i++)
    {
        swap(a, 0, &len);
        AdjustMaxHeap(a, 0, len - 1);
    }
}

void Merge(int *a, int start, int mid, int end)
{
    int Leften = mid - start + 1;
    int Righten = end - mid;
    int *L = (int *)malloc(sizeof(int) * Leften);
    int *R = (int *)malloc(sizeof(int) * Righten);

    int i, k, j;
    for (i = 0, k = start; i < Leften; i++, k++)
    {
        L[i] = a[k];
    }
    for (j = 0; j < Righten; j++, k++)
    {
        R[i] = a[k];
    }

    for (i = 0, j = 0, k = start; i < Leften && j < Righten; k++)
    {
        if (L[i] < R[i])
        {
            a[k] = L[i++];
        }
        else
        {
            a[k] = R[i++];
        }
    }

    if (j < Righten)
    {
        for (; j < Righten; j++, k++)
        {
            a[k] = R[j];
        }
    }
    if (i < Leften)
    {
        for (; i < Leften; i++,k++)
        {
            a[k] = L[i];
        }
    }
}

/*
�������ƣ��鲢����
�������ܣ���С��������
��������������ָ��
��������ֵ����
*/
void MergeSort(int *a, int start, int end)
{
    int mid = (start + end) / 2;
    MergeSort(a, start, mid);
    MergeSort(a, mid + 1, end);

    Merge(a, start, mid, end);
}

int main()
{
    int i,j;
    int array[100];
    srand(time(NULL));
    for (i = 0; i < 100;i++)
    {
        array[i] = rand() % 100;
    }

    //Quicksort(array, 0, sizeof(array) / sizeof(array[0]));
    //InsertSort(array, 100);
    //HillInsertSort(array, 100);
    //SelectSort(array, 100);
    //HeapSort(array, 100);
    MergeSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

    for (i = 0; i < 100; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n"); 
    
    return 0;
}