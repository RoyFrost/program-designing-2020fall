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
        n = GetInteger("������n:");
        k = GetInteger("������k:");
        if (n<k)
            printf("���벻�Ϸ�������������\n");
        else
            break;
    }
    printf("result=%d",C(n,k));
    return 0;
}

void Welcome()
{
    printf("����������õݹ鷽���������ʽϵ���ģ���ʽΪC(n,k)��\n");
}

int GetInteger(CSTRING prompt)
{
    int num;
    while(1)
    {
        printf("%s",prompt);
        num=GetIntegerFromKeyboard();
        if (num < 0)
            printf("���벻�Ϸ������������룡");
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
        return C(n-1,k)+C(n-1,k-1);//�ݹ��㷨
}