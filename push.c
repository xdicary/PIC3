/*************************************************
 **						**
 **		       push.c			**
 **						**
 **	    Electrostatic particle pusher	**
 **						**
 *************************************************/

#include "es.h"

void push(int n, double x[], double Ex[], double vx[], double q_over_m)
{

    /* locals */

    double xa;			/* fractional particle position */
    double b1, b2;		/* linear weights */
    double exi;			/* interpolated e-field */
    int i, j1, j2;		/* grid indices */



    if ( i_time == 1 )
    {
	for ( i=0; i<n; i++ )
	    x[i] = x[i] + 0.5*dt*vx[i];
    }

    for( i=0; i<n; i++)
    {
        /* interpolate field Ex from grid to particle */

        xa = x[i]/dx;
        j1 = xa;
        j2 = j1 + 1;
        b2 = xa - j1;
        b1 = 1.0 - b2;
        exi = b1*Ex[j1] + b2*Ex[j2];
      
        /*  update velocities */

        vx[i] = vx[i] + q_over_m*dt*exi; 
    }


    /*  update positions (2nd half of leap-frog) */

    for( i=0; i<n; i++)
    {
        x[i] = x[i] + dt*vx[i];
    }

}
