#include <stdio.h>

int convert_to_celsius(float fahr);

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   // lower limit of temperature table
    upper = 300; // upper limit
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int convert_to_celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}