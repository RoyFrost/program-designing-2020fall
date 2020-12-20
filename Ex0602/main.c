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
    printf("这个程序会生成30个10-99的随机数,存储在一个数组中并输出。\n");
}

void Generate30randomnumber(int a[])
{
    for (int i=0; i<30; i++)
    {
        a[i]=GenerateRandomNumber(10,99);
    }
}
