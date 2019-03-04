#include <stdio.h>

main()
{
    int c, newline = 0, tab = 0, blank = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++newline;

        if (c == '\t')
            ++tab;

        if (c == ' ')
            ++blank;
    }

    printf("newlines: %i\n", newline);
    printf("tabs: %i\n", tab);
    printf("blanks: %i\n", blank);
}