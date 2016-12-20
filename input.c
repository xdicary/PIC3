/*************************************************
**						**
**		Parameters input		**
**						**
**************************************************/


#include "es.h"

void input(void)
{
    /* set up simulation parameters */

    nt = 20000;			/* # timesteps  */
    nx = 1024;                   /* # grid points */

    ne = 51200;			/* # electrons   */
    ni = 51200;                     /* # ions */

    ne_EP = 10240;
    ni_EP = 10240;

    weighting_EP = 1.0;

    ve_EP = 4.0;
    vi_EP = 2.0;

    grid_length = 204.8;        /* size of spatial grid */
    plasma_start = 0.;          /* plasma edge */

    dt = 0.02;			/* normalised timestep */

    q_over_me = -1.0;             /* electron charge:mass ratio */

    rho0 = 1.0;			/* background ion density */
    vte = 1.0;			/* thermal velocity */
    vti = 0.015;
    
    fftsize = 1024;		/* 2^n */

    energic_particle = 2;       /* 0 = no energic particles,    */
                                /* 1 = energic electrons,       */
                                /* 2 = energic ions             */

    filtering_switch = 0;	/* 0 = no filtering	*/

    perturbation_switch = 0;	/* 0 = no perturbation, 			*/
				/* 1 = perturbation on initial density,		*/
				/* 2 = perturbation on boundary potential	*/

    bc_field = 1;               /* field boundary conditions:  1 = periodic, */
                                /*                             2 = reflective */

    bc_particle = 1;            /* particle BCs:  1 = periodic, */
                                /*                2 = reflective, */
                                /*                3 = thermal */

    ihist = 1;                  /* frequency of time-history output */
    igraph = 5000;                /* freq. of graphical snapshots */
    iout = 1000;			/* freq. of printed diags. */
}
