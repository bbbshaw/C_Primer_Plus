#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int main(void)
{
    int input;
    int letter_count = 0;
    int word_count = 0;
    bool in_word = false;
    

    printf("Plz enter the string:\n");

    while ((input= getchar()) != EOF)
    {
        if (isalpha(input))
        {
            letter_count++;
        
            if (!in_word)
            {
                in_word = true;
                word_count++;
            }
        }
        else
            in_word = false;
        
    }
    printf("Words: %d    letters: %d\n", word_count, letter_count);
    printf("The average letters per word: %0.2f\n", (float)letter_count / word_count);

    return 0;
}