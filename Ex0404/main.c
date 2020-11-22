#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#define DEBUGED

void Welcome();
int GetInteger(CSTRING prompt);
unsigned int GetSumOfEachPos(unsigned int n);

int main()
{
    int n;
    Welcome();
    while(1)
    {
        n=GetInteger("请输入一个自然数n（不要太大！）：");
        if (n<0)
            printf("输入不合法，请重新输入\n");
        else
            break;
    }
    printf("各位数字之和为%d\n",GetSumOfEachPos(n));
    return 0;
}

void Welcome()
{
    printf("这个程序是用来求自然数各位数字之和的。\n");
}

int GetInteger(CSTRING prompt)
{
    int num;
    printf("%s",prompt);
    num = GetIntegerFromKeyboard();
    return num;
}

unsigned int GetSumOfEachPos(unsigned int n)
{
    unsigned int sum=0;
    while (n>0)
    {
        #ifndef DEBUGED
        printf("n=%d\n",n);
        #endif // DEBUGED
        sum+=(n%10);
        n/=10;
    }
    return sum;
}//逐位除以十，余数即为各位上的数字
