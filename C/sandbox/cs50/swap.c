#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);

int main(void)
{
    int x = 1, y = 2;

    printf("x: %i, y: %i\n", x, y);
    swap(&x, &y);
    printf("x: %i, y: %i\n", x, y);
}

void swap (int *a, int *b)
{
    // print the memory location
    printf("%p, %p\n", a, b);

    int temp = *a;
    *a = *b;
    *b = temp;
}
