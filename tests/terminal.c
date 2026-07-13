#include <assert.h>
#include "../src/terminal.h"

int main (void) {
    Terminal terminal;
    
    assert (terminal_init(&terminal) == 0);
}