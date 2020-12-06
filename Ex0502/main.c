#include <stdio.h>
#include <stdlib.h>
#include "../zylib/zylib.h"
#include "../zylib/zyrandom.h"


void Welcome();
int Roll();//������
BOOL Round();//һ���غ�
void ResultAnnouncement(BOOL _result);//�����Ϸ�����ʾ

int main()
{
    Randomize();
    ResultAnnouncement(Round());
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

BOOL Round()
{
    int NumOfCom, NumOfUser;//������������û�����
    char temp;
    NumOfCom = Roll();
    while (1)
    {
        printf("������g����һ�����ӡ�\n");
        temp = getchar();
        fflush(stdin);
        if (temp=='g')
        {
            NumOfUser=Roll();
            break;
        }
        else
        {
            printf("���벻�Ϸ���������g\n");
            continue;
        }
    }
    printf("C=%d,U=%d\n",NumOfCom,NumOfUser);
    return NumOfUser<NumOfCom ? FALSE : TRUE;
}

void ResultAnnouncement(BOOL result)
{
    if (result)
        printf("�û�ʤ����\n");
    else
        printf("�û����ˣ�\n");
}