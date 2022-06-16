#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int mode;
    double distance;
    double fuel_consu;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(&mode);
        get_info(mode, &distance, &fuel_consu);
        show_info(mode, distance, fuel_consu);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf("(-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}