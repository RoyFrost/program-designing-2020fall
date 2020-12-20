#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

typedef enum{ T3N, T3X, T3O } TICK_TACK_TOE;
TICK_TACK_TOE tick_tack_toe_phase[3][3]={{T3X,T3X,T3X},{T3X,T3O,T3O},{T3O,T3O,T3N}};//һ��ʾ������
TICK_TACK_TOE tick_tack_toe_phase2[3][3]={{T3X,T3X,T3O},{T3X,T3O,T3O},{T3O,T3X,T3N}};//�ڶ���ʾ������

void Welcome();
void OutputSingle(TICK_TACK_TOE a);//���һ�������
void PrintLine();//����ָ���
void OutputOneLine(TICK_TACK_TOE a[], int n);//���һ������
void OutputPhase(TICK_TACK_TOE a[]);//���������������
int CheckThreePoint(TICK_TACK_TOE a[], int point1, int point2, int point3);//����������Ƿ���ͬ,����
void CheckPhase(TICK_TACK_TOE a[]);//���ʤ������

int main()
{
    Welcome();
    OutputPhase(tick_tack_toe_phase);
    CheckPhase(tick_tack_toe_phase);
    OutputPhase(tick_tack_toe_phase2);
    CheckPhase(tick_tack_toe_phase2);
    return 0;
}

void Welcome()
{
    printf("��������������жϾ�����ʤ���ģ��ṩ������ʾ�����֡�\n");
}

void OutputSingle(TICK_TACK_TOE a)
{
    switch(a)
    {
        case T3N: printf("   ");break;
        case T3X: printf(" X ");break;
        case T3O: printf(" O ");break;
    default: break;
    }
}

void OutputOneLine(TICK_TACK_TOE a[], int n)
{
    OutputSingle(a[n*3+0]);
    printf("|");
    OutputSingle(a[n*3+1]);
    printf("|");
    OutputSingle(a[n*3+2]);
    printf("\n");
}
void PrintLine()
{
    printf("---+---+---\n");
}

void OutputPhase(TICK_TACK_TOE a[])
{
    printf("\n");
    OutputOneLine(a,0);
    PrintLine();
    OutputOneLine(a,1);
    PrintLine();
    OutputOneLine(a,2);
}

int CheckThreePoint(TICK_TACK_TOE a[], int point1, int point2, int point3)
{
    if (a[point1]==a[point2]&&a[point1]==a[point3])
    {
        return a[point1];
    }
    else
        return 0;
}

void CheckPhase(TICK_TACK_TOE a[])
{
    /*һ���а�������Ҫ���*/
    int flag=0;
    int lines[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(int i=0;i<8;i++)
    {
        flag = CheckThreePoint(a,lines[i][0],lines[i][1],lines[i][2]);
        if (flag!=0)
            break;
    }
    switch (flag)
    {
        case 0: printf("����ʤ��!\n");break;
        case 1: printf("X��ʤ��!\n");break;
        case 2: printf("O��ʤ��!\n");break;
        default:break;
    }

}