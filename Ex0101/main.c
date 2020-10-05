#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.h"
#include "..\zylib\zylib.c"

int main()
{
    double principal, interest, RoI, deposit;//本金、利息、利率、总存款

    /*从键盘接收数据*/
    printf("Input the initial principal of the deposit\(Unit: ￥\):");
    principal = GetRealFromKeyboard();
    printf("Input the rate of interest\(Unit: %\):");
    RoI = GetRealFromKeyboard();

    /*计算最终结果*/
    interest = principal * RoI ;
    deposit = principal + interest;
    printf("The final deposit id %.2lf￥", deposit);
    return 0;
}
