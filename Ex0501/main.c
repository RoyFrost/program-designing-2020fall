#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"

void Welcome();
int Roll();//������

int main()
{
    int i;
    Welcome();
    Randomize();
    for (i=1;i<10;i++)
    {
        printf("��%d�������ӵĽ��Ϊ%d\n",i,Roll());
    }
    return 0;
}

void Welcome()
{
    printf("����������������������ӵ�������������ġ�\n");
}

int Roll()
{
    return rand()%6+1;
}