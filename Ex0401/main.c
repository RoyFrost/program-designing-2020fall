#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../zylib/zylib.h"

void Welcome();
int GetInteger(CSTRING prompt);
BOOL IsCompleteNum(unsigned int n);


int main()
{
    int num=0;
    BOOL flag;
    Welcome();
    num=GetInteger("请输入一个正整数：");
    flag=IsCompleteNum(num);
    flag?printf("是完数!"):printf("不是完数!");
    return 0;
}

void Welcome()
{
    printf("这个程序是用来判断一个自然数是否是完全数的。\n");
}

int GetInteger(CSTRING prompt)
{
    int num;
    while (1)
    {
        printf("%s",prompt);
        num = GetIntegerFromKeyboard();
        if (num <= 0)
            PrintErrorMessage(TRUE,"输入不合法!请重新输入");
        else
            break;
    }
    return num;
}

BOOL IsCompleteNum(unsigned int n)
{
    int i=0,sum=1;
    for (i=2; i<n;i++)
    {
        if (n%i==0)
            sum+=i;
    }
    printf("sum=%d\n",sum);
    return sum==n? TRUE:FALSE;
}
