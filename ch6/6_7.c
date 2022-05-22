#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_word[100];
    int index;
    int i;


    printf("Plz enter a single word: \n"); 
    scanf("%s", input_word);        //string 的时候不用取地址符号 也不用带[]  array 的时候要 string 最后带\0

    index = strlen(input_word);

    for ( i = (index - 1); i >= 0; i--)
    {
        printf("%c", input_word[i]);
    }
    
    printf("\n");
    
    
    return 0;
}