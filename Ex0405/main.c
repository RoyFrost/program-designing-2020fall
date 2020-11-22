#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
int GetInteger(CSTRING prompt);
unsigned int GetSumOfEachPos(unsigned int n);
unsigned int FinalSum(unsigned int n);
void CountDifferentFinalSums();

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
    printf("最终之和为%d\n",FinalSum(n));
    printf("对1-99999的数字进行检查，结果如下：\n");
    CountDifferentFinalSums();
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
        sum+=(n%10);
        n/=10;
    }
    return sum;
}//逐位除以十，余数即为各位上的数字

unsigned int FinalSum(unsigned int n)
{
    int result=GetSumOfEachPos(n);
    while (result >=10)
    {
        result=GetSumOfEachPos(result);
    }
    return result;
}//对每一次的结果重复求和过程，直到小于10

void CountDifferentFinalSums()
{
    int i,count[9]={0,0,0,0,0,0,0,0,0},j;
    for (i=1;i<100000;i++)
    {
        count[FinalSum(i)-1]+=1;
    }
    for (j=0;j<9;j++)
    {
        printf("最终结果数字%d出现的次数为%d\n",j+1,count[j]);
    }
}
