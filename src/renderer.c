#include <renderer.h>
#include <stdio.h>
#include <time.h>



// Todo: definitely clean this up
// i.e. reimplement this whole file
#define SCENE_WIDTH 100
#define SCENE_HEIGHT 20
#define FRAME_COUNT 150
#define FRAME_DELAY_MS 100


/* Function Definitions*/


void draw_frame(WeatherCondition Weather, int frame) {
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
