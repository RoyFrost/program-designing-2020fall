#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
int GetInteger(CSTRING prompt);
unsigned int C(unsigned int n, unsigned int k);

int main()
{
    int n,k;
    Welcome();
    while(1)
    {
        n = GetInteger("请输入n:");
        k = GetInteger("请输入k:");
        if (n<k)
            printf("输入不合法！请重新输入\n");
        else
            break;
    }
    printf("result=%d",C(n,k));
    return 0;
}

void Welcome()
{
    printf("这个程序是用递归方法计算二项式系数的，形式为C(n,k)。\n");
}

int GetInteger(CSTRING prompt)
{
    int num;
    while(1)
    {
        printf("%s",prompt);
        num=GetIntegerFromKeyboard();
        if (num < 0)
            printf("输入不合法，请重新输入！");
        else
            break;
    }
    return num;
}

unsigned int C(unsigned int n, unsigned int k)
{
    if (k==0||n==k)
        return 1;
    else
        return C(n-1,k)+C(n-1,k-1);//递归算法
}
