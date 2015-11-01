/*
IMPORTANT: To use plot() run:
sudo apt-get install gnuplot
sudo apt-get install gnuplot-x11
*/

#ifndef PLOT_H
#define PLOT_H

#include "stdio.h"
#define PLOT_TEMPFILE "data.temp"

extern void plot(float* x, float* y, int length) {
    FILE * temp = fopen(PLOT_TEMPFILE, "w");
    FILE * gnuplotPipe = popen("gnuplot -persistent", "w");

    int i;
    for (i = 0; i < length; i++) {
        fprintf(temp, "%lf %lf \n", x[i], y[i]);
    }

    fprintf(gnuplotPipe, "%s \n", "plot '"PLOT_TEMPFILE"' with linespoints ls 1");
}


extern void plot_y(float *y, int length) {
    float x[length];
    int i;
    for (i = 0; i < length; i++) {
        x[i] = (float)i;
    }

    plot(x, y, length);
}

#endif
