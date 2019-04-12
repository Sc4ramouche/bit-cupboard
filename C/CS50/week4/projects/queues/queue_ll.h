/*
 * Linked list-based queue implementation
 */
typedef struct _queue_ll
{
    int value;
    struct _queue_ll* prev;
    struct _queue_ll* next;
}
queue_ll;

void enqueue_ll(int val);
int dequeue_ll();
