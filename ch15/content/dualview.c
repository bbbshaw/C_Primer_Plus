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
//bit[0]
#define OPAQUE 0x1
//bit[3:1]
#define FILL_BLACK 0x0
#define FILL_RED 0x2
#define FILL_GREEN 0x4
#define FILL_YELLOW 0x6
#define FILL_BLUE 0x8
#define FILL_MAGENTA 0xA
#define FILL_CYAN 0xC
#define FILL_WHITE 0xE
//bit[4]
#define BORDER 0x10
//bit[7:5]
#define BORDER_BLACK 0x00
#define BORDER_RED 0x20
#define BORDER_GREEN 0x40
#define BORDER_YELLOW 0x60
#define BORDER_BLUE 0x80
#define BORDER_MAGENTA 0xA0
#define BORDER_CYAN 0xC0
#define BORDER_WHITE 0xE0
//bit[9:8]
#define BORDER_SOLID 0x000
#define BORDER_DOTTED 0x100
#define BORDER_DASHED 0x200


struct box_props {
    unsigned int opaque         :1;
    unsigned int fill_color     :3;
    unsigned int show_border    :1;
    unsigned int border_color   :3;
    unsigned int border_type    :2;
};

union views
{
    struct box_props st_views;
    unsigned int ui_view;
};


void show_setting(const struct box_props *pb);
void show_setting1(unsigned int us);

int main(void)
{
    //struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};
    union views box = {{YES, YELLOW, YES, GREEN, DASHED}};

    printf("Originall box setting:\n");
    show_setting(&box);
    puts("----");
    box.ui_view &= ~(OPAQUE);
    
    box.ui_view &= ~0xE;
    box.ui_view |= FILL_WHITE;

    box.ui_view &= ~(BORDER);

    box.ui_view &= ~(0xE0);
    box.ui_view |= BORDER_BLACK;

    box.ui_view &= ~(0x300);
    box.ui_view |= BORDER_SOLID;
    
    show_setting1(box.ui_view);

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

void show_setting1(unsigned int us)
{
    printf("Box is %s.\n", (us & OPAQUE)== YES ? "opaque" : "trasnparent");
    printf("The fill color is %s.\n", colors[(us>>1) & 0x7]);
    printf("Border %s.\n", (us & BORDER) == BORDER ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[(us>>5) & 0x7]);
    printf("The border type is ");
    switch (us & 0x300)
    {
    case BORDER_SOLID:
        printf("solid.\n");
        break;

    case BORDER_DOTTED:
        printf("dotted.\n");
        break;
    
    case BORDER_DASHED:
        printf("dashed.\n");
        break;
    
    default:
        printf("unknown type.\n");
        break;
    }   
}

