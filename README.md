#OAiS DSP 1
Pattern to plot data in C

## Getting started
- Install **gnuplot**
```
	sudo apt-get install gnuplot
	sudo apt-get install gnuplot-x11
```
- Clone repositorium `git clone https://github.com/lukicdarkoo/dspplot.git`
- Compile example `make`
- Run example `./bin/dspplot`

## Plotting
x - array for x axis (to avoid warnings cast to double *)  
y - array for y axis (to avoid warnings cast to double *)  
length - array length  
size - sizeof(data type)  
  
Standard plot  
```plot(double* x, double* y, int length, int size)```
  
Plot will automatically set values for x axis   
```plot_y(double *y, int length, int size)```
  
Plot will calculate FFT and automatically set values for x axis  
```extern void plot_fft_y(double* y, int length, int size)```
  
Prepare data for Audacity  
```plot_file(double* y, int length, int size, char *filename)```
