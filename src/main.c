#include <stdio.h>
#include <math.h>
#include "gen_sinus.h"
#include "lib/simulator.h"

#include "lib/fft.h"

#define LEN 1024

Int16 buffer_first[LEN];
Int16 buffer_second[LEN];
Int16 buffer[LEN];

int main() {
  int i;

	gen_sinus_table(LEN, 0.5, 0.005, 0, buffer_first);
	gen_sinus_table(LEN, 0.5, 0.05, 0, buffer_second);

	
	for (i = 0; i < LEN; i++) {
		buffer[i] = buffer_first[i] + buffer_second[i];
	}
	

	plot_y((double *)buffer, LEN, sizeof(Int16));

	//plot_fft_y((double *)buffer, LEN, sizeof(Int16));

  return 0;
}

