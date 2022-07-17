#ifndef P3_H_
#define P3_H_

#include <stdio.h>
#include <math.h>

#define PI 3.1415926

struct polar
{
    double len;
    double angle;
};

struct rect
{
    double x;
    double y;
};

struct rect polar_to_rect(const struct polar *p);

#endif
