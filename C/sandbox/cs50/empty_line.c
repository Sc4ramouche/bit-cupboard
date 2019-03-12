#include <stdio.h>

/* 
 *  program to understand what it means
 *  for input line to be 'empty'
 */
int main()
{
    int c;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            printf("%s", "\\n");
        else {
            putchar(c);
        }
    }

    printf("\n");
}
