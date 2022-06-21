#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fps, *fpt;
    int ch;

    //check the commond line
    if (argc != 3)
    {
        fprintf(stderr, "Invalid inpput.\n");
        exit(EXIT_FAILURE);
    }
    
    //attempt to open source file
    if((fps = fopen(argv[1],"rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s file.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    //attempt to open taget file
    if((fpt = fopen(argv[1],"wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s file.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //copy the source file
    while((ch = getc(fps)) != EOF)
        putc(ch, fpt);
    
    //close the file
    if (fclose(fps) != 0 || fclose(fpt) != 0)
    fprintf(stderr, "Error in closing files.\n");
    
    return 0;
}