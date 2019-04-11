#include <stdio.h>
#include <stdlib.h>

#include "stack_linked_list.h"

stack_linked_list* push_ll(stack_linked_list* stack, int value)
{
    stack_linked_list* node = malloc(sizeof(stack_linked_list));
    if (!node)
    {
        printf("Unable to allocate space\n");
        return NULL;
    }

    node->value = value;
    node->next = stack;

    return node;
}

stack_linked_list* pop_ll(stack_linked_list* stack)
{
    stack_linked_list* trav;

    if (stack == NULL)
    {
        printf("Stack is empty already\n");
        return NULL; 
    }

    trav = stack;
    stack = stack->next;
    trav->next = NULL;
    free(trav);
    return stack;
}

int is_empty(stack_linked_list* stack)
{
    return stack == NULL;
}

int get_top_value(stack_linked_list* stack)
{
    if (!is_empty(stack))
        return stack->value;
    else
        return -1;
}
