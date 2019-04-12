#include <stdio.h>

#include "queue_a.h"
#include "queue_ll.h"

void run_queue_array();
void run_queue_linked_list();

queue_ll* head = NULL;
queue_ll* tail = NULL;

int main(int argc, char** argv)
{
    run_queue_array();
    run_queue_linked_list();

    return 0;
}

void run_queue_array()
{
    queue_a q;
    q.size = 0;
    q.front = 0;
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("Dequeued value: %i\n", dequeue(&q));
    printf("Dequeued value: %i\n", dequeue(&q));
    printf("Dequeued value: %i\n", dequeue(&q));

    // Test wrappings
    for (int i = 0; i < 15; i++)
        enqueue(&q, i);

    printf("--------\n");

    // check queue contents
    for (int i = 0; i < 10; i++)
        printf("queue value: %i\n", q.array[i]);

    printf("--------\n");

    for (int i = 0; i < 15; i++)
        printf("dequeue: %i\n", dequeue(&q));
    
}

void run_queue_linked_list()
{   
    // populate queue
    enqueue_ll(10);
    printf("enqueue value: %i\n", tail->value);

    enqueue_ll(20);
    printf("enqueue value: %i\n", tail->value);

    // empty queue
    printf("dequeue value: %i\n", dequeue_ll());
    printf("dequeue value: %i\n", dequeue_ll());
    printf("dequeue value: %i\n", dequeue_ll());

    // add something again to ensure it's fine
    enqueue_ll(5);
    enqueue_ll(15);

    printf("dequeue value: %i\n", dequeue_ll());
    printf("dequeue value: %i\n", dequeue_ll());
}
