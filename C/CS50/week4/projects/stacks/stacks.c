#include <stdio.h>

#include "stack_array.h"
#include "stack_linked_list.h"

void run_array_stack();
void run_linked_list_stack();

/*
 * In order to compile and link you have to execute:
 * gcc -o stacks_2 stack_array.c stacks.c stack_linked_list.c
 */
int main(int argc, char** argv)
{
    run_array_stack();
    run_linked_list_stack();

    return 0;
}

void run_array_stack()
{
    stack_array stack;    
    stack.top = 0;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("stack value popped: %i\n", pop(&stack));
    printf("stack value popped: %i\n", pop(&stack));
    printf("stack value popped: %i\n", pop(&stack));
}

void run_linked_list_stack()
{
    stack_linked_list* stack = push_ll(NULL, 2);
    stack = push_ll(stack, 4);
    stack = push_ll(stack, 6);

    printf("value %i was placed\n", stack->value);
    printf("value %i was placed\n", stack->next->value);
    printf("value %i was placed\n", stack->next->next->value);

    printf("stack value popped: %i\n", get_top_value(stack));
    stack = pop_ll(stack);
    printf("stack value popped: %i\n", get_top_value(stack));
    stack = pop_ll(stack);
    printf("stack value popped: %i\n", get_top_value(stack));
    stack = pop_ll(stack);

    // make sure you're not able to pop from empty stack
    stack = pop_ll(stack);

    if (stack == NULL)
        printf("We are fine there.\n");
}
