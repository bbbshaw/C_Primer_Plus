#include <stdio.h>

int main(void)
{
    float width, length;

    printf("Plz enter the lenght: \n");
    while (scanf("%f", &length) == 1)
    {
        printf("Length: %0.2f\n", length);
        printf("Plz enter the width: \n");
        
        if(scanf("%f", &width) != 1)
        {
            printf("You enter a unvalid number!\n");
            break;
        }
        printf("Width: %0.2f \nLength: %0.2f \nArea: %0.2f\n", width, length, width * length);

        printf("Enter the length (q to quit): \n");
    }
    printf("Invalid number. Done.\n");

    return 0;
}