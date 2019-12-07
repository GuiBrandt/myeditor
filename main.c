#include <curses.h>
#include <locale.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

#include "LIFO.h"

void setup();
void cleanup();

void set_status(const char* fmt, ...);

stack* undone;

void myeditor_write(char c) {
    echochar(c);
    empty(undone);
}

void myeditor_undo() {
    int y, x;
    getyx(stdscr, y, x);

    char c;
    if (x > 0) {
        c = mvinch(y, x - 1) & A_CHARTEXT;
        set_status("UNDOING %d (%c)", c, c);
        
        push(undone, c);
        mvdelch(y, x - 1);
    } else {
        set_status("NOTHING TO UNDO", c, c);
        beep();
    }
}

void myeditor_redo() {
    char c = pop(undone);
    if (c != -1) {
        set_status("REDOING %d (%c)", c, c);
        echochar(c);
    } else {
        set_status("NOTHING TO REDO", c, c);
        beep();
    }
}

int main(int argc, char** argv) {
    setup();

    while (1) {
        char c = getch();
        set_status("");
        if (isgraph(c) || c == '\t' || c == ' ')
            myeditor_write(c);
        else if (c == KEY_BACKSPACE || c == 127)
            myeditor_undo();
        else if (c == KEY_ENTER || c == '\n')
            myeditor_redo();
        else
            set_status("UNSUPPORTED KEY %d", c);
    }

    cleanup();
    return 0;
}

void setup() {
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    idcok(stdscr, FALSE);
    define_key("DEL", 127);

    undone = new_stack();
}

void cleanup() {
    free_stack(undone);
}

void set_status(const char* fmt, ...) {
    int y, x;
    getyx(stdscr, y, x);

    char str[128];

    va_list args;
    va_start(args, fmt);

    int n = vsprintf(str, fmt, args);
    str[n] = '\n';
    str[n + 1] = 0;

    va_end(args);

    mvaddstr(10, 0, str);
    move(y, x);
}
