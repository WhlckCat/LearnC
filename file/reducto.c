#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

/**
 * fprint 的作用是将一些东西输入到文件里
 * fscanf 的作用可能是将文件里的东西读取出来
*/
int main(int argc, char *argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    if (NULL == (in = fopen(argv[1], "r")))
    {
        fprintf(stderr, "I could not open the file \"%s\"\n", argv[1]);
        exit(2);
    }
    strcpy(name, argv[1]);
    strcat(name, ".red");
    if (NULL == (out = fopen(name, "w")))
    {
        fprintf(stderr, "Can't creat output file.\n");
        exit(3);
    }

    while((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}