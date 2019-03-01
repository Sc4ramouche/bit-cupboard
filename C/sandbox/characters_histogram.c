#include <stdio.h>

#define ALPHABET_LENGTH 26
#define ASCII_OFFSET 97

/* 
    build horizontal histogram 
    for characters frequencies
*/
int main()
{
    int c;
    int characters[26];

    for (int i = 0; i < 26; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
            ++characters[c - 'a'];

        if (c >= 'A' && c <= 'Z')
            ++characters[c - 'A'];
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c: ", i + 97);
        for (int j = 0; j < characters[i]; j++)
            printf("•");

        printf("\n");
    }
}