#include <stdbool.h>

// this is known as "include guard"
// read more: https://en.wikipedia.org/wiki/Include_guard
#ifndef H_SLLIST
#define HSLLIST
typedef struct sllist
{
    int value;
    struct sllist* next;
}
sllnode;
#endif

sllnode* create(int val);
sllnode* insert(sllnode* head, int val);
bool find(sllnode* head, int val);
void destroy(sllnode* head);
