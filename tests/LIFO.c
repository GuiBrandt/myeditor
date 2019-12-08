#include <stdio.h>
#include "../LIFO.h"

stack* s;

void test_lifo() {
    s = new_stack();

    push(s, 'A');
    push(s, 'B');
    push(s, 'C');

    char c = pop(s);
    if (c == 'C')
        printf("ok - last in, first out");
    else if (c == (char)-1)
        printf("not ok - empty stack");
    else
        printf("not ok - last in was not first out");
    printf("\n");

    free_stack(s);
}

void test_pop_removes() {
    s = new_stack();

    push(s, 'A');
    push(s, 'B');
    push(s, 'C');

    char c = pop(s);
    char d = pop(s);

    if (c == (char)-1 || d == (char)-1)
        printf("not ok - empty stack");
    else if (c == d)
        printf("not ok - pop does not remove from stack");
    else
        printf("ok - pop removes from stack");
    printf("\n");

    free_stack(s);
}

void test_peek_does_not_remove() {
    s = new_stack();

    push(s, 'A');

    char c = peek(s);
    char d = peek(s);

    if (c == (char)-1 || d == (char)-1)
        printf("not ok - empty stack");
    else if (c == d)
        printf("ok - peek does not remove from stack");
    else
        printf("not ok - peek removes from stack");
    printf("\n");

    free_stack(s);
}

void test_pop_order() {
    s = new_stack();

    push(s, 'A');
    push(s, 'B');
    push(s, 'C');

    char c = pop(s);
    char d = pop(s);

    if (c == (char)-1 || d == (char)-1)
        printf("not ok - empty stack");
    else if (c == 'C' && d == 'B')
        printf("ok - pop follows expected order");
    else
        printf("not ok - pop order is weird");
    printf("\n");

    free_stack(s);
}

void test_empty_cleans_stack() {
    s = new_stack();

    push(s, 'A');
    push(s, 'B');
    push(s, 'C');
    empty(s);

    char c = peek(s);

    if (c == (char)-1)
        printf("ok - empty cleans stack");
    else
        printf("not ok - empty does not clean stack");
    printf("\n");

    free_stack(s);
}

int main(int argc, char** argv) {
    printf("1..5\n");
    test_lifo();
    test_pop_removes();
    test_peek_does_not_remove();
    test_pop_order();
    test_empty_cleans_stack();
    return 0;
}