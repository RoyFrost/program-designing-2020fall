#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"

/*Ԥ�ȶ���һЩ��������д*/
int check(int num);

int printblanks(int num);

int printstars(int num);

int main()
{
    int n,m; //nΪ������mΪ�ո���
    BOOL a = FALSE;

    /*�û���������n���м�Ŀո���m, ��Ҫ������������������ѭ��������һ��*/
    while(1)
    {
        printf("please set the number of lines:");
        n = GetIntegerFromKeyboard();
        printf("please set the number of space between:");
        m = GetIntegerFromKeyboard();
        a = check(n)*check(m);//ֻ��������鶼�����Ժ�a�Ż᲻Ϊ0
        if (a==FALSE) printf("plz input positive int correctly!\n");
        else break;
    }

    /*�۲���ɽ������*/
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

int check(int num)
{
    return num > 0 ? 1 : 0;
}//�����������ķ��ţ��������1���������0

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
