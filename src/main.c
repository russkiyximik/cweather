#include <stdio.h>



/* Function Definitions*/


void clear_screen(void) {
    printf("\x1B[2J"); // clears screen
    printf("\x1B[H"); // moves cursor to top-left
    fflush(stdout);
}

/*
todo

hide_cursor
show_cursor
sleep_ms
draw_frame
main
*/