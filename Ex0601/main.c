#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
STRING GetString(CSTRING prompt);
unsigned int FindVowelChar(CSTRING s); //找到字符串中的第一个元音字母，若不存在则返回inexistent_index


int main()
{
    STRING s;
    unsigned int pos=0;
    Welcome();
    s = GetString("请输入字符串：");
    pos=FindVowelChar(s);
    printf("元音字母首次出现位置为：%d",pos+1);
    return 0;
}

void Welcome()
{
    printf("此程序是用来寻找字符串中元音字母的首次出现位置的。首位位置为1,不存在时返回0。\n");
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
