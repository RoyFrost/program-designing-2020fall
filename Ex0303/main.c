#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
BOOL CheckLeapYear(unsigned int year);//����Ƿ�������
int NumofMonthDay(int month, BOOL leapflag);//���ض�Ӧ�·ݵ���������Ҫ�ж��Ƿ�����
int WeekdayoftheFirstDay(int month, int year);//����������1�����ܼ�
int GetInteger(CSTRING prompt);//������ʾ��Ϣ��ȡ����
void RetractSpace(int num);//����������������ʽ
void PrintLine(int width);//��ӡһ�����ȵķָ���
void PrintCalendar(int month, int year);//�����Ӧ���µ�����

int main()
{
    int month,year;
    Welcome();
    while(1)
    {
         month = GetInteger("�������·�:");
         if (month>0&&month<=12)
            break;
         else
            printf("���벻�Ϸ�������������\n");
    }
     while(1)
    {
         year = GetInteger("���������:");
         if (year >= 2015)
            break;
         else
            printf("���벻�Ϸ�������������\n");
    }
    PrintCalendar(month,year);
    return 0;
}

void Welcome()
{
    printf("����2015��󣨺�����ĳ��ĳ������ӡһ������:\n");
}

BOOL CheckLeapYear(unsigned int year)
{
    if (year%4 == 0&& year%100 != 0 || year%400 == 0)
        return TRUE;
    else
        return FALSE;
}

int NumofMonthDay(int month, BOOL leapflag)
{
    if (month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
        return 31;
    else if (month == 4||month == 6||month == 9||month == 11)
        return 30;
    else
        return leapflag ? 29 : 28;
}
int WeekdayoftheFirstDay(int target_month, int target_year)
{
    int total_day = 0,month, year,t;
    BOOL leapflag = CheckLeapYear(target_year);
    if (target_year > 2015)
        for (year = 2015; year < target_year; year++)
        {
            total_day += CheckLeapYear(year) ? 366 : 365;
        }
    if (target_month > 1)
        for (month=1 ; month < target_month ; month++)
        {
            total_day+=NumofMonthDay(month,leapflag);
        }
    t= (total_day%7+4)%7;
    return t;
}

int GetInteger(CSTRING prompt)
{
    int t;
    printf("%s",prompt);
    t = GetIntegerFromKeyboard();
    return t;
}

void RetractSpace(int num)
{
    for (int i=0;i<num;i++)
    {
        printf(" ");
    }
}

void PrintLine(int width)
{
    for (int i=0;i<width;i++)
    {
        printf("-");
    }
    printf("\n");
}

void PrintCalendar(int target_month, int target_year)
{
    int weekday = WeekdayoftheFirstDay(target_month,target_year);
    int monthday = NumofMonthDay(target_month,CheckLeapYear(target_year));
    int width = 26;
    printf("Calendar %d-%d          \n",target_year,target_month);
    PrintLine(width);
    printf("Su  Mo  Tu  We  Th  Fr  Sa\n");
    PrintLine(width);
    for (int i = 1; i <= monthday; i++)
    {
    if (i==1)
    {
        RetractSpace(4*weekday-4);
        printf("%2d",i);
    }
    else if (i%7== (7 - weekday)%7)
        printf("%4d\n", i);//����
    else if (i%7== (8 - weekday)%7)
        printf("%2d", i);//ÿһ�е�һ�����ڵ�����
    else
    printf("%4d", i);//һ�����ڵ�����
    }
    printf("\n");
    PrintLine(width);
}