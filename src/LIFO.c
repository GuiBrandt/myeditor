#include <stdlib.h>

#include "LIFO.h"

typedef struct _LIFO_node {
    struct _LIFO_node* prev;
    char value;
} _stack_node;

typedef struct _LIFO {
    _stack_node* head;
    _stack_node* tail;
} stack;

stack_t new_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->head = 0;
    s->tail = 0;
    return s;
}

void free_stack(stack_t s) {
    empty((stack*)s);
    free(s);
}

void push(stack_t s_, char c) {
    stack* s = (stack*)s_;
    _stack_node *node = (_stack_node*)malloc(sizeof(_stack_node));
    node->value = c;
    node->prev = s->tail;
    if (!s->head)
        s->head = node;
    s->tail = node;
}

char pop(stack_t s_) {
    stack* s = (stack*)s_;
    _stack_node *node = s->tail;
    if (!node)
        return (char)-1;
    char c = node->value;
    if (s->head == node)
        s->head = 0;
    s->tail = node->prev;
    free(node);
    return c;
}

char peek(const stack_t s_) {
    stack* s = (stack*)s_;
    if (s->tail)
        return s->tail->value;
    return (char)-1;
}

char is_empty(const stack_t s_) {
    stack* s = (stack*)s_;
    return s->head == 0;
}

void empty(stack_t s_) {
    stack* s = (stack*)s_;
    _stack_node *node = s->tail, *prev;
    while (node) {
        prev = node->prev;
        free(node);
        node = prev;
    }
    s->head = 0;
    s->tail = 0;
}
