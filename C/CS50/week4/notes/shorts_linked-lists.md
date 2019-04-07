# Week 4 shorts | Singly Linked Lists

## Singly-Linked Lists

Working with arrays could be quite costly. There's another issue – inflexibility. If you decide at some point to expand existing array your only option is to declare array of bigger size and copy all the contents.

Linked lists **node** is a special kind of struct with two members: data of some data type and a *pointer* to another node of the same type.

An example of how `struct` for singly-linked list could look like:

```C
typedef struct sllist
{
    VALUE val;
    struct sllist* next;
}
sllnode;
```

Note that we have to use name `sllist` list inside of `struct` declaration, as we didn't yet declare name `sllnode`. That's the caveat when working with self-referential struct declaration.

### Create Singly-Linked List

If we want to create a linked list, we can declare a function `create`, which should accept `value` of some type as an argument and return a pointer to the first node in the linked list. This function should:

1. Dynamically allocate space for a new `sllnode`.
2. Check to make sure we didn't run out of memory.
3. Initialize the node's `val` field.
4. Initialize the node's `next` field.
5. Return a pointer to the newly create `sllnode`.

### Find in Singly-Linked List

Function declaration for finding out if some value is present in the linked list could look something like this:

```C
bool find(sllnode* head, VALUE val);
```

Steps involved:

1. Create a traversal pointer pointing to the list's head (so we always have a record of the start of the list, which we don't change).
2. If the current node's `val` field is what we're looking for, report success.
3. If not, set the traversal pointer to the next pointer in the list and go back to step b.
4. If reached the end of the list, report failure.

### Insert a new node into the Linked Lists

```C
sllnode* insert(sllnode* head, VALUE val);
```

Steps involved:

1. Dynamically allocate space for a new `sllnode`.
2. Check to make sure we didn't run out of memory.
3. Populate and insert the node **at the beginning of the list**.
4. Return a pointer to the new head of the linked list.

Note that the reason for inserting the element into the beginning of the list is that you don't have to traverse whole list, but you can insert new element immediately. Thus we have to return new head.

There is important detail. You have to change pointer in this case. Order matters! If you don't want to accidentally drop the list, you should make new node point to the list in first place, and then change list starting location.

### Delete an entire linked list

```C
void destroy(sllnode* head);
```

Steps involved:

1. If you've reached a null pointer, stop.
2. Detele the rest of the list.
3. Free the current node.

Note that this is like recursive approach.

### Delete a single element from a linked list

That's a tricky one! Singly linked lists don't provide us a way to go backwards. So we need to either keep two pointers, and move them in an off step way, one behind the other as we go, but this problem could be solved with **Doubly Linked Lists**.
