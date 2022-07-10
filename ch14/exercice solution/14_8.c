#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LEN 21
#define CAPACITY 12

struct seat 
{
    int seatid;
    bool assigned;
    char lname[LEN];
    char fname[LEN];
};

struct seat seats[CAPACITY];

char getchoice(void);
void clear(void);
char * s_gets(char * st, int n);
void showemptynum(struct seat *pst);
void showemptylist(struct seat *pst);
void showalpha(struct seat *pst);
void assginseat(struct seat *pst);
void delassign(struct seat *pst);


int main(void)
{   
    struct seat temp;
    char choice;
    int i;
    FILE *fp;

    //initial 
    for (i = 0; i < CAPACITY; i++)
    {
        seats[i].seatid = i;
        seats[i].assigned = false;
    }

    if ((fp = fopen("seats.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Can't open filr.\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&temp, sizeof(struct seat), 1, fp) == 1)
    {
        seats[temp.seatid] = temp;
    }
    
    while((choice = getchoice()) != 'f')
    {

        switch (choice)
        {
        case 'a':
            showemptynum(seats);
            break;
        
        case 'b':
            showemptylist(seats);
            break;
        
        case 'c':
            showalpha(seats);
            break;
        
        case 'd':
            assginseat(seats);
            break;

        case 'e':
            delassign(seats);
            break;

        default: puts("Error.");
        }
        puts("");
    }
    fclose(fp);

    if ((fp = fopen("seats.dat", "wb")) == NULL )
    {
        fprintf(stderr, "Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    if (fwrite(seats, sizeof(struct seat), CAPACITY, fp) != CAPACITY)
    {
        fprintf(stderr, "Error writing data to file.\n");
    }
    fclose(fp);

    return 0;
}

char getchoice(void)
{
    char ch;

    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");

    while ((ch = getchar()) != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f')
    {
        puts("Invalid input. Please enter again:");
        clear();
    }
    clear();

    return ch;
}

void clear(void)
{
    while (getchar() != '\n')
        continue;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else 
            while (getchar() != '\n')
                continue;   
    }
    return ret_val;
}

void showemptynum(struct seat *pst)
{
    int i;
    int count = 0;

    for ( i = 0; i < CAPACITY; i++)
    {
        if (!pst[i].assigned)
            count++;
    }
    printf("%d empty seats.\n", count);
}

void showemptylist(struct seat *pst)
{
    int i;
    for ( i = 0; i < CAPACITY; i++)
    {
        if (!pst[i].assigned)
            printf("NO.%d seat is empty\n", pst[i].seatid);
    }
}

void showalpha(struct seat *pst)
{
    int i;

    puts("Seat List:");
    for ( i = 0; i < CAPACITY; i++)
        printf("No.%d %s %s\n", pst[i].seatid, pst[i].fname, pst[i].lname);
}

void assginseat(struct seat *pst)
{
    int seat_num;

    printf("Empty list:\n");
    showemptylist(pst);

    printf("Enter the empty seat number:\n");
    scanf("%d", &seat_num);
    clear();

    printf("Enter the first name of the passenger:\n");
    s_gets(pst[seat_num].fname, LEN);

    printf("Enter the last name of the passenger:\n");
    s_gets(pst[seat_num].lname, LEN);

    pst[seat_num].assigned = true;

    puts("Passenger checked in.\n");
}

void delassign(struct seat *pst)
{
    int i;
    int tempnum;

    for ( i = 0; i < CAPACITY; i++)
    {
        if(pst[i].assigned)
            printf("No.%d First Name:%s Last Name:%s\n", pst[i].seatid, pst[i].fname, pst[i].lname);
    }
    puts("------------");
    puts("Enter the seat number that you want to delete the assignment:");
    scanf("%d", &tempnum);
    clear();

    strcpy(pst[tempnum].fname, "");
    strcpy(pst[tempnum].lname, "");
    pst[tempnum].assigned = false;
    pst[tempnum].seatid = 0;
    puts("Deleted.\n");
}


