#include "p3.h"

int main(void)
{
    struct polar input;
    struct rect result;

    printf("Please enter the len and the angle in polar:\n");
    scanf("%lf %lf", &input.len, &input.angle);
    result = polar_to_rect(&input);
    printf("x = %.2lf, y = %.2lf \n", result.x, result.y);

    return 0;
}

struct rect polar_to_rect(const struct polar *p)
{
    struct rect temp;
    double radian;

    radian = (PI/180) * p->angle;

    temp.x = p->len * cos(radian);
    temp.y = p->len * sin(radian);

    return temp;
}