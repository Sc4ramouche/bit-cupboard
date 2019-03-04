#include <stdio.h>

main()
{
    long count;

    count = 0;
    while (getchar() != EOF)
        ++count;
    printf("%ld\n", count);
}