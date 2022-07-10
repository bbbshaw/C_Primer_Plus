#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 40
#define MAXBKS 20

struct book {
    char title[40];
    char author[40];
    float value;
};

char * s_gets(char * st, int n);
void clear(void);
char getchoice(void);
int addbk(struct book *library, int count);
void changeinfo(struct book *library, int count);
void printinfo(struct book *library, int count);
int delbk(struct book *library, int count);

int main(void)
{
    char name[LEN];
    struct book library[MAXBKS];
    char ch;
    FILE *fp;
    int count = 0;
    int filecount = 0;
    char choice;
    int index;

    printf("Please enter the file name:\n");
    s_gets(name, LEN);
    while ((fp = fopen(name, "a+b")) == NULL)
    {
        fprintf(stderr, "Can't open file - %s.\n", name);
        exit(EXIT_FAILURE);
    }
    rewind(fp);

    while (count < MAXBKS && fread(&library[count], sizeof(struct book), 1, fp) == 1)
        count ++;
    
    filecount = count;

    if (count == MAXBKS)
    {
        puts("The book file is full.");
        exit(EXIT_FAILURE);
    }

    while((choice = getchoice()) != 'q')
    {
        switch (choice)
        {
            case 'a': count = addbk(library, count);
                    break;
            case 'c': changeinfo(library, count);
                    break;
            case 'd': count = delbk(library, count);
                    break;
            case 'p': printinfo(library, count);
                    break;
            default: printf("Program error.\n");
                    break;
        }
    }
    if (count > 0)
    {
        puts("Here is the book list:");
        for ( index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        fwrite(&library[filecount], sizeof(struct book), count - filecount, fp);        //write the book information into file
    }
    else 
        puts("No books.");
    
    return 0;
}

char * s_gets(char * st, int n)
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

void clear(void)
{
    while (getchar() != '\n')
        continue;   
}

char getchoice(void)
{
    char ch;
    
    printf("Please input your choice:\n");
    printf("a. add some books        c. change a book\n");
    printf("d. delete a book         p. print all books\n");
    printf("q. quit.\n");
    while ((ch = getchar()) != 'a' && ch != 'c' && ch != 'd' &&
        ch != 'p' && ch != 'q')
    {
        clear();
        printf("Please input the right character.\n");
    }
    clear();

    return ch;
}

int addbk(struct book *library, int count)
{
    int i;

    if (count >= MAXBKS)
    {
        printf("The library is full.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        puts("Please enter a new book titles.(Press ENTER at the start of a line to stop)");
        while (count < MAXBKS && s_gets(library[count].title, LEN) != NULL && library[count].title[0] != '\0')
        {
            puts("Now enter the author of this book:");
            s_gets(library[count].author, LEN);
            puts("Now enter the price of this book:");
            scanf("%f", &library[count].value);
            count++;
            clear();
            if (count < MAXBKS)
                puts("Please enter the title of next book:");  
        }
    }
    return count;
}

void changeinfo(struct book *library, int count)
{
    char name[LEN];
    int i;

    puts("Please enter the book you want to edit:");
    while(s_gets(name, LEN) != NULL && name[0] != '\0')
    {
        for ( i = 0; i < count; i++)
            if(strcmp(name, library[i].title) == 0)
            {
                printf("Book %s founded.\n", name);
                
                puts("Please edit the title:");
                s_gets(library[i].title, LEN);

                puts("Please edit the author:");
                s_gets(library[i].title, LEN);

                printf("Please exit the price:\n");
                scanf("%f", &library[i].value);

                printf("Book %s has been changed.", name);  
                puts("Enter the next book:");
            }
            else
                printf("%s not founded.\n", name);
    }
}

int delbk(struct book *library, int count)
{
    int i, j;
    char name[LEN];

    puts("Please enter the book you want to delete:");
    while(s_gets(name, LEN) != NULL && name[0] != '\0')
    {
        for ( i = 0; i < count; i++)
            if(strcmp(name, library[i].title) == 0)
            {   
        
                for ( j = i; j < count; j++)
                {
                    strcpy(library[j].title, library[j + 1].title);
                    strcpy(library[j].author, library[j + 1].author);
                    library[j].value = library[j + 1].value;
                }
                count--;
            }
    puts("Please enter the next book you wan to delete:");
    }
    return count;
}

void printinfo(struct book *library, int count)
{
    int i;

    if (count < 0)
        printf("No books.\n");
    
    for ( i = 0; i < count; i++)
    {
        printf("Here is the book list:\n");
        printf("%s by %s :$ %.2f\n", library[i].title, library[i].author, library[i].value);
    }
}


