#include "es.h"
#include "math.h"

typedef struct
{
	double real;
	double img;
}complex;


complex x[fftpoint], *W;
double PI;
void filtering(void)
{
	int i, j;
	PI = atan(1) * 4;

/*	for (i = 0; i<nx; i++)
	{
		x[i].real = sin(2*PI*10/fftsize*0.2*i)+2*sin(2*PI*10/fftsize*0.2*i*5);
		x[i].img = 0.0;
	}
*/
	for (i=0; i<nx; i++)
	{
		x[i].real = phi[i];
		x[i].img = 0.0;
	}

	initW();
	fft();
	for (i = 0; i<nx; i++)
	{
		phifft[i] = sqrt(x[i].real*x[i].real+x[i].img*x[i].img);
	}
	for (i = 0; i<nx; i++)
	{
		if ( i>5 && i<1019 || i==0  )
/*		if ( i!=3 && i!=1021 )*/
/*		if ( i!=2 && i!=1022 && i!=3 && i!=1021 )*/		/* a+b=1024 */
		{
			x[i].real = 0.0;
			x[i].img = 0.0;
		}
	}

	for ( j=0; j<10; j++)
	{
	    phiAt[j][i_time] = sqrt(x[j+1].real*x[j+1].real+x[j+1].img*x[j+1].img);
	}

	ifft();
	for (i=0; i<nx; i++)
		phi[i] = x[i].real;
/*		phi[i] = sin(2*PI*10/fftsize*i)+2*sin(2*PI*10/fftsize*i*5);
*/	phi[nx] = phi[0];
}

void fft()
{
	int i = 0, j = 0, k = 0, l = 0;
	complex up, down, product;
	change();
	for (i = 0; i< log(fftsize) / log(2); i++)
	{
		l = 1 << i;
		for (j = 0; j<fftsize; j += 2 * l)
		{
			for (k = 0; k<l; k++)
			{
				mul(x[j + k + l], W[fftsize*k / 2 / l], &product);
				add(x[j + k], product, &up);
				sub(x[j + k], product, &down);
				x[j + k] = up;
				x[j + k + l] = down;
			}
		}
	}
}
void ifft()
{
	int i = 0, j = 0, k = 0, l = fftsize;
	complex up, down;
	for (i = 0; i< (int)(log(fftsize) / log(2)); i++)
	{
		l /= 2;
		for (j = 0; j<fftsize; j += 2 * l)
		{
			for (k = 0; k<l; k++)
			{
				add(x[j + k], x[j + k + l], &up);
				up.real /= 2; up.img /= 2;
				sub(x[j + k], x[j + k + l], &down);
				down.real /= 2; down.img /= 2;
				divi(down, W[fftsize*k / 2 / l], &down);
				x[j + k] = up;
				x[j + k + l] = down;
			}
		}
	}
	change();
}
void initW()
{
	int i;
	W = (complex *)malloc(sizeof(complex) * fftsize);
	for (i = 0; i<fftsize; i++)
	{
		W[i].real = cos(2 * PI / fftsize*i);
		W[i].img = -1 * sin(2 * PI / fftsize*i);
	}
}
void change()
{
	complex temp;
	unsigned short i = 0, j = 0, k = 0;
	double t;
	for (i = 0; i<fftsize; i++)
	{
		k = i; j = 0;
		t = (log(fftsize) / log(2));
		while ((t--)>0)
		{
			j = j << 1;
			j |= (k & 1);
			k = k >> 1;
		}
		if (j>i)
		{
			temp = x[i];
			x[i] = x[j];
			x[j] = temp;
		}
	}
}
void add(complex a, complex b, complex *c)
{
	c->real = a.real + b.real;
	c->img = a.img + b.img;
}
void mul(complex a, complex b, complex *c)
{
	c->real = a.real*b.real - a.img*b.img;
	c->img = a.real*b.img + a.img*b.real;
}
void sub(complex a, complex b, complex *c)
{
	c->real = a.real - b.real;
	c->img = a.img - b.img;
}
void divi(complex a, complex b, complex *c)
{
	c->real = (a.real*b.real + a.img*b.img) / (
		b.real*b.real + b.img*b.img);
	c->img = (a.img*b.real - a.real*b.img) / (b.real*b.real + b.img*b.img);
}
