#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../zylib/zylib.h"

int IsPrime(int num)
{
    unsigned int i = 2;
    if (num < 2) return 0;
    else if ( num == 2 ) return 1;
    else
    {
        while (i <= (int)sqrt(num)+1)
        {
            if (num % i==0) return 0;
            i+=2;
        }
    }
    return 1;
}


int main()
{
    int temp;
    temp = GetIntegerFromKeyboard();
    if (IsPrime(temp)) printf("true!");
    else printf("false!");
    return 0;
}
