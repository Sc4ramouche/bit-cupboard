/*
 * Array-based queue implementation
 */

#define CAPACITY 10

typedef struct _queue_a
{
    int array[CAPACITY];
    int front;
    int size;
}
queue_a;

void enqueue(queue_a* q, int value);
int dequeue(queue_a* q);
