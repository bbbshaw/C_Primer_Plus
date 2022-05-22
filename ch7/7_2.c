#include <stdio.h>

#define STOP '#'
#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'

int main(void)
{
    unsigned int count = 0;
    char ch;

    printf("Enter the character (%c to STOP): \n", STOP);

    while((ch = getchar()) != STOP)
    {
        switch (ch)
        {
            case SPACE:
                    printf("' ':%3d ", ch);
                    break;
            case TAB:
                    printf("\\t:%3d ", ch);
                    break;
            case NEWLINE:
                    printf("\\n:%3d ", ch);
                    break;
            default:
                    printf(" %c: %3d ", ch, ch);

        }
        count++;    
    }
    
    if (count % 8 == 0)
    {
        printf("\n");
    }
    
    printf("Done.\n");
    
    return 0;
}