#include <stdio.h>


void Temperature (double f_tem);

int main(void)
{
    double f_tem;
    printf("Plz enter the Fa temperature: \n");

    //if value is not, stop loop
    while (scanf("%lf", &f_tem))
    {
        Temperature(f_tem);
        printf("Enter the next value: \n");

    }
    printf("Done. \n");
    return 0;

}

//Tem function
void Temperature (double f_tem)
{
    const float F_TO_C_1 = 1.8;
    const float F_TO_C_2 = 32.0;
    const float C_TO_K = 273.16;

    double c_tem;
    double k_tem;


    c_tem = F_TO_C_1 * (f_tem - F_TO_C_2);
    k_tem = c_tem + C_TO_K;

    printf("%0.2lfF = %0.2lfC = %0.2lfK\n", f_tem, c_tem, k_tem);
    
}


