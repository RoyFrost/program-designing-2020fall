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
        n=GetInteger("������һ����Ȼ��n����Ҫ̫�󣡣���");
        if (n<0)
            printf("���벻�Ϸ�������������\n");
        else
            break;
    }
    printf("��λ����֮��Ϊ%d\n",GetSumOfEachPos(n));
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
        #ifndef DEBUGED
        printf("n=%d\n",n);
        #endif // DEBUGED
        sum+=(n%10);
        n/=10;
    }
    return sum;
}//��λ����ʮ��������Ϊ��λ�ϵ�����