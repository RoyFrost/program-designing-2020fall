#include <stdio.h>
#include <stdlib.h>
#include "..\zylib\zylib.c"


int printline()
{
    for (int i = 0; i < 51; i++)
    {
        printf("-");
    }
    printf("\n");
    return 0;
}
/*�����ָ���*/

int main()
{
    struct MYCOUNTRY
    {
    STRING name;
    double area;
    double population;
    double GDP;
    }country[5];//����һ���ṹ���洢ÿһ�е���Ϣ

    /*�ֶ��洢����*/
    country[0].name = "China"; country[0].area = 960.00; country[0].population = 135700.00; country[0].GDP = 9240.00;
    country[1].name = "Iceland"; country[1].area = 10.30; country[1].population = 32.30; country[1].GDP = 15.33;
    country[2].name = "India"; country[2].area = 297.47; country[2].population = 125200.00; country[2].GDP = 1877.00;
    country[3].name = "Madagascar"; country[3].area = 62.70; country[3].population = 2292.00; country[3].GDP = 10.61;
    country[4].name = "Maldive"; country[4].area = 0.03; country[4].population = 34.50; country[4].GDP = 2.30;


    /*�ṹ������*/
    printline();
    printf("COUNTRY     AREA\(10K km2\)  POP.\(10K\)  GDP\(Billion$\)\n");
    printline();
    for (int i = 0; i < 5 ; i++)
    {
        printf("%-10s  %13.2lf  %9.2lf  %-13.2lf\n", country[i].name, country[i].area, country[i].population, country[i].GDP);
    }
    printline();

    return 0;
}
