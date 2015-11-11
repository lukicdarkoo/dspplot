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
- `plot(float* x_array, float* y_array, int length_of_array)` or
- `plot_y(float* y_array, int length_of_array)`
