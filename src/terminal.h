/*
Communicates with the OS/terminal

Query terminal dimensions
Enter raw input mode (TBD)
Manipulate cursor using ANSI
Write completed frame to stdout
Restore settings on exit (TBD)
*/

#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>
#include <stddef.h>



// basic utils
void clear_screen(void);
void hide_cursor(void);
void show_cursor(void);
void sleep_ms(long ms);
static int write_all(int fd, const char* buff, size_t length);



// Data
typedef struct {
    int width;
    int height;
    struct termios original_settings;
    int initialized;
} Terminal;



// Terminal "member functions"
int terminal_init(Terminal* terminal);
void terminal_restore(Terminal* terminal);
int terminal_update_size(Terminal* terminal);
int terminal_present(const char* buff, size_t length);

#endif