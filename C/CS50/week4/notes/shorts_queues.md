# Week 4 shorts | Queues

A queue is a special type of structure that is commonly implemented in one of two ways: as an **array** or **linked list**. It's an *FIFO* (first in, first out) data structure.

There are two legal operations:

* **Enque** – add a new element to the end of the queue
* **Dequeue** - Remove the oldest element from the front of the queue

## Array-based Queue Implementation

```C
typedef struct _queue
{
    VALUE array[CAPACITY];
    int front;
    int size;
}
queue;
```

In general case, `enqueue()` needs to:

* Accept a pointer to the queue
* Accept data of type `VALUE` to be added to the queue
* Add that data to the queue at the end of the queue
* Change the size of the queue

In general case, `dequeue()` needs to:

* Accept a pointer to the queue
* Change the location of the front of the queue
* Decrease the size of the queue
* Return the value that was removed from the queue

Note that when implement queue in such a way you'd probably hit the border of the queue. In this case, smart move would be to wrap around the queue using modulo operator. See it's in use in `queue_a.c` file.

## Linked List-based Queue Implementation

```C
typedef struct _queue
{
    VALUE val;
    struct _queue *prev;
    struct _queue *next;
}
queue;
```

In general, it's just a *doubly linked list*. 

Note: make sure to always maintain pointers to the head and tail of the linked list! (probably global)

To enqueue:

* Dynamically allocate a new node
* Set its next pointer to NULL, set its prev pointer to the tail
* Set the tail's next pointer to the new node
* Move the tail pointer to the newly-created node

To dequeue:

* Traverse the linked list to its second element (if it exists)
* Free the head of the list
* Move the head pointer to the (former) second element
* Make that node's prev pointer point to `NULL`

Note: this time, unlike for stack, I've decided to keep `head` and `tail` in a global variable. This removes the need to explicitly pass the pointers here and there.
