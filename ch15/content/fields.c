#include <stdio.h>
#include <stdbool.h>

#define YES 1
#define NO 0

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

#define SOLID 0
#define DOTTED 1
#define DASHED 2

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct box_props {
    unsigned int opaque         :1;
    unsigned int fill_color     :3;
    unsigned int show_border    :1;
    unsigned int border_color   :3;
    unsigned int border_type    :2;
};

void show_setting(const struct box_props *pb);

int main(void)
{
    struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};

    printf("Originall box setting:\n");
    show_setting(&box);
    puts("----");
    box.opaque = NO;
    show_setting(&box);

    return 0;
}

void show_setting(const struct box_props *pb)
{
    printf("Box is %s.\n", pb->opaque == YES ? "opaque" : "trasnparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n", pb->show_border == YES? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border type is ");
    switch (pb->border_type)
    {
    case SOLID:
        printf("solid.\n");
        break;

    case DOTTED:
        printf("dotted.\n");
        break;
    
    case DASHED:
        printf("dashed.\n");
        break;
    
    default:
        printf("unknown type.\n");
        break;
    }   
}

