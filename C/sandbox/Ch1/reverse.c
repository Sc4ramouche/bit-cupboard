#include <stdio.h>
#define MAXLINE 1000

int read_line(char string[]);
int get_length(char string[]);
void reverse(char source[], char reversed[], int length);

int main()
{
	int len;
	char current_line[MAXLINE];
	char reversed_line[MAXLINE];

	while((len = read_line(current_line)) > 0)
	{
		reverse(current_line, reversed_line, len);
		printf("reversed: %s\n", reversed_line);
	}
}

int read_line(char string[])
{
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		string[i] = c;
	if (c == '\n')
	{
		string[i] = c;
		++i;
	}

	string[i] = '\0';
	return i;
}

int get_length(char string[])
{
	int i = 0;

	while(string[i] != '\0')
		i++;

	return i;
}

void reverse(char source[], char reversed[], int length)
{
	for (int i = length - 1, j = 0; i >= 0; --i, ++j)
	{
		reversed[j] = source[i];
	}
	reversed[length] = '\0';
}