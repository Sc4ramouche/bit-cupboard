#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sllist.h"

/*
 *  Function which initializes linked list
 *  with given value.
 *  Return pointer to the first node of the list.
 */
sllnode* create(int val)
{
   sllnode* head = malloc(sizeof(sllnode)); 

   if (!head)
   {
       printf("Unable to allocate space\n");
       return NULL;
   }

   head->value = val;
   head->next = NULL;
   
   return head;
}

/*
 * Indicates if specified value is
 * contained in the list
 */
bool find(sllnode* head, int val)
{
    /* 
     * declare traversal pointer
     * as it could be important to know
     * where is the actual start of the list
     */
    sllnode* trav = head;
    
    while(trav != NULL)
    {
        if (trav->value == val)
            return true;

        // move traversal pointer to the next node
        trav = trav->next;
    }
    
    return false;
}

/*
 * Inserts new node to the start of the list
 */
sllnode* insert(sllnode* head, int val)
{
    sllnode* new_head = malloc(sizeof(sllnode));
    
    if (!new_head)
    {
       printf("Unable to allocate space\n");
       return NULL;
    }

    new_head->next = head;
    new_head->value = val;

    return new_head;
}

/*
 * Frees every node's memory
 */
void destroy(sllnode* head)
{
    if (head == NULL)
        return;
    
    destroy(head->next);
    free(head);
}
