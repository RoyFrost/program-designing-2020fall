#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#define DEBUGED

void Welcome();
int GetInteger(CSTRING prompt);
unsigned int factorial(unsigned int n);//计算阶乘
unsigned int C(unsigned int n, unsigned int k);//计算二项式系数


int main()
{
    int n,k;
    Welcome();
    while(1)
    {
        n=GetInteger("请输入n：");
        k=GetInteger("请输入k：");
        if (n>=k&&k>=0)
            break;
        else
        {
            printf("输入不合理，请重新输入！\n");
        }
    }
    printf("result=%d\n",C(n,k));
    return 0;
}

void Welcome()
{
    printf("这个程序是用来计算二项式系数的。形式为C(n,k),即n次二项式展开时k阶项的系数。\n");
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

unsigned int factorial(unsigned int n)
{
    int i,result=1;
    if (n==0||n==1)
        return 1;
    for (i=2; i<=n;i++)
    {
        result*=i;
    }
    #ifndef DEBUGED
    printf("fac=%d\n",result);
    #endif // DEBUGED
    return result;
}//事实上这个函数能算的n很小

unsigned int C(unsigned int n, unsigned int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}
