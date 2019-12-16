#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/**
 * 变长数组
*/
int main()
{
    int n, i;

    scanf("%d", &n);
    int a[n];

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}