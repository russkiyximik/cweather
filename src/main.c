#include <stdio.h>
#include <time.h>



/* Function Definitions*/


void clear_screen() {
    printf("\x1B[2J"); // clears screen
    printf("\x1B[H"); // moves cursor to top-left
    fflush(stdout);
}

void hide_cursor() {
    printf("\x1B[?25l");
}

void show_cursor() {
    printf("\x1B[?25h");
}

void sleep_ms(long ms) {
    // puts calling thread to sleep for ms
    struct timespec sleep_time;
    sleep_time.tv_sec = ms / 1000;
    sleep_time.tv_nsec = (ms % 1000) * (long)(1e6);
    
    (void)nanosleep(&sleep_time, NULL);
}

void draw_frame(int frame) {
    printf("cweather\t");
    printf("Frame: %d\n", frame);
    printf("Made by russkiyximik\n");

    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            putchar(' '); // adds a col
            if ( (i+j+frame) % 5 == 0 ) {
                putchar('/');
            }
        }
        putchar('\n'); // adds a row
    }
    printf("Done!\n");
}

/*
todo

draw_frame (exceedingly simple)
*/


int main(void) {
    clear_screen();
    hide_cursor();

    for ( int frame = 0; frame < 10; frame++ ) {
        draw_frame(frame);
        sleep_ms(500);
        clear_screen();
    }

    show_cursor();

    return 0;
}
