#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81

void append(FILE *source, FILE *dest);

int main()
{
    FILE *fa, *fs;                  //faָ��׷�ӵ�Ŀ���ļ���fsָ��Դ�ļ�����׷���ļ���
    int files = 0;                  //׷���ļ�����
    char file_app[SLEN];            //��׷���ļ�����
    char file_src[SLEN];            //Դ�ļ�����
    puts("Enter name of destination file: ");
    gets(file_app);                 //����Ŀ���ļ�����

    if (NULL == (fa = fopen(file_app, "a")))        //��Ŀ���ļ�
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
    while(gets(file_src) && file_src[0] != '\0')        //����Դ�ļ�������
    {
        if (strcmp(file_src, file_app) == 0)            //���Դ�ļ���Ŀ���ļ���ͬ���򷵻�error
            fputs("Can't append file to itself\n", stderr);
        else if (NULL == (fs == fopen(file_src, "r")))  //���Դ�ļ���ʧ�ܣ�����error
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)//�򿪻�����
            {
                fputs("Can't creat input buffer\n", stderr);
                continue;
            }
            append(fs, fa);                             //��Դ�ļ���fs��д��Ŀ���ļ���fa����
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", file_app);
            fclose(fs);                                 //д������ֹر�
            files++;                                    //��¼�ļ�����
            printf("File %s append.\n", file_src);
            puts("Next file (empty line to quit): ");
        }
        
    }
    printf("Done. %d files append.\n", files);
    fclose(fa);                                         //д�����ֹر�

    return 0;
}

/**
 * ������������Դ�ļ���sourse��������д��Ŀ���ļ���dest����
*/
void append(FILE *sourse, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];      //��̬

    while((bytes = fread(temp, sizeof(char), BUFSIZE, sourse)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}