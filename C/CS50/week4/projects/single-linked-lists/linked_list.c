#include <stdio.h>
#include <stdlib.h>

#include "sllist.h"

/*
 * This program was split into several
 * C files for convenience sake.
 *
 * In order to compile and link you have to execute:
 * gcc linked_list.c sllist.c -o linked list
 */

int main(int argc, char** argv)
{
    /* CREATE */
    sllnode* head = create(5);
    
    if (!head)
    {
        printf("Unable to initialize linked list");
        return 1;
    }

    printf("Did I successfully create first element in linked list? %i\n", head->value);

    /* INSERT */
    head = insert(head, 6);
    head = insert(head, 7);

    /* SEARCH */
    bool found_true = find(head, 5);
    bool found_false = find(head, 14);

    printf("Did I find what's I've looked for? %i\n", found_true);
    printf("Is there 14 yet? %i\n", found_false);

    /* DESTROY */
    destroy(head);
    return 0;
}


