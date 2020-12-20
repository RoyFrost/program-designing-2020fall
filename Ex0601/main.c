#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
STRING GetString(CSTRING prompt);
unsigned int FindVowelChar(CSTRING s); //�ҵ��ַ����еĵ�һ��Ԫ����ĸ�����������򷵻�inexistent_index


int main()
{
    STRING s;
    unsigned int pos=0;
    Welcome();
    s = GetString("�������ַ�����");
    pos=FindVowelChar(s);
    printf("Ԫ����ĸ�״γ���λ��Ϊ��%d",pos+1);
    return 0;
}

void Welcome()
{
    printf("�˳���������Ѱ���ַ�����Ԫ����ĸ���״γ���λ�õġ���λλ��Ϊ1,������ʱ����0��\n");
}

STRING GetString(CSTRING prompt)
{
    STRING s;
    printf("%s",prompt);
    s = GetStringFromKeyboard();
    return s;
}

unsigned int FindVowelChar(CSTRING s)
{
    unsigned int temp=0,pos=inexistent_index;
    char vowel[10]={'a','A','e','E','i','I','o','O','u','U'};
    int i;
    for (i=0;i<10;i++)
    {
        temp=FindCharFirst(vowel[i],s);
        pos = temp < pos ? temp : pos;
    }
    return pos;
}