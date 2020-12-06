#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"

void Welcome();
int Roll();//������
int UserRoll();//�û������ӣ�����-1��ʾ���������ӣ����˳���Ϸ
BOOL Round();//һ���غ�
void ResultAnnouncement(BOOL _result);//�����Ϸ�����ʾ
void Game();//��Ϸ��ʼ

int main()
{
    Welcome();
    Game();
    return 0;
}

void Welcome()
{
    printf("��������У��û��ͼ����������������Ϸ��\n");
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
            printf("������g����һ�����ӡ�����q��Q��������Ϸ\n");
            temp = getchar();
            fflush(stdin);
            if (temp =='q'||temp=='Q')
                return -1;
            else if (temp=='g')
                return Roll();
            else
                printf("���벻�Ϸ�������������\n");
        }
}//����-1��ʾ��Ҫ�˳���Ϸ

void ResultAnnouncement(BOOL result)
{
    if (result)
        printf("�û�ʤ����\n");
    else
        printf("�û����ˣ�\n");
}

void Game()
{
    int NumOfCom, NumOfUser;//������������û�����
    int TotalRoundCount,WinRoundCount;//�ܻغϼ�����ʤ���غϼ���
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
            printf("�û�����%d\n",NumOfUser);
            NumOfCom=Roll();
            printf("���������%d\n",NumOfCom);
        }
        else
        {
            NumOfCom=Roll();
            printf("���������%d\n",NumOfCom);
            NumOfUser=UserRoll();
            if (NumOfUser==-1) break;
            printf("�û�����%d\n",NumOfUser);
        }


        /*ÿһ�ֵ���Ӯ�жϣ�����¼*/
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
        printf("û�н�����Ϸ��\n");
    else
    {
        WinRate = (double)WinRoundCount/(double)TotalRoundCount;
        printf("total rounds:%d, user-win rounds:%d, win rate: %f\n", TotalRoundCount, WinRoundCount, WinRate);
    }
}
