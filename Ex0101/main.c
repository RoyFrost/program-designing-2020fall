#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"

int main()
{
    double principal, interest, RoI, deposit;//������Ϣ�����ʡ��ܴ��

    /*��ó�ʼ����*/
    printf("Input the initial principal of the deposit\(Unit: %%\):");
    principal = GetRealFromKeyboard();
    printf("Input the rate of interest\(Unit: %%\):");
    RoI = GetRealFromKeyboard()/100;

    /*���㲢�������ս��*/
    interest = principal * RoI ;
    deposit = principal + interest;
    printf("The final deposit is %.2lf ", deposit);
    return 0;
}