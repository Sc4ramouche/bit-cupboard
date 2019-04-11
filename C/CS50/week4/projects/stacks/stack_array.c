#define CAPACITY 100
#include <stdio.h>

#include "stack_array.h"

void push(stack_array* stack, int value)
{
    // check if we can still push to the stack
    if (stack->top + 1 > CAPACITY - 1)
    {
        printf("Unable to push new items to stack\n");
        return;
    }

    stack->array[stack->top] = value; 
    stack->top++;
}

int pop(stack_array* stack)
{
    // check if stack is not yet empty
    if (stack->top == 0)
    {
        printf("Stack is already empty\n");
        return -1;
    }

    stack->top--;
    return stack->array[stack->top];
}
