#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"

void Welcome();
void Generate30randomnumber(int a[]);

int main()
{
    int a[30];
    Randomize();
    Generate30randomnumber(a);
    for (int i=0;i<30;i++)
    {
        printf("%d ",a[i]);
        if (i%10==9)
            printf("\n");
    }
    return 0;
}

void Welcome()
{
    printf("������������30��10-99�������,�洢��һ�������в������\n");
}

void Generate30randomnumber(int a[])
{
    for (int i=0; i<30; i++)
    {
        a[i]=GenerateRandomNumber(10,99);
    }
}