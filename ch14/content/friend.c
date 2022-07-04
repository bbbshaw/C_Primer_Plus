#include <stdio.h>

#define LEN 41

struct names
{
    char first[LEN];
    char second[LEN];
};

struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2] = {
        {
            {"Brian", "Shaw"},      //asign value use ","
            "grilled salmon",
            "Personality coach",
            581112.00
        },
        {
            {"Kevin", "Kim"},
            "salad",
            "soft engineer",
            188383.33
        }
    };

    struct guy *him;    //pointer to a structure

    //printf("%s\n", fellow.handle.first);
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);

    him = &fellow[0];       //pointer to structure add "&""   
    printf("address #1: %p #2: %p\n", him, him + 1);   

    printf("him ->income: %.2f.\n", him->income);
    printf("(*him).come is %.2f.\n", (*him).income);

    return 0;
}