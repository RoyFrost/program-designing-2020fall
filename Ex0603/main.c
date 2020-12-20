#include <stdio.h>
#include <stdlib.h>

void Welcome();
void Generate30NoRepeatRandomNumber(int a[]);

int main()
{
    int a[30];
    Randomize();
    Generate30NoRepeatRandomNumber(a);
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
    printf("这个程序会生成30个不重复的10-99的随机数,存储在一个数组中并输出。\n");
}

void Generate30NoRepeatRandomNumber(int a[])
{
    a[0]=GenerateRandomNumber(10,99);
    for (int i=1; i<30; i++)
    {
        int temp;
        temp = GenerateRandomNumber(10,99);
        for (int j=0; j<i; j++)
        {
            if(temp==a[j])
            {
                temp = GenerateRandomNumber(10,99);
                j=0;
            }
        }
        a[i]=temp;
    }
}
