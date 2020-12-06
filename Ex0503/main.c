#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"

void Welcome();
int Roll();//掷骰子
int UserRoll();//用户掷骰子，返回-1表示放弃掷骰子，即退出游戏
BOOL Round();//一个回合
void ResultAnnouncement(BOOL _result);//输出游戏结果提示
void Game();//游戏开始

int main()
{
    Welcome();
    Game();
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

int UserRoll()
{
    char temp;
    while (1)
        {
            printf("请输入g来掷一次骰子。输入q或Q来结束游戏\n");
            temp = getchar();
            fflush(stdin);
            if (temp =='q'||temp=='Q')
                return -1;
            else if (temp=='g')
                return Roll();
            else
                printf("输入不合法！请重新输入\n");
        }
}//返回-1表示需要退出游戏

void ResultAnnouncement(BOOL result)
{
    if (result)
        printf("用户胜利！\n");
    else
        printf("用户输了！\n");
}

void Game()
{
    int NumOfCom, NumOfUser;//计算机的数和用户的数
    int TotalRoundCount,WinRoundCount;//总回合计数和胜利回合计数
    double WinRate;
    BOOL UserIsBanker;
    TotalRoundCount=WinRoundCount=0;
    UserIsBanker = TRUE;
    Randomize();
    while(1)
    {
        if(UserIsBanker)
        {
            NumOfUser=UserRoll();
            if (NumOfUser==-1) break;
            printf("用户掷出%d\n",NumOfUser);
            NumOfCom=Roll();
            printf("计算机掷出%d\n",NumOfCom);
        }
        else
        {
            NumOfCom=Roll();
            printf("计算机掷出%d\n",NumOfCom);
            NumOfUser=UserRoll();
            if (NumOfUser==-1) break;
            printf("用户掷出%d\n",NumOfUser);
        }


        /*每一轮的输赢判断，及记录*/
        TotalRoundCount++;
        if (UserIsBanker)
        {
            if (NumOfCom > NumOfUser)
                ResultAnnouncement(FALSE);
            else
            {
                ResultAnnouncement(TRUE);
                UserIsBanker = FALSE;
                WinRoundCount++;
            }
        }
        else
        {
            if (NumOfUser > NumOfCom)
            {
                ResultAnnouncement(TRUE);
                WinRoundCount++;
            }
            else
            {
                ResultAnnouncement(FALSE);
                UserIsBanker = TRUE;
            }
        }
    }
    if (TotalRoundCount==0)
        printf("没有进行游戏！\n");
    else
    {
        WinRate = (double)WinRoundCount/(double)TotalRoundCount;
        printf("total rounds:%d, user-win rounds:%d, win rate: %f\n", TotalRoundCount, WinRoundCount, WinRate);
    }
}

