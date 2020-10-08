#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"


int printline(int length)
{
    for (int i = 0; i < length; i++) printf("-");
    printf("\n");
    return 0;
}//打印分割线

int main()
{
    int width = 38;
    printf("   Nine-by-nine Multiplication Table  \n");
    printline(width);
    printf("     1   2   3   4   5   6   7   8   9\n");
    printline(width);

    /*主要的循环打印部分，注意缩进即可*/
    for (int i = 0; i < 9; i++)
    {
        printf("%2d",i+1);
        for (int j = 0; j < i + 1; j++)
        {
            printf("%4d",(j+1)*(i+1));
        }
        printf("\n");
    }
    printline(width);
    return 0;
}
