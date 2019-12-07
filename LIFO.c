#include <stdlib.h>

#include "LIFO.h"

stack* new_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->head = 0;
    s->tail = 0;
    return s;
}

void free_stack(stack* s) {
    empty(s);
    free(s);
}

void push(stack* s, char c) {
    _stack_node *node = (_stack_node*)malloc(sizeof(_stack_node));
    node->value = c;
    node->prev = s->tail;
    if (!s->head)
        s->head = node;
    s->tail = node;
}

char pop(stack* s) {
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

char peek(const stack* s) {
    if (s->tail)
        return s->tail->value;
    return (char)-1;
}

char is_empty(const stack* s) {
    return s->head == 0;
}

void empty(stack* s) {
    _stack_node *node = s->tail, *prev;
    while (node) {
        prev = node->prev;
        free(node);
        node = prev;
    }
    s->head = 0;
    s->tail = 0;
}
