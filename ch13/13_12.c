#include <stdio.h>
#include <stdlib.h>

#define ROW 20
#define COL 30
#define SIZE 41

int main(void)
{
    int arr[ROW][COL];
    char file_name[SIZE];
    FILE *fp;
    int i,j;
    
    puts("Plz enter a file name:");
    gets(file_name);

    if ((fp = fopen(file_name, "r")) == NULL) 
    {
        fprintf(stderr, "Can't open file %s .\n", file_name);
        exit(EXIT_FAILURE);
    }

    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; i < COL; j++)
            fscanf(fp, "%d", &arr[i][j]);  
    }

    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            switch (arr[i][j])
            {
            case 0:
                putchar(' ');
                break;

            case 1:
                putchar('.');
                break;
            
            case 2:
                putchar('\'');
                break;

            case 3:
                putchar(':');
                break;

            case 4:
                putchar('~');
                break;

            case 5:
                putchar('*');
                break;
            
            case 6:
                putchar('=');
                break;

            case 7:
                putchar('+');
                break;

            case 8:
                putchar('%');
                break;

            case 9:
                putchar('#');
                break;

            default:
                printf("E");
            }
            putchar('\n');
        }
        
    }
    fclose(fp);
    
    return 0;
}