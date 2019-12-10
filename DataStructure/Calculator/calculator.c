#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

stack number, simbol;

int InitCalculator()
{
    int ret = initStack(&number);
    if (SUCCESS == ret)
    {
        printf("初始化数字栈成功！\n");
    }
    else
    {
        printf("初始化失败！\n");
        return FAILURE;
    }

    ret = initStack(&simbol);
    if (SUCCESS == ret)
    {
        printf("初始化符号栈成功！\n");
    }
    else
    {
        printf("初始化失败！\n");
        return FAILURE;
    }

    return SUCCESS;
}

int prior(char e)
{
    switch(e)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
}

int main()
{
    char opt[128] = {0}; 
    int ret = InitCalculator();
    if (ret = FAILURE)
    {
        printf("初始化失败！\n");
    }
    else
    {
        printf("初始化成功！\n");
    }

    scanf("请输入算式：%s", opt);
    int i = 0, tmp = 0;
    while(opt[i] != '\0' || emptyStack(simbol))
    {
        if(opt[i] >= '0' && opt[i] <= '9')      //数字
        {
            tmp = opt[i] - '0';
            i++;
            if(opt[i] < '0' && opt[i] > '9')
            {
                pushStack(&number, tmp);
            }
        }
        else    //运算符
        {
            if (SUCCESS == emptyStack(simbol) || prior(opt[i]) > prior(gettop(simbol)) || '(' == gettop(simbol))
            {
                pushStack(&simbol, opt[i]);
                i++;
            }
            else if ('(' == gettop(simbol) && ')' == opt[i])
            {
                popStack(&simbol);
                popStack(&simbol);
            }
            else
            {
                
            }
            
        }
        
    }
    return 0;
}