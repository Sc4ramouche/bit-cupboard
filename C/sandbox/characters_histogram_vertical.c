#include <stdio.h>

#define ALPHABET_LENGTH 26
#define ASCII_OFFSET 97

/* 
    build vertical histogram 
    for characters frequencies

    thoughts for future:
    extract frequencies calculation to separate function
    extract print logic to separate function
*/
int main()
{
    int c;
    int characters[ALPHABET_LENGTH];

    for (int i = 0; i < ALPHABET_LENGTH; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        // lowercase and uppercase handled separately
        // but end up incrementing same value
        // due to subtracting ASCII value
        if (c >= 'a' && c <= 'z')
            ++characters[c - 'a'];

        if (c >= 'A' && c <= 'Z')
            ++characters[c - 'A'];
    }

    // find max value for vertical histogram
    int max = 0;
    for (int i = 0; i < ALPHABET_LENGTH; i++)
        if (characters[i] > max)
            max = characters[i];

    // print vertical part of histogram
    for (int i = max, step = 0; i >= 0; i--, step++)
    {
        for (int j = 0; j < ALPHABET_LENGTH; j++)
        {
            if ((max - step) < characters[j])
                printf("• ");
            else
                printf("  ");
        }

        printf("\n");
    }

    // print table-like footer
    for (int i = 0; i < ALPHABET_LENGTH; i++)
        printf("– ");

    printf("\n");

    for (int i = 0; i < ALPHABET_LENGTH; i++)
        printf("%c ", i + ASCII_OFFSET);

    printf("\n");
}