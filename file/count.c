#include <stdio.h>
#include <stdlib.h>

/**
 * putc getc ��putchar getchar��ԭ�ͺ���
 * ����һ���ַ�һ���ַ��Ķ�ȡ������
*/
int main(int argc, char *argv[])
{
    int ch;
    FILE *fp;
    long count = 0;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    if (NULL == (fp = fopen(argv[1], "r")))
    {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }

    while((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }

    printf("\n");
    printf("%d  %s  %s\n", argc, argv[0], argv[1]);

    fclose(fp);
    printf("File %s has %ld characters\n", argv[1], count);

    return 0;
}