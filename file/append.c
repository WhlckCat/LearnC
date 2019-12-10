#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81

void append(FILE *source, FILE *dest);

int main()
{
    FILE *fa, *fs;                  //fa指向追加的目的文件，fs指向源文件（即追加文件）
    int files = 0;                  //追加文件个数
    char file_app[SLEN];            //被追加文件名称
    char file_src[SLEN];            //源文件名称
    puts("Enter name of destination file: ");
    gets(file_app);                 //输入目的文件名称

    if (NULL == (fa = fopen(file_app, "a")))        //打开目的文件
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(2);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't creat output buffer\n", stderr);
        exit(3);
    }

    puts("Enter name of first source file (empty line to quit): ");
    while(gets(file_src) && file_src[0] != '\0')        //输入源文件的名称
    {
        if (strcmp(file_src, file_app) == 0)            //如果源文件和目的文件相同，则返回error
            fputs("Can't append file to itself\n", stderr);
        else if (NULL == (fs == fopen(file_src, "r")))  //如果源文件打开失败，返回error
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)//打开缓冲区
            {
                fputs("Can't creat input buffer\n", stderr);
                continue;
            }
            append(fs, fa);                             //将源文件（fs）写到目的文件（fa）中
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", file_app);
            fclose(fs);                                 //写完就随手关闭
            files++;                                    //记录文件个数
            printf("File %s append.\n", file_src);
            puts("Next file (empty line to quit): ");
        }
        
    }
    printf("Done. %d files append.\n", files);
    fclose(fa);                                         //写完随手关闭

    return 0;
}

/**
 * 函数描述：将源文件（sourse）的内容写到目的文件（dest）中
*/
void append(FILE *sourse, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];      //静态

    while((bytes = fread(temp, sizeof(char), BUFSIZE, sourse)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}