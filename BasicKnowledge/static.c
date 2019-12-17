#include <stdio.h>

void f1()
{
    static int i = 3;
    printf("i is %d\n", i);
    i++;
}

int main()
{
    f1();
    f1();

    return 0;
}