#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

int FindPrimeFactor(int n);
void Factorize(int n);

int main()
{
    int n;
    n = GetIntegerFromKeyboard();
    Factorize(n);
    return 0;
}

int FindPrimeFactor(int n)
{
    int i = 2;
    for (i = 2;i <= n; i++)
    {
        if (n%i==0)
        {
            printf("%d ",i);
            if (n!=i)
                printf("* ");
            return n/i;
        }
    }
}

void Factorize(int n)
{
    printf("%d = ",n);
    while(n>1)
    {
        n = FindPrimeFactor(n);
    }
}
