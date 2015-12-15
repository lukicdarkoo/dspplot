#include "fft.h"

void fft(int N, double (*x)[2], double (*X)[2])
{
  /* Declare a pointer to scratch space. */
  double (*XX)[2] = malloc(2 * N * sizeof(double));

  /* Calculate FFT by a recursion. */
  fft_rec(N, 0, 1, x, X, XX);

  /* Free memory. */
  free(XX);
}

/* FFT recursion */
void fft_rec(int N, int offset, int delta,
             double (*x)[2], double (*X)[2], double (*XX)[2])
{
  int N2 = N/2;            /* half the number of points in FFT */
  int k;                   /* generic index */
  double cs, sn;           /* cosine and sine */
  int k00, k01, k10, k11;  /* indices for butterflies */
  double tmp0, tmp1;       /* temporary storage */

  if(N != 2)  /* Perform recursive step. */
    {
      /* Calculate two (N/2)-point DFT's. */
      fft_rec(N2, offset, 2*delta, x, XX, X);
      fft_rec(N2, offset+delta, 2*delta, x, XX, X);

      /* Combine the two (N/2)-point DFT's into one N-point DFT. */
      for(k=0; k<N2; k++)
        {
          k00 = offset + k*delta;    k01 = k00 + N2*delta;
          k10 = offset + 2*k*delta;  k11 = k10 + delta;
          cs = cos(TWO_PI*k/(double)N); sn = sin(TWO_PI*k/(double)N);
          tmp0 = cs * XX[k11][0] + sn * XX[k11][1];
          tmp1 = cs * XX[k11][1] - sn * XX[k11][0];
          X[k01][0] = XX[k10][0] - tmp0;
          X[k01][1] = XX[k10][1] - tmp1;
          X[k00][0] = XX[k10][0] + tmp0;
          X[k00][1] = XX[k10][1] + tmp1;
        }
    }
  else  /* Perform 2-point DFT. */
    {
      k00 = offset; k01 = k00 + delta;
      X[k01][0] = x[k00][0] - x[k01][0];
      X[k01][1] = x[k00][1] - x[k01][1];
      X[k00][0] = x[k00][0] + x[k01][0];
      X[k00][1] = x[k00][1] + x[k01][1];
    }
}

/* IFFT */
void ifft(int N, double (*x)[2], double (*X)[2])
{
  int N2 = N/2;       /* half the number of points in IFFT */
  int i;              /* generic index */
  double tmp0, tmp1;  /* temporary storage */

  /* Calculate IFFT via reciprocity property of DFT. */
  fft(N, X, x);
  x[0][0] = x[0][0]/N;    x[0][1] = x[0][1]/N;
  x[N2][0] = x[N2][0]/N;  x[N2][1] = x[N2][1]/N;
  for(i=1; i<N2; i++)
    {
      tmp0 = x[i][0]/N;       tmp1 = x[i][1]/N;
      x[i][0] = x[N-i][0]/N;  x[i][1] = x[N-i][1]/N;
      x[N-i][0] = tmp0;       x[N-i][1] = tmp1;
    }
}
