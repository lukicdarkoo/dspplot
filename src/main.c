#include "gen_sinus.h"
#include "plot.h"

#include "stdio.h"
#include "math.h"

float buffer[1000];

int main() {
  gen_sinus(1000, 10, 0.02, 0, buffer);
	plot_y(buffer, 1000);

	printf("%f", sin(M_PI / 2));

  return 0;
}
