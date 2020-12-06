#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"


void Welcome();
int Roll();//掷骰子
BOOL Round();//一个回合
void ResultAnnouncement(BOOL _result);//输出游戏结果提示

int main()
{
    Randomize();
    ResultAnnouncement(Round());
    return 0;
}

void Welcome()
{
    printf("这个程序中，用户和计算机进行掷骰子游戏。\n");
}

int Roll()
{
    return rand()%6+1;
}

BOOL Round()
{
    int NumOfCom, NumOfUser;//计算机的数和用户的数
    char temp;
    NumOfCom = Roll();
    while (1)
    {
        printf("请输入g来掷一次骰子。\n");
        temp = getchar();
        fflush(stdin);
        if (temp=='g')
        {
            NumOfUser=Roll();
            break;
        }
        else
        {
            printf("输入不合法！请输入g\n");
            continue;
        }
    }
    printf("C=%d,U=%d\n",NumOfCom,NumOfUser);
    return NumOfUser<NumOfCom ? FALSE : TRUE;
}

void ResultAnnouncement(BOOL result)
{
    if (result)
        printf("用户胜利！\n");
    else
        printf("用户输了！\n");
}
