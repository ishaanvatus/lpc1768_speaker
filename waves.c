#include <LPC17xx.h>
#include <math.h>
#include "waves.h"
#include "timer.h"

#define MAX_DAC_VALUE (1024 - 1) // 2**10 = 1024
#define PI 3.14159265

void dac_init(void) 
{
    LPC_PINCON->PINSEL1 |= (1 << 21); //P0.26 first alt fn AD0
}

void sine(double amp, double freq, double duration) 
{
    double period = 1.0 / freq;
    int cycles = (int)(duration / 0.1);
    int dac_value, i;
    double value, t;
    
    for (i = 0; i < cycles; i++) {
        t = 0;
        while (t < period) {
            value = amp * sin(2 * PI * freq * t);
            dac_value = (int)((value + 1.0) * (MAX_DAC_VALUE / 2.0));
            LPC_DAC->DACR = (dac_value << 6);
            t += 0.1;
            delay(1);
        }
    }
}
void square(double amp, double freq, double duration) 
{
    double period = 1.0 / freq;
    int cycles = (int)(duration / 0.1); 
    int dac_value, i;
    double value, t;
    
    for (i = 0; i < cycles; i++) {
        t = 0;
        while (t < period) {
            value = (t < period / 2) ? amp : -amp;
            dac_value = (int)((value + 1.0) * (MAX_DAC_VALUE / 2.0)); 
            LPC_DAC->DACR = (dac_value << 6);
            t += 0.1; 
            delay(1); 
        }
    }
}

void sawtooth(double amp, double freq, double duration)
{
    double period = 1.0 / freq;
    int cycles = (int)(duration / 0.1); 
    int dac_value, i;
    double value, t;
    
    for (i = 0; i < cycles; i++) {
        t = 0;
        while (t < period) {
            value = (2 * amp / period) * fmod(t, period);
            dac_value = (int)((value + 1.0) * (MAX_DAC_VALUE / 2.0));
            t += 0.1; 
            delay(1); 
        }
    }
}

void triangle(double amp, double freq, double duration)
{
    double period = 1.0 / freq;
    int cycles = (int)(duration / 0.1);
    int dac_value, i;
    double value, t;
    
    for (i = 0; i < cycles; i++) {
        t = 0;
        while (t < period) {
            value = (2 * amp / period) * (fmod(t, period) - (period / 2));
            if (value < 0) value = -value;
            dac_value = (int)((value + 1.0) * (MAX_DAC_VALUE / 2.0)); 
            LPC_DAC->DACR = (dac_value << 6);
            t += 0.1; 
            delay(1);
        }
    }
}
