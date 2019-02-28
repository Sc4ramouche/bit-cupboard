#include <stdio.h>

#define IN 1
#define OUT 0

/* analog of wc UNIX utilite that also prints every word on new line */
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        ++nc;
        if (c == '\n')
            ++nl;

        if (c == ' ')
            putchar('\n');

        if (c == '\n' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}