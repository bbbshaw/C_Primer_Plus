#include <stdio.h>

#define SIZE 81

void get_n_words(char * string, int n);

int main(void)
{
    char input[SIZE];
    int num;

    puts("How many character you want to read:");
    scanf("%d", &num);
    getchar();
    puts("Plz enter a string:\n");
    gets(input);
    get_n_words(input, num);
    puts(input);

    return 0;
}

void get_n_words(char * string, int n)
{
    for (int i = n; i < SIZE; i++)
            *(string+i) = '\0';
}
