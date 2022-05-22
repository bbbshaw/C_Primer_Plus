#include <stdio.h>

int main(void)
{
    int integer;
    unsigned int odd_count = 0, even_count = 0; 
    double odd_sum = 0, even_sum = 0;
    double ave_odd, ave_even;

    printf("Enter the integer ('0' to quit): \n");

    while (scanf("%u", &integer) == 1 )
    {
        if (integer == 0)
        {
           even_count++;
            break;
        }
        if (integer % 2 == 0)
        {
            even_count++;
            even_sum += integer;    
        }

        else if (integer % 2 != 0)
        {
            odd_count++;
            odd_sum += integer;
        }
        
    }
    ave_even = even_sum / even_count;
    ave_odd = odd_sum / odd_count;

    printf("num_odd: %5u ave_odd: %5.2f\n", odd_count, ave_odd);
    printf("num_even: %5u ave_even: %5.2f\n", even_count, ave_even);

    return 0;
}
