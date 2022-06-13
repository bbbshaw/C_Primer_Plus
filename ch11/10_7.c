#include <stdio.h>
#include <string.h>

#define SZIE 41

void mystrncopy(char * ptr1, char * ptr2, int n);

int main(void)
{
    char s1[SZIE];
    char s2[SZIE];
    int n;

    printf("Please enter the string for s2:\n");
    while (gets(s2) && s2[0] != '\0')
    {
        puts("Please enter the number of character you want to copy:");
        scanf("%d", &n);

        while (getchar() != '\n')
            continue;
        
        mystrncopy(s1, s2, n);
        puts(s1);
        puts("Please enter the next string you want to copy:");
    }
    puts("Done.");
    return 0;
}

void mystrncopy(char * ptr1, char * ptr2, int n)
{
    int i;

    for (i = 0; i < n; i++)
        *(ptr1 + i) = *(ptr2 + i);

    if (strlen(ptr2) >= n)
        *(ptr1 + i) = '\0';
}