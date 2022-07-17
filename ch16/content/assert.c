#include <stdio.h>

//#define NDEBUG

#include <assert.h>

int main(void)
{
    int num;

    printf("Enter an integer > 0:\n");
    while (1)
    {
        scanf("%d", &num);
        assert(num >= 0);
        printf("num = %d\n", num);
        printf("Enter the next integer:\n");
    }
    
    return 0;
}