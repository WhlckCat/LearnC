#include <stdio.h>


//getchar���ӳٻ���
int main()
{
    char ch;

    while ((ch = getchar()) != '#')
        putchar(ch);

    return 0;
}