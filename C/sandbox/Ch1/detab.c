#include <stdio.h>
#define TAB_LENGTH 5

/*
 * replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop
 */
int main(void)
{
    int c;

    while((c = getchar()) != EOF)
    {
        if (c == '\t')
            for (int i = 0; i < TAB_LENGTH; i++)
                putchar(' ');
        else
            putchar(c);
    }
}
