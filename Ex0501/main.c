#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"

void Welcome();
int Roll();//掷骰子

int main()
{
    int i;
    Welcome();
    Randomize();
    for (i=1;i<10;i++)
    {
        printf("第%d次掷骰子的结果为%d\n",i,Roll());
    }
    return 0;
}

void Welcome()
{
    printf("这个程序是用来测试掷骰子的随机数生成器的。\n");
}

int Roll()
{
    return rand()%6+1;
}
