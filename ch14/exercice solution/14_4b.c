#include <stdio.h>
#include <string.h>

#define LEN 21

struct fullname
{
    char fname[LEN];
    char mname[LEN];
    char lname[LEN];
};

struct person
{
    int ssn;
    struct fullname name; 
};

void showinfo(struct person pers);

int main(void)
{
    int i;

    struct person record[5] ={
        {111223, {"Brian", "B", "Xiao"}},
        {111224, {"Cc", "", "Cc"}},
        {111225, {"Dc", "D", "Dc"}},
        {111226, {"Ec", "E", "Ec"}},
        {111227, {"Fc", "", "Fc"}},
    };

    for (size_t i = 0; i < 5; i++)
    {
        showinfo(record[i]);
    }
    return 0;
}

void showinfo(struct person pers)
{
    int i;

    if (strlen(pers.name.mname) > 0)
        printf("%s, %s %c. - %d\n", pers.name.fname, pers.name.lname, pers.name.mname[0], pers.ssn);

    else
        printf("%s, %s - %d\n",pers.name.fname, pers.name.lname, pers.ssn);  
}