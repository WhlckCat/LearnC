#include <stdio.h>


//getcharÊÇÑÓ³Ù»ØÏÔ
int main()
{
    char ch;

    while ((ch = getchar()) != '#')
        putchar(ch);

    return 0;
}