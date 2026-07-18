#include <terminal.h>
#include <renderer.h>
#include <weather.h>
#include <stdio.h>



#define SCENE_WIDTH 100
#define SCENE_HEIGHT 20
#define FRAME_COUNT 150
#define FRAME_DELAY_MS 100



int main(void) {
    Terminal terminal;
    Renderer renderer;

    terminal_init(&terminal);
    renderer_init(&renderer, terminal.width, terminal.height);

    for ( int frame = 0; frame < 200; frame++ ) {
        renderer_clear(&renderer);

        renderer_write(&renderer,
            frame % renderer.width,
            renderer.height / 2,
            '@'
        );

        terminal_present(renderer_buffer(&renderer), renderer_length(&renderer));
    
        sleep_ms(50);
    }

    renderer_destroy(&renderer);
    terminal_restore(&terminal);

    return 0;
}
