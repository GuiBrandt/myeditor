#ifndef __LIFO_H__
#define __LIFO_H__

typedef struct _LIFO_node {
    struct _LIFO_node* prev;
    char value;
} _stack_node;

typedef struct _LIFO {
    _stack_node* head;
    _stack_node* tail;
} stack;

stack* new_stack();
void free_stack(stack*);

void push(stack*, char);
char pop(stack*);
void empty(stack*);

char peek(const stack*);
char is_empty(const stack*);

#endif // __LIFO_H__