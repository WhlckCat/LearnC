#include <stdio.h>
#include <stdlib.h>
#define MAX 40

/**
 * 给文件（可读可写 'a'）尾部添加内容（如果没有就创建一个）
*/
int main(void)
{
    FILE *fp;
    char words[MAX];

    if (NULL == (fp = fopen("words", "a+")))
    {
        fprintf(stderr, "Can't open \"word\" file\n");
        exit(1);
    }

    puts("Enter words to add to the file: press the Enter");
    puts("key at the beginning of a line to terminate.");
    while (gets(words) != NULL && words[0] != '\0')
        fprintf(fp, "%s", words);
    puts("File contents:");
    rewind(fp);
    while (1 == fscanf(fp, "%s", words))
        puts(words);

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}