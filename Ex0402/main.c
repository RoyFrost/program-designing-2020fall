#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#define DEBUGED

void Welcome();
int GetInteger(CSTRING prompt);
unsigned int factorial(unsigned int n);//����׳�
unsigned int C(unsigned int n, unsigned int k);//�������ʽϵ��


int main()
{
    int n,k;
    Welcome();
    while(1)
    {
        n=GetInteger("������n��");
        k=GetInteger("������k��");
        if (n>=k&&k>=0)
            break;
        else
        {
            printf("���벻���������������룡\n");
        }
    }
    printf("result=%d\n",C(n,k));
    return 0;
}

void Welcome()
{
    printf("��������������������ʽϵ���ġ���ʽΪC(n,k),��n�ζ���ʽչ��ʱk�����ϵ����\n");
}

int GetInteger(CSTRING prompt)
{
    int num;
    while (1)
    {
        printf("%s",prompt);
        num = GetIntegerFromKeyboard();
        if (num <= 0)
            PrintErrorMessage(TRUE,"���벻�Ϸ�!����������");
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
}//��ʵ��������������n��С

unsigned int C(unsigned int n, unsigned int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}