#include <stdio.h>

void input(double (*arr)[5], int n);
void show_arr(double (*arr)[5], int n);
void cal_ave(double (*arr)[5], int n);
void cal_total(double (*arr)[5], int n);
void find_max(double (*arr)[5], int n);


int main(void)
{
    double arr1[3][5];

    input(arr1, 3);
    show_arr(arr1, 3);
    cal_ave(arr1, 3);
    cal_total(arr1, 3);
    find_max(arr1, 3);

    return 0;
}

void input(double (*arr)[5], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Plz ente the %d array:\n", i+1);
        for (int j = 0; j < 5; j++)
            scanf("%lf", &arr[i][j]);  
    }  
}

void show_arr(double (*arr)[5], int n)
{
    printf("\nThe array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%5.2lf ", arr[i][j]);
    printf("\n");
    }
}

void cal_ave(double (*arr)[5], int n)
{
    double subtotal = 0;
    double line_ave;

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            subtotal += arr[i][j];        
        }
    line_ave = subtotal / 5;
    printf("The %d line average:%.2lf\n", i + 1, line_ave);
    line_ave = 0;
    subtotal = 0;
    }
}

void cal_total(double (*arr)[5], int n)
{
    double total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            total += arr[i][j];
    }
    printf("\nThe total: %.2lf\n",total);
}

void find_max(double (*arr)[5], int n)
{
    double max = arr[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }
    printf("\nThe max value: %.2lf\n", max);
}