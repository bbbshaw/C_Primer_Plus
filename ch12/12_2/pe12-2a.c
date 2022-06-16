#include <stdio.h>
#include "pe12-2a.h"

//static int mode;
//static double distance;
//static double fuel_consu;

void set_mode(int *mode)
{
    if (*mode != ME_M && *mode != US_M)
    {
        printf("Invalid mode specified mode. Mode 1(US) used.\n");
        *mode = US_M;
    }
}

void get_info(int mode, double *distance, double *fuel_consu)
{
    if (mode == ME_M)
    {
        printf("Enter distance traveled in kilometers:");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters:");
        scanf("%lf", fuel_consu);
    }
    else
    {
        printf("Enter distance traveled in miles:");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", fuel_consu);
    }
}
void show_info(int mode, double distance, double fuel_consu)
{
    if(mode == ME_M)
        printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel_consu / (distance / 100));
    else
        printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel_consu);
}