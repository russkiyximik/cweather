#include <terminal.h>

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>



// Terminal Utils
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
    // in C++, use std::chrono::steady_clock
    struct timespec sleep_time;
    sleep_time.tv_sec = ms / 1000;
    sleep_time.tv_nsec = (ms % 1000) * (long)(1e6);
    
    (void)nanosleep(&sleep_time, NULL);
}

static int write_all(int fd, const char* buff, size_t length) {
    // calls write() until every byte of buff is written
    // prevents partial writes due to ...(idk)
    size_t total = 0;

    while (total < length) {
        // points to beginning of what to write
        ssize_t written = write(fd, buff + total, length - total);
        
        if (written == -1) {
            if (errno == EINTR) continue; // interrupted by a signal
            return -1;
        }

        total +=(size_t) written;
    }

    return 0;
}




/*
todo
write_all
*/

// Terminal Native Stuff
int terminal_update_size(Terminal* terminal) {
    struct winsize size;

    if ( ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == -1) {
        // ioctl modifies size memory directly
        return -1;
    }

    terminal->height = size.ws_row;
    terminal->width = size.ws_col;

    return 0;
}


int terminal_present(const char* buff, size_t length) {
    // Writes a buffer.
    // Displays one frame produced by the renderer

    // overwrites old frame directly instead of clearing screen
    if ( write_all(STDOUT_FILENO, "\x1b[H", 3) == -1 ) {
        return -1;
    }
    if ( write_all(STDOUT_FILENO, buff, length) == -1 ) {
        return -1;
    }

    return 0;
}


int terminal_init(Terminal* terminal) {
    // Initializes Terminal obj with proper settings
    // i.e., turning off canon input type and echoing characters

    int temp = tcgetattr(STDIN_FILENO, &terminal->original_settings);
    struct termios raw = terminal->original_settings;
    raw.c_lflag &= ~(ICANON | ECHO); // disables ICANON + ECHO bit flags

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // what is TCSAFLUSH?

    hide_cursor();
    clear_screen();

    return 0;
}


void terminal_restore(Terminal* terminal) {
    // cleanup
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal->original_settings);
    show_cursor();
    clear_screen();
}
