#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 20
#define PLAYERNUM 19

struct player
{
    char fname[NAMELEN];
    char lname[NAMELEN];
    unsigned int bat, hits, walks, ribs;
    float bat_ave;
};

void cal_ave(struct player * players);
void showdata(const struct player * players, int size);

int main(void)
{
    struct player players[PLAYERNUM];
    int i;

    for ( i = 0; i < PLAYERNUM; i++)
        players[i] = (struct player) {"", "", 0, 0, 0, 0, 0};
    
    FILE *fp;
    int number;
    char firstname[NAMELEN];
    char lastname[NAMELEN];
    unsigned int bat, hits, walks, ribs;

    if ((fp = fopen("roster.txt", "r")) == NULL)
    {
        fprintf(stderr, "Could'n open file - toster.txt.\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(fp, "%d %s %s %u %u %u %u", &number, firstname, lastname, &bat, &hits, &walks, &ribs) == 7)
    {
        if (players[number].fname[0] == '\0')
        {
            strncpy(players[number].fname, firstname, NAMELEN);
            strncpy(players[number].lname, lastname, NAMELEN);
        }
        players[number].bat += bat;
        players[number].hits += hits;
        players[number].walks += walks;
        players[number].ribs += ribs;
    }

    for ( i = 0; i < PLAYERNUM; i++)
        cal_ave(&players[i]);
    
    showdata(players, PLAYERNUM);

    fclose(fp);

    return 0;
}

void cal_ave(struct player * players)
{
    players->bat_ave = players->hits / (float) players->bat;
}

void showdata(const struct player * players, int size)
{
	unsigned int bat = 0, hits = 0, walks = 0, ribs = 0;


	for (int i = 0; i < PLAYERNUM; i++, players++)
	{
		printf("%2d ", i);
		printf("%*s %*s %u %u %u %u %.3f\n", NAMELEN, players[i].fname, NAMELEN,
		       players[i].lname, players[i].bat, players[i].hits, players[i].walks,
		       players[i].ribs, players[i].bat_ave);
    }
}