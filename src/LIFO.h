#ifndef __LIFO_H__
#define __LIFO_H__

typedef void* stack_t;

stack_t new_stack();
void free_stack(stack_t);

void push(stack_t, char);
char pop(stack_t);
void empty(stack_t);

char peek(const stack_t);
char is_empty(const stack_t);

#endif // __LIFO_H__