#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../zylib/zylib.h"


int IsPrime(int _num);//检查一个数是否为素数，返回1为是，0为否

int main()
{
    int temp;
    printf("Please input a integer to check whether it's a prime number or not:");
    temp = GetIntegerFromKeyboard();
    if (IsPrime(temp))
        printf("true!");
    else
        printf("false!");
    return 0;
}

int IsPrime(int num)
{
    unsigned int i = 2;
    if (num < 2)
        return 0;
    else if (num == 2)
        return 1;
    else
    {
        while (i <= (int)sqrt(num)+1)
        {
            if (num % i==0)
                return 0;
            i+=1;
        }
    }
    return 1;
}
/*虽然只要判断大于2， 但把小于2的异常也给排除了*/
