#include <stdio.h>

/* copy input to output – more brief version */
main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}