#include <stdio.h>

#include "queue_a.h"

#define CAPACITY 10

void enqueue(queue_a* q, int value)
{   
    if (q->size == CAPACITY)
    {
        printf("Queue is already full\n");
        return;
    }
    
    q->array[(q->front + q->size) % CAPACITY] = value;
    q->size++;
}

int dequeue(queue_a* q)
{
    if (q->size == 0)
    {
        printf("Queue is already empty\n");
        return -1;
    }
    
    // capture value to be returned
    int value = q->array[q->front];

    q->front = (q->front + 1) % CAPACITY;
    q->size--;

    return value;
}
