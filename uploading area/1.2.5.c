#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"

int main()
{
    double principal, interest, RoI, deposit;//本金、利息、利率、总存款

    /*获得初始条件*/
    printf("Input the initial principal of the deposit\(Unit: %%\):");
    principal = GetRealFromKeyboard();
    printf("Input the rate of interest\(Unit: %%\):");
    RoI = GetRealFromKeyboard()/100;

    /*计算并给出最终结果*/
    interest = principal * RoI ;
    deposit = principal + interest;
    printf("The final deposit is %.2lf ", deposit);
    return 0;
}
