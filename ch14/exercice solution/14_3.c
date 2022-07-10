#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

char * s_gets(char *st, int n);

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    int top, seek;
    struct book temp;

    printf("Enter the book title.\n");
    printf("Press enter at the start of a line to stop.\n");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author:\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value:.\n");
        scanf("%f", &library[count++].value);

        while(getchar() != '\n')
            continue;
        
        if (count < MAXBKS)
            printf("Plz enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Book list:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

        printf("-----------------------\n");
        printf("Here is the list of your books value:\n");
        for ( top = 0; top < count - 1; top++)
        {
            
            for (seek = top + 1; seek < count; seek++)
            {
                if (library[top].value > library[seek].value)
                {
                    temp = library[top];
                    library[top] = library[seek];
                    library[seek] = temp;
                }
            }
            
        }
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

        printf("-----------------------\n");
        printf("Here is the list of your books by alphabetized:\n");

        for ( top = 0; top < count - 1 ; top++)
        {
            for (seek = top + 1; seek < count; seek++)
            {
                if (strcmp(library[top].title, library[seek].title))
                {
                    temp = library[top];
                    library[top] = library[seek];
                    library[seek] = temp;
                }
            }
        }
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
    
    else 
        printf("No books were founded.\n");

    return 0;
}

char * s_gets(char *st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar() != '\n')
                continue;
    }
    return ret_val;  
}
