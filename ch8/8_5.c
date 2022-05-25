#include <stdio.h>

int main(void)
{
    int guess = 50;
    int lower_bound = 1;
    int upper_bound = 100;
    char response;

    printf("Plz pick an number between 1 and 100.\n");
    printf("If the program guess is greater than the number, reponse 'g'\n");
    printf("If the program guess is smaller than the number, reponse 's'\n");
    printf("Enter 'y' if correct!\n");
    printf("The program guess: %d\n", guess);
    printf("Enter: ");

    while ((response = getchar()) != 'y')
    {
        
        if (response == 'h')
        {
            upper_bound = guess - 1;
        }
        else if (response =='l')
        {
            lower_bound = guess + 1;
        }
        else 
        {
            printf("Invalid input!\n");
            continue;
        }

        guess = (lower_bound + upper_bound) / 2;
        
        printf("Is it %d?\n", guess);
        printf("Enter:");

        while (getchar() != '\n')
        {
            continue;
        }
        
    }
    printf("Great!\n");
    
    
    return 0;

}