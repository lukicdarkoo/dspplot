#include "simulator.h"

void plot(double* x, double* y, int length, int size) {
    FILE * temp = fopen(PLOT_TEMPFILE, "w");
    FILE * gnuplotPipe = popen("gnuplot -persistent", "w");

    int i;
    for (i = 0; i < length; i++) {
				if (size == 2) {
        	fprintf(temp, "%f %f\n", x[i], (double)((Int16 *)y)[i]);
				} else {
					fprintf(temp, "%f %f\n", x[i], y[i]);
				}
    }


    fprintf(gnuplotPipe, "%s \n", "plot '"PLOT_TEMPFILE"' with linespoints");
}


void plot_y(double *y, int length, int size) {
    double x[length];
    int i;
    for (i = 0; i < length; i++) {
        x[i] = i;
    }

    plot(x, y, length, size);
}

void plot_fft_y(double* y, int length, int size) {
	double buffer_complex[length][2];
	double buffer_fft[length][2];
	double buffer_fft_array[length];
	int i;

	for (i = 0; i < length; i++) {
		buffer_complex[i][0] = i;

		if (size == 2) {
			buffer_complex[i][1] = (double)((Int16 *)y)[i];
		}	else {
			buffer_complex[i][1] = y[i];
		}
	}

	fft(length, buffer_complex, buffer_fft);

	for (i = 0; i < length; i++) {
		buffer_fft_array[i] = sqrt(buffer_fft[i][0] * buffer_fft[i][0] + buffer_fft[i][1] * buffer_fft[i][1]);
	}

	plot_y(buffer_fft_array, length, sizeof(double)); 
}
