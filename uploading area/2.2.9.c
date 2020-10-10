#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"

int printline(int length);

int main()
{
  int width = 26;
  printf("Calendar 2015-05          \n");
  printline(width);
  printf("Su  Mo  Tu  We  Th  Fr  Sa\n");
  printline(width);
  for (int i = 1; i <= 31; i++)
  {
    if (i==1) printf("%22d", i);//第一个光标位置需要手动确认
    else if (i%7==2) printf("%4d\n", i);//换行
    else if (i%7==3) printf("%2d", i);//每一行第一个日期的缩进
    else printf("%4d", i);//一般日期的缩进
  }
  printf("\n");
  printline(width);
  return 0;
}

int printline(int length)
{
  for(int i = 0; i < length; i++) printf("-");
  printf("\n");
  return 0;
}//打印分割线
