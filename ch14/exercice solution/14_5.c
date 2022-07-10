#include <stdio.h>

#define LEN 21
#define CSIZE 4
#define GRADLEN 3

struct fullname 
{
    char fname[LEN];
    char lname[LEN];
};

struct student 
{
    struct fullname name;
    float scores[GRADLEN];
    float ave_scores;
};

void getgrades(struct student * students);
void cal_ave(struct student * students);
void showinfo(struct student * students);

int main(void)
{
    int i;

    struct student students[CSIZE] = {
        {.name = {"Brian", "Shaw"}},
        {.name = {"Kevin", "Durant"}},
        {.name = {"Lebron", "James"}},
        {.name = {"Harry", "Potter"}}   
    };

    for ( i = 0; i < CSIZE; i++)
        getgrades(&students[i]);

    for ( i = 0; i < CSIZE; i++)
        cal_ave(&students[i]);
    
    for ( i = 0; i < CSIZE; i++)
        showinfo(&students[i]);
    
    return 0;
}

void getgrades(struct student * students)
{
    int i;

    for ( i = 0; i < GRADLEN; i++)
    {
        printf("Please enter the %d score for %s %s:", i + 1, students->name.fname, students->name.lname);
        while (scanf("%f", students->scores + i) != 1)
            while (getchar() != '\n')
                continue;
        while (getchar() != '\n')
            continue;
    }
}

void cal_ave(struct student * students)
{
    int i;
    float total = 0;

    for ( i = 0; i < GRADLEN; i++)
        total += students->scores[i];

    students->ave_scores = total / GRADLEN;
}

void showinfo(struct student * students)
{
    printf("Name: %s %s\n", students->name.fname, students->name.lname);
    
    for (int i = 0; i < GRADLEN; i++)
    {
        printf("Grade %d: %.2f\n", i, students->scores[i]);
    }
    printf("Average Grade: %.2f\n", students->ave_scores);
}