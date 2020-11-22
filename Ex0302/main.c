#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
unsigned int gcd(unsigned int _num1, unsigned int _num2);//寻找两个正整数的最小公约数，并返回
int GetInteger(CSTRING prompt);

int main()
{
    int a, b;
    Welcome();
    a = GetInteger("请输入第一个数:");
    b = GetInteger("请输入第二个数:");
    printf("最大公约数为%d",gcd(a,b));
    return 0;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    int temp;
    while (b > 0)
        {
        temp = a % b;
        a = b;
        b = temp;
        }
    return a;
}//利用辗转相除法

void Welcome()
{
    printf("请输入两个正整数来求它们的最大公约数：\n");
}

int GetInteger(CSTRING prompt)
{
    int a;
    printf("%s",prompt);
    a = GetIntegerFromKeyboard();
    return a;
}
