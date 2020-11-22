#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

void Welcome();
BOOL CheckLeapYear(unsigned int year);//检查是否是闰年
int NumofMonthDay(int month, BOOL leapflag);//返回对应月份的天数，需要判断是否闰年
int WeekdayoftheFirstDay(int month, int year);//计算该年该月1日是周几
int GetInteger(CSTRING prompt);//给出提示信息获取整数
void RetractSpace(int num);//缩进，方便日历格式
void PrintLine(int width);//打印一定长度的分割线
void PrintCalendar(int month, int year);//输出对应年月的日历

int main()
{
    int month,year;
    Welcome();
    while(1)
    {
         month = GetInteger("请输入月份:");
         if (month>0&&month<=12)
            break;
         else
            printf("输入不合法，请重新输入\n");
    }
     while(1)
    {
         year = GetInteger("请输入年份:");
         if (year >= 2015)
            break;
         else
            printf("输入不合法，请重新输入\n");
    }
    PrintCalendar(month,year);
    return 0;
}

void Welcome()
{
    printf("输入2015年后（含）的某年某月来打印一份日历:\n");
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
        printf("%4d\n", i);//换行
    else if (i%7== (8 - weekday)%7)
        printf("%2d", i);//每一行第一个日期的缩进
    else
    printf("%4d", i);//一般日期的缩进
    }
    printf("\n");
    PrintLine(width);
}
