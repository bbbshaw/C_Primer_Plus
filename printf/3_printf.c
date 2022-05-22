#include <stdio.h>
#include <string.h>
#define PAGE 931
#define BLURB "Hello World!"


int main(void)
{
    // width
    printf("*%d*\n", PAGE);     //
    printf("*%2d*\n", PAGE);        //小于字段 自动增加
    printf("*%10d*\n", PAGE);       //minimum field width
    printf("*%-10d*\n", PAGE);      //left-justified 左对齐

    //float
    const double RENT = 3852.99;

    printf("*%f*\n", RENT);     //
    printf("*%e*\n", RENT);     //e-notation
    printf("*%4.2f*\n", RENT);      //4 characters wide with 2 digits
    printf("*%3.1f*\n", RENT);      //精读为一位小数 四舍五入
    printf("*%10.3f*\n", RENT);     //10 characters wide with 3 digits
    printf("*%10.3e*\n", RENT);     //e-notation 10 characters wide with 3 digits
    printf("*%+4.2f*\n", RENT);     // pos with + / nag with -
    printf("*%010.2f*\n", RENT);        // 0 fill the empty 

    // #
    printf("%x, %#x, %#X\n", 31, 31, 31);       // start with 0 & lower ; 0 & upper
    printf("*%d*, *% d*, *% d\n*", 42, 42, -42);        // space before d indicates the p/n 
    printf("*%5d*", "*%5.3d*","*%05d*","%05.3d\n", 6, 6, 6, 6);       //*    6*/*  006*/*00006*/* ！如果0和精读同时出现 0忽视

    // string
    printf("*%s*\n", BLURB);
    printf("*%2s*\n", BLURB);
    printf("*%24s*\n", BLURB);
    printf("*%24.5s*\n", BLURB);        // Hello
    printf("%-24.5s\n", BLURB);     // left-justified

    return 0;
}

