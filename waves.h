#ifndef WAVES_H
#define WAVES_H

void dac_init(void);
void sine(double amp, double freq, double duration);
void square(double amp, double freq, double duration);
void sawtooth(double amp, double freq, double duration);
void triangle(double amp, double freq, double duration);

#endif
