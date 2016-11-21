
/*************************************************
 **						**
 **   Particle loading for uniform density	**
 **						**
 *************************************************/

#include "es.h"

/* local variables */

double dpxe, dpxi;					/* particle spacing */ 
int i;						/* counter */

void loadx(int n, double x[])
{
    if (bc_particle >= 2)
    {
         /**  for reflective bcs to work properly, must place particle
              boundaries half a mesh spacing inside field boundaries  **/

         wall_left = dx/2.;
         wall_right = grid_length-dx/2.;
	 plasma_end = wall_right;		/* actually want min(end,wr) */
    }
    else 
    {
         /*  periodic boundaries */

         wall_left = 0.;
         wall_right = grid_length;
         plasma_start = 0.;
	 plasma_end = grid_length;
    }

    xload = plasma_end - plasma_start;		/* length for particle loading */
    dpxe = xload/ne;				/* particle spacing */
    dpxi = xload/ni;

    /* pseudo-particle charge normalised to give ncrit=1 (rhoc=-1) */

    qe = -rho0*dpxe;
    qi = rho0*dpxi; 

    /* pseudo-particle mass (need for kinetic energy diagnostic) */

    e_mass = qe / q_over_me;
    i_mass = qi / q_over_mi;

    /* set up initial positions */

    for (i = 0; i < n; i++)
    { 
        x[i] = plasma_start + dpxe*(i-0.5);
    }
}
