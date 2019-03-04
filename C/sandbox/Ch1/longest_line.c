#include <stdio.h>
#define MAXLINE 1000       // maximum input line size

int get_line(char string[], int limit);
void copy(char to[], char from[]);

int main()
{
    int len;               // current line length
    int max;               // maximum length seen so far
    char line[MAXLINE];    // current input line
    char longest[MAXLINE]; // longest line

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

int get_line(char string[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    if (c == '\n')
    {
        string[i] = c;
        ++i;
    }

    string[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}