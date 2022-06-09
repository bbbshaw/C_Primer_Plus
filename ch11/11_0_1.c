#include <stdio.h>

int main(void)
{
    char * mesg = "Don't be a fool.";
    char * copy;
    copy = mesg;

    printf("%s\n",copy);
    printf("mesg = %s, &mesg = %p, value = %p.\n", mesg, &mesg, mesg);
    printf("copy = %s, &copy = %p, value = %p.\n", copy, &copy, copy);

    /*
    mesg = Don't be a fool., &mesg = 0x16b2df220, value = 0x104b23f58.
    copy = Don't be a fool., &copy = 0x16b2df218, value = 0x104b23f58.
    */
   
    return 0;
} 