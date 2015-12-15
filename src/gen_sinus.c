#include "gen_sinus.h"
#include "sine_table.h"
#include "math.h"

#define PI 3.14159265

/********************************************************************
 * Generisanje sinusnog signala upotrebom tabele pretrazivanja
 *   n - broj odbiraka
 *   a - amplituda (u opsegu 0 - 1.0)
 *   f - frekvencija (normalizovana)
 *   ph - fazni pomeraj
 *   buffer - niz u kome ce biti smesten izlazni signal
 *********************************************************************/

void gen_sinus_table(int n, float a, float f, float ph, Int16 buffer[])
{
	int N = SINE_TABLE_SIZE;
	//int delta = N * (f / 8000);
	int delta = N * f;
	float final;

	int m = (ph * SINE_TABLE_SIZE) / (2 * PI);

	int i = 0;
	for (i=0; i < n; i++) {
		m += delta;
		if (m >= N) {
			m -= N;
		}
		// Int16 k = (int)(ph + i * delta) % N;
		int k = m % N - 1;

		if (k <= N/4) {
			final = p_sine_table[k];
		}
		else if (k <= N/2) {
			final = p_sine_table[N/2 - k];
		}
		else if (k <= 3*N/4) {
			final = - p_sine_table[k - N/2];
		}
		else {
			final = - p_sine_table[N - k];
		}

		buffer[i] = a * final;
	}
}
