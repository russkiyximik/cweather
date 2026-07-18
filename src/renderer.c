#include <renderer.h>
#include <stdio.h>
#include <time.h>


/*
todo

renderer_clear
renderer_destroy
renderer_write
renderer_buffer
renderer_length
*/


/* Function Definitions*/

int renderer_init(Renderer* renderer, int term_w, int term_h) {
    if (!renderer || term_h<1 || term_w<1) return -1;

    renderer->width = term_w - 1; // leave room for '\n'
    renderer->height = term_h - 1;
    renderer->stride = term_w;
    renderer->length = renderer->stride * (size_t)renderer->height - 1;
    // byte for (x, y) is renderer->stride * y + x

    renderer->buffer = malloc(renderer->length);
    if (!renderer->buffer) return -1;

    renderer_clear(renderer);
    return 0;
}

void renderer_destroy(Renderer* renderer) {
    free(renderer); // ?
}


void renderer_clear(Renderer* renderer) {
    for ( int row = 0; row < renderer->height; row++ ) {
        // offset is row * renderer->stride
        // leave spaces for \n
        memset(renderer->buffer + renderer->stride * row, 
            0, renderer->width); // should i set it to blank space ' ' instead?
    }
}

int renderer_write(Renderer* renderer, int x, int y, char symbol) {
    // ensure (x, y) within bounds
    if (y > renderer->height || x > renderer->width) return -1;

    memset(renderer->buffer + renderer->stride * y + x, symbol, 1);
    return 0;
}


const char* renderer_buffer(const Renderer* renderer) {return renderer->buffer;}
const size_t renderer_length(const Renderer* renderer) {return renderer->length;}





// Random stuff (tbd whether needed or not)
// void draw_frame(WeatherCondition Weather, int frame) {
//     printf("cweather\t");
//     printf("Frame: %d\n", frame);
//     printf("Condition: rain\n");
    
//     for ( int i = 0; i < SCENE_HEIGHT; i++ ) {
//         for ( int j = 0; j < SCENE_WIDTH; j++ ) {
//             if ( (i * 3 + j + frame) % 17 == 0 ) {
//                 putchar('/');
//             }
//             else putchar(' ');
//         }
//         putchar('\n'); // adds a row
//     }
//     for ( int j = 0; j < SCENE_WIDTH; j++ ) {
//         // print a simple ground
//         putchar('^');
//     }

//     putchar('\n');
//     printf("Made by russkiyximik");
// }
