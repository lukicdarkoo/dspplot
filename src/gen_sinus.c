#include "gen_sinus.h"
#include "sine_table.h"
#include "math.h"

#define PI 3.14159265

void gen_sinus(int n, float a, float f, float ph, float buffer[])
{
	int i;
	for (i=0; i<n; i++)
	{
		buffer[i] = a * sin(2 * PI * f * i + ph);
	}
}

void gen_sinus_table(int n, float a, float f, float ph, float buffer[])
{
	/* TO DO: Generate sine wave using look up table */
}

void gen_sinus_multiton(int n, float a, float f0, float df, float ph, float buffer[])
{
	/* TO DO: Generate multitone sine wave */
}

void gen_lin_sweep(int n, float a, float f1, float f2, float ph, float buffer[])
{
    /* TO DO: Generate linear sweep sine wave*/
}

void gen_log_sweep(int n, float a, float f1, float f2, float ph, float buffer[])
{
    int i = 0;
    float df = log(f2/f1)/n;
    float f = f1;
    for(i = 0; i < n; i++)
    {
    	buffer[i] = a*sin(2*PI*f*i+ph);
    	f=f*exp(df);
    }
}

void gen_square(int n, float a, float b, int na, int nb, float buffer[])
{
    /* TO DO: Generate square wave */
}
