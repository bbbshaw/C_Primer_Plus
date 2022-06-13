#include <stdio.h>
#include <string.h>

#define SIZE 41

char * string_in(char *s1, char *s2);

int main(void)
{
    char str1[SIZE];
    char str2[SIZE];
    char *flag;

    puts("Please enter the first string:");
    gets(str1);
    while(str1[0] != '\0')    
    {
        puts("Please enter the second string to look for:");
        gets(str2);

        flag = string_in(str1, str2);
        if (flag)
            printf("Found s2 in s1 at %p\n", flag);
        else
            puts("Not found.");
        
        puts("Please enter the first string:");
        gets(str1);
    }
  
    printf("Done.\n");
    return 0;
}

char * string_in(char * s1, char * s2)
{
    int len2 = strlen(s2);
    int try_times = strlen(s1) - len2 + 1;
    int flag;

    while ((flag = strncmp(s1, s2, len2)) && try_times--)
        s1++;
  
    if (flag)
        return NULL;
    else 
        return (char *)s1;
}