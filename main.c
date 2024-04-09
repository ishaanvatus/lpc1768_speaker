#include <LPC17xx.h>
#include "timer.c"
#include "waves.c"

// frequencies for "Happy Birthday" melody
#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define G4 392.00
#define A4 440.00
#define B4 493.88

// note durations in terms of 0.1 ms
#define QUARTER_NOTE 500 // 0.1 ms * 500 = 50 ms
#define HALF_NOTE (2 * QUARTER_NOTE) // 100 ms
#define EIGHTH_NOTE (QUARTER_NOTE / 2) // 25 ms

int main(void) {
    // initialize timer
    timer_init();
    //initialize dac
    dac_init();

    // Play "Happy Birthday" melody
    // Note: The melody is played in C major key
    sine(0.5, C4, QUARTER_NOTE);
    sine(0.5, C4, QUARTER_NOTE);
    sine(0.5, D4, HALF_NOTE);
    sine(0.5, C4, HALF_NOTE);

    sine(0.5, F4, QUARTER_NOTE);
    sine(0.5, E4, QUARTER_NOTE);
    sine(0.5, C4, HALF_NOTE);

    sine(0.5, F4, QUARTER_NOTE);
    sine(0.5, E4, QUARTER_NOTE);
    sine(0.5, D4, HALF_NOTE);

    sine(0.5, G4, QUARTER_NOTE);
    sine(0.5, C4, HALF_NOTE);

    // Pause between phrases
    delay(20000); // 2-second pause (2000 * 0.1 ms = 200 ms)

    sine(0.5, G4, QUARTER_NOTE);
    sine(0.5, F4, QUARTER_NOTE);
    sine(0.5, E4, HALF_NOTE);

    sine(0.5, C4, QUARTER_NOTE);
    sine(0.5, D4, QUARTER_NOTE);
    sine(0.5, C4, HALF_NOTE);

    return 0;
}
