#include <stdio.h>

void Fibonacci(int n);

int main(void)
{
    int n;

    printf("Please enter an integer: ");
    scanf("%d", &n);
    Fibonacci(n);

    return 0;

}

void Fibonacci(int n)
{
    int Fn = 0;
    int Fn_1 = 0;
    int Fn_2 = 1;

    printf("The Fibonacci sequence is:\n");
    printf("%d\n", Fn_1);
    printf("%d\n", Fn_2);
    
    while (Fn < n)
    {
        Fn = Fn_1 + Fn_2;
        printf("%d\n", Fn);
     
        Fn_1 = Fn_2;
        Fn_2 = Fn;    
    }   
}