#define CAPACITY 100

typedef struct _stack_array
{
    int array[CAPACITY];
    int top;
}
stack_array;

void push(stack_array* stack, int value);
int pop(stack_array* stack);

// we can create array based stack
// by usual variable declaration,
// so there's no need to explicitly state
// `create_stack` function for that.
// see `stacks.c` file for details.
