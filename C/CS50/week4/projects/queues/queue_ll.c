#include <stdio.h>
#include <stdlib.h>

#include "queue_ll.h"

extern queue_ll* head;    // keep track of the queue's head
extern queue_ll* tail;    // keep track of the queue's tail

void enqueue_ll(int val)
{
    queue_ll* node = malloc(sizeof(queue_ll));

    if (node == NULL)
    {
        printf("Unable to allocate space\n");
        return;
    }

    node->value = val;
    
    node->next = NULL;
    node->prev = tail;

    // if it's first node in the queue
    if (head == NULL)
        head = node;

    // if it's not first node in the queue
    if (tail != NULL)
        tail->next = node;
    
    // move tail to the newly added node
    tail = node;
}

int dequeue_ll()
{
    queue_ll* trav = head;
    
    if (head == NULL)
    {
        printf("Queue if empty already\n");
        return -1;
    }
    
    // capture front queue value
    int val = trav->value;

    // if it's not the last node in the queue
    if (head->next != NULL)
    {
        // move the head
        head = head->next;
        // cut the previous node
        head->prev = NULL;
    }
    else 
        head = NULL;

    // free previous node
    free(trav);

    return val;
}
