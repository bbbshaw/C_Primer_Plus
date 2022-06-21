#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main (void)
{
    double numbers[SIZE];
    int i;
    const char *file = "number.dat";
    FILE *iofile;
    int index;
    long pos;
    double value;

    //create a set of double values
    for ( i = 0; i < SIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);

    //attempt to open the file
    if((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }

    //write array in binary format to file
    fwrite(numbers, sizeof(double), SIZE, iofile);
    fclose(iofile);

    //attempt to open the file
    if((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr,"Could not open file %s for read.\n", file);
        exit(EXIT_FAILURE);
    }

    //read the item for file
    printf("Enter the index in range from 0 to %d.\n", SIZE - 1);
    while(scanf("%d", &index) == 1 && index > 0 && index < SIZE)
    {
        pos = (long) index * sizeof(double);    //cal the offset
        fseek(iofile, pos, SEEK_SET);       // target, offset, beginning
        fread(&value, sizeof(double), 1, iofile);   //pointer, size, unit, target 
        printf("The value there is %f.\n", value);
        printf("Next inde (out of range to quit):\n");
    }
    fclose(iofile);
    printf("Done.\n");

    return 0;
}