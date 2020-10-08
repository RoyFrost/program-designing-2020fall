#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"

/*预先定义一些函数方便写*/
int check(int num)
{
    return num > 0 ? 1 : 0;
}//检查输入的数的符号，正号输出1，其他输出0

int printblanks(int num)
{
    for (int i = 0; i < num; i++) printf(" ");
    return 0;
}

int printstars(int num)
{
    for (int i = 0; i < num; i++) printf("*");
    return 0;
}

int main()
{
    int n,m; //n为行数，m为空格数
    BOOL a = FALSE;

    /*用户输入行数n和中间的空格数m, 需要两个都是正数再跳出循环进行下一步*/
    while(1)
    {
        printf("please set the number of lines:");
        n = GetIntegerFromKeyboard();
        printf("please set the number of space between:");
        m = GetIntegerFromKeyboard();
        a = check(n)*check(m);//只有两个检查都成立以后a才会不为0
        if (a==FALSE) printf("plz input positive int correctly!\n");
        else break;
    }

    /*观察规律进行输出*/
    for (int i = 0; i < n; i++)
    {
        printblanks(n-1-i);
        printstars(2*i+1);
        printblanks(m);
        printstars(2*(n-1-i)+1);
        printf("\n");
    }
    return 0;
}
