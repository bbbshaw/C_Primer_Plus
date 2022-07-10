#include <stdio.h>

char getchoice(void);
double sum(double x, double y);
double sub(double x, double y);

int main(void)
{
    double (*func[2])(double, double) = {sum, sub};

    double x, y;
    char ch;

    puts("Enter two number:");
    scanf("%lf %lf", &x, &y);
    while (getchar() != '\n')
        continue;

    while((ch = getchoice()) != '\n')
    {
        switch (ch)
        {
        case 'a':
            printf("%lf\n", func[0](x, y));
            break;

        case 'b':
            printf("%lf\n", func[1](x, y));
            break;
        }
    }
    puts("Done.");
}

char getchoice(void)
{
    char ch;

    puts("a) sum");
    puts("b) sub");
    ch = getchar();

    while (getchar() != '\n')
        continue;

    return ch;
}

double sum(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}