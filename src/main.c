#include <terminal.h>
#include <weather.h>
#include <stdio.h>



#define SCENE_WIDTH 100
#define SCENE_HEIGHT 20
#define FRAME_COUNT 150
#define FRAME_DELAY_MS 100



int main(void) {
    clear_screen();
    hide_cursor();

    for ( int frame = 0; frame < FRAME_COUNT; frame++ ) {
        clear_screen();
        // draw_frame(condition, frame);
        fflush(stdout);
        sleep_ms(FRAME_DELAY_MS);
    }

    show_cursor();

    return 0;
}
