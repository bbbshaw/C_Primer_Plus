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

void showinfo(struct person *pst);

int main(void)
{
    struct person record[5] ={
        {111223, {"Brian", "B", "Xiao"}},
        {111224, {"Cc", "", "Cc"}},
        {111225, {"Dc", "D", "Dc"}},
        {111226, {"Ec", "E", "Ec"}},
        {111227, {"Fc", "", "Fc"}},
    };

    showinfo(record);

    return 0;
}

void showinfo(struct person *pst)
{
    int i;

    for ( i = 0; i < 5; i++)
    {
        if (strlen(pst[i].name.mname) > 0)
            printf("%s, %s %c. - %d\n", pst[i].name.fname, pst[i].name.lname, pst[i].name.mname[0], pst[i].ssn);

        else
            printf("%s, %s - %d\n",pst[i].name.fname, pst[i].name.lname, pst[i].ssn);
    }
}