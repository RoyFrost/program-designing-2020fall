#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"

typedef enum{ T3N, T3X, T3O } TICK_TACK_TOE;
TICK_TACK_TOE tick_tack_toe_phase[3][3];

void Welcome();
void OutputSingle(TICK_TACK_TOE a);//���һ�������
void PrintLine();//����ָ���
void OutputOneLine(TICK_TACK_TOE a[], int n);//���һ������
void OutputPhase(TICK_TACK_TOE a[]);//���������������

int main()
{
    Welcome();

    /*���벼������*/
    for (int i=0;i<3;i++)
        tick_tack_toe_phase[0][i]=T3X;
    for (int i=0;i<3;i++)
        tick_tack_toe_phase[1][i]=T3N;
    for (int i=0;i<3;i++)
        tick_tack_toe_phase[2][i]=T3O;
    OutputPhase(tick_tack_toe_phase);
    return 0;
}

void Welcome()
{
    printf("��������������洢0.2.2�ľ����岼�ֲ���������ġ�\n");
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
    OutputSingle(a[n*3+0]);//��ά����ֱ�ӿ���һά����������
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