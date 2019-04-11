# Week 4 shorts | Tries

Tries combine structures and pointers together to store data. The data to be searched for in the trie in a roadmap. If you can follow the map from beginning to end, the data exists in the trie. If you can't, it doesn't.

Unlike with a hash table, there are no collisions, and no two pieces of data (unless they are identical) have the same path.

```C
typedef struct _trie
{
    char university[20];
    struct _trie* paths[10];
}
trie;
```

Tries are really huge in terms of memory, but they allow us to achieve constant time insertion, deletion and lookup.

# Stacks

A stack is a special type of structure that can be used to maintain data in an organized way. It's commonly implemented in one of two ways: a an *array* or as a *linked list*. Last In, First out.

We can **push**: add a new element to the top of the stack. We can **pop**: remove the most recently-added element from the top of the stack.

## Array-based Stack implementation

```C
typedef struct _stack
{
    VALUE array[CAPACITY];
    int top;
}
stack;
```

Note that our stack is limited by `CAPACITY`, as usual when working with arrays in C. We can keep track of last item placed in the stack via `top` property.

In general case, `push()` needs to:

* Accept a pointer to the stack
* Accept data of type `VALUE` to be added to the stack
* Add that data to the stack at the top of the stack
* Change the location of the top of the stack

In general case, `pop()` needs to:

* Accept a pointer to the stack
* Change the location of the top of the stack
* Return the value that was removed from the stack

## Linked-List-based Stack implementation

```C
typedef struct _stack
{
    VALUE val;
    struct _stack *next;
}
stack;
```

To *push*, we have to dynamically allocate a new node, et its next pointer to point to the current head of the list, then move the head pointer to the newly-created node.

To *pop*, we have to traverse the linked list to its second element (if it exists), free the head of the list, then move the head pointer to the (former) second element.

### Note about pointers passed to functions

What I've discovered during implementation of stack data structure via linked list is that when you pass a pointer to the function, you actually pass a **copy of the original pointer** value. So if you want to change original pointer, you probably need to return changed pointer from the function. Another approach could be passing a *pointer-to-pointer* as a parameter.
