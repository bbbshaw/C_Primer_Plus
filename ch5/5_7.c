#include <stdio.h>

void operand (int first_int);

int main(void)
{
    int first_int;

    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: \n");
    scanf("%d", &first_int);

    operand(first_int);


    return 0;

}

void operand (int first_int)
{
    int next_number, result;


    printf("Enter next number for first operand (<= 0 to quit): \n");
    scanf("%d", &next_number);

    result = next_number % first_int;
    
    while (next_number > 0 )
    {
        printf("%d %% %d is %d\n", next_number, first_int, result);
        printf("Enter next number for first operand (<= 0 to quit): \n");
        scanf("%d", &next_number);
    }
    printf("Done.\n");
}
