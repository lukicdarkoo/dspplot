#ifndef simulator_h
#define simulator_h

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "fft.h"

// Fix data types
typedef int16_t Int16;
#define AUDIO_IO_SIZE 128


#define PLOT_TEMPFILE "data.temp"

/*
IMPORTANT: It is able to plot only double and 16bit integer (for now)!
IMPORTANT: To use plot() run: sudo apt-get install gnuplot & sudo apt-get install gnuplot-x11

x - array for x axis (to avoid warnings cast to double *)
y - array for y axis (to avoid warnings cast to double *)
length - array length
size - sizeof(data type)
*/

// Standard plot
extern void plot(double* x, double* y, int length, int size);

// Plot will automatically set values for x axis
extern void plot_y(double *y, int length, int size);

// Plot will calculate FFT and automatically set values for x axis
extern void plot_fft_y(double* y, int length, int size);

#endif
