#include <terminal.h>
#include <stdio.h>
#include <time.h>




/* Function Definitions*/


void clear_screen(void) {
    printf("\x1B[2J"); // clears screen
    printf("\x1B[H"); // moves cursor to top-left
    fflush(stdout);
}

void hide_cursor(void) {
    printf("\x1B[?25l");
}

void show_cursor(void) {
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
    printf("Condition: rain\n");
    
    for ( int i = 0; i < SCENE_HEIGHT; i++ ) {
        for ( int j = 0; j < SCENE_WIDTH; j++ ) {
            if ( (i * 3 + j + frame) % 17 == 0 ) {
                putchar('/');
            }
            else putchar(' ');
        }
        putchar('\n'); // adds a row
    }
    for ( int j = 0; j < SCENE_WIDTH; j++ ) {
        // print a simple ground
        putchar('^');
    }

    putchar('\n');
    printf("Made by russkiyximik");
}



/* Fake Weather (temporary obv) */


WeatherData weather = {
    .condition=WEATHER_RAINY,
    .temp=18.,
    .wind_speed=12.,
    .precipitation=.8
};
