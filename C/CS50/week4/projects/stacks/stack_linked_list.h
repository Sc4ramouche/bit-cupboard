typedef struct _stack_linked_list
{
    int value;
    struct _stack_linked_list* next;
}
stack_linked_list;

stack_linked_list* push_ll(stack_linked_list* stack, int value);
stack_linked_list* pop_ll(stack_linked_list* stack);
int is_empty(stack_linked_list* stack);
int get_top_value(stack_linked_list* stack);
