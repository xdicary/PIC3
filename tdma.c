/*****************************************
 **					**
 **	Tridiagonal Matrix Algorithm	**
 **					**
 *****************************************/

#include "es.h"
#include "math.h"

void tdma(void)
{
    double a[nx];
    double b[nx+1];
    double c[nx];
    int i;
    double m, test;

/*    for (i=0; i<nx; i++)
	a[i] = -1.0;
    a[nx] = 0.0;

    for (i=0; i<=nx; i++)
	b[i] = 2.0;
    b[nx+1] = 1.0;

    for (i=1; i<=nx; i++)
	c[i] = -1.0;
*/
    for (i=0; i<nx-1; i++)
	a[i] = -1.0;
    a[nx-1] = nx;

    for (i=1; i<nx; i++)
	b[i] = 2.0;
    b[0] = 1.0;
    b[nx] = -nx;

    for (i=1; i<nx; i++)
	c[i] = -1.0;
    c[0] = 0.0;
/* 
    for(i=0; i<nx; i++)
    {
	test = 2.0*pi*i/nx;
	rhot[i] = cos(test);
    }
*/
    for(i=1; i<nx; i++)
        phi[i] = rhot[i]*dx*dx;
    phi[0] = 0.0;
    phi[nx] = 0.0;
    for(i=3; i<=nx; i++)
	phi[nx] = phi[nx]+(i-2)*rhot[i-1]*dx*dx;

    for (i=1; i<nx; i++)
    {
	m = 1.0/( b[i] - a[i-1]*c[i-1] );
        c[i] = c[i]*m;
	phi[i] = ( phi[i] - a[i-1]*phi[i-1] )*m;
    }
    phi[nx] = ( phi[nx] - a[nx-1]*phi[nx-1] )/( b[nx] - a[nx-1]*c[nx-1] );
    for (i=nx-1; i>0; i--)
	phi[i] = phi[i] - c[i]*phi[i+1];
}
