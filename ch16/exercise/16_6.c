#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

struct name
{
    char firstname[LEN];
    char lastname[LEN];
};

int mycomp(const void *p1, const void *p2);
void show_array(const struct name array[], int num);

int main(void)
{
    struct name arr[10] = 
    {
        {"B1", "J1"}, {"H2", "L2"}, {"C3", "P3"}, {"K4", "I4"}, {"F5", "S5"}, 
        {"G6", "L6"}, {"Y7", "D7"}, {"Z8", "V8"}, {"R9", "M9"}, {"I10", "T10"}
    };
    
    qsort(arr, 10, sizeof(struct name), mycomp);
    show_array(arr, 10);
}

int mycomp(const void *p1, const void *p2)
{
    int ret;
    const struct name *a1 = p1;
    const struct name *a2 = p2;

    ret = strcmp(a1->firstname, a2->firstname);
    if (ret != 0)
        return ret;
    else 
        return strcmp(a1->lastname, a2->lastname);
}

void show_array(const struct name arr[], int num)
{
    int i;
    for ( i = 0; i < num; i++)
        printf("%s %s\n", arr[i].firstname, arr[i].lastname);
    printf("\n");   
}
