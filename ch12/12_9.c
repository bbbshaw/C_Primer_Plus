#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 41

int main(void)
{
    int i, j, n;

    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    while (getchar() != '\n')
        continue;
    
    printf("Enter %d words now:\n", n);

    char ** ptr = (char **) malloc(n * sizeof (char *));

    for (i = 0; i < n; i++)
    {
        char *word = (char *) malloc(LIMIT * sizeof (char));
        scanf("%s", word);
        ptr[i] = word;
    }

    printf("Here are your words:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", *(ptr + i));
    }

    free(ptr);

    return 0;
}