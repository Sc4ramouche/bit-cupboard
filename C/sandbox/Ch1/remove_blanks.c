#include <stdio.h>
#define NON_BLANK '-'

main()
{
    int c, lastc;

    lastc = NON_BLANK;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (lastc != ' ')
                putchar(c);
        }
        else
        {
            putchar(c);
        }

        lastc = c;
    }
}