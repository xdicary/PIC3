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
    double b[nx];
    double c[nx];
    double d[nx];

    double q[nx];
    double u[nx];
    double t[nx];
    double h[nx];
    double g[nx];
    int i, j;
    double p, test;
    double phi_iteration[nx+1];

    for (i=0; i<nx; i++)
	a[i] = -1.0;

    for (i=0; i<nx; i++)
	b[i] = 2.0;

    for (i=0; i<nx; i++)
	c[i] = -1.0;
/* 
    for(i=0; i<=nx; i++)
    {
	test = 2.0*pi*i/nx;
	rhot[i] = cos(test);
    }
*/
    for (i=0; i<nx; i++)
        d[i] = rhot[i+1]*dx*dx;

    p = b[0];
    q[0] = -c[0]/p;
    t[0] = -a[0]/p;
    u[0] = d[0]/p;

    for (i=1; i<nx-1; i++)
    {
	p = a[i]*q[i-1]+b[i];
	u[i] = (d[i]-a[i]*u[i-1])/p;
	q[i] = -c[i]/p;
	t[i] = -a[i]*t[i-1]/p;
    }

    h[nx-1] = (d[nx-1]-a[nx-1]*u[nx-2])/(a[nx-1]*(q[nx-2]+t[nx-2])+b[nx-1]);
    g[nx-1] = -1.0*c[nx-1]/(a[nx-1]*(q[nx-2]+t[nx-2])+b[nx-1]);

    h[nx-2] = u[nx-2]+(q[nx-2]+t[nx-2])*h[nx-1];
    g[nx-2] = (q[nx-2]+t[nx-2])*g[nx-1];

    for (i=nx-3; i>0; i--)
    {
	h[i] = u[i]+q[i]*h[i+1]+t[i]*h[nx-1];
	g[i] = q[i]*g[i+1]+t[i]*g[nx-1];
    }

    phi[1] = (d[0]-c[0]*h[1]-a[0]*h[nx-1])/(b[0]+c[0]*g[1]+a[0]*g[nx-1]);
    for (i=1; i<nx; i++)
	phi[i+1] = h[i]+g[i]*phi[1];
    phi[0] = phi[nx];

    /* Jacobi iteration */
    for (j=0; j<50; j++)
    { 
	for (i=1; i<nx; i++)
	{
	    phi_iteration[i] = (phi[i+1]+phi[i-1]+rhot[i]*dx*dx)/2.0;
	}
	phi_iteration[0] = (phi[nx-1]+phi[1]+rhot[0]*dx*dx)/2.0;
	phi_iteration[nx] = phi_iteration[0];

	for (i=0; i<=nx; i++)
	    phi[i] = phi_iteration[i];
    }

}
