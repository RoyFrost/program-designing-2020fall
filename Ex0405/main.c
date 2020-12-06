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
        n=GetInteger("������һ����Ȼ��n����Ҫ̫�󣡣���");
        if (n<0)
            printf("���벻�Ϸ�������������\n");
        else
            break;
    }
    printf("����֮��Ϊ%d\n",FinalSum(n));
    printf("��1-99999�����ֽ��м�飬������£�\n");
    CountDifferentFinalSums();
    return 0;
}

void Welcome()
{
    printf("�����������������Ȼ����λ����֮�͵ġ�\n");
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
}//��λ����ʮ��������Ϊ��λ�ϵ�����

unsigned int FinalSum(unsigned int n)
{
    int result=GetSumOfEachPos(n);
    while (result >=10)
    {
        result=GetSumOfEachPos(result);
    }
    return result;
}//��ÿһ�εĽ���ظ���͹��̣�ֱ��С��10

void CountDifferentFinalSums()
{
    int i,count[9]={0,0,0,0,0,0,0,0,0},j;
    for (i=1;i<100000;i++)
    {
        count[FinalSum(i)-1]+=1;
    }
    for (j=0;j<9;j++)
    {
        printf("���ս������%d���ֵĴ���Ϊ%d\n",j+1,count[j]);
    }
}