#include <stdio.h>

/* horizontal histogram of words length */
int main()
{
    int c, newlines, current_length;
    int lengths[10];

    newlines = current_length = 0;
    for (int i = 0; i < 10; i++)
        lengths[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            newlines++;

        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++lengths[current_length - 1];
            current_length = 0;
        }
        else
        {
            current_length++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%2d: ", i + 1);
        for (int j = 0; j < lengths[i]; j++)
            printf("•");
        printf("\n");
    }

    printf("\n");
}