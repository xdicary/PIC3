/*****************************************
 **					**
 **	      Electron density		**
 **					**
 *****************************************/

#include "es.h"

void density(void)
{
    double re, ri, xa, f1, f2;
    int i, j, j1, j2, iwl, iwr;

    re = qe/dx;			/*  charge weighting factor */
    ri = qi/dx;

    if (energic_particle == 1)
	re = re*ne/(ne+ne_EP/weighting_EP);

    if (energic_particle == 2)
	ri = ri*ni/(ni+ni_EP/weighting_EP);

    for (j=0; j<=nx; j++) 
    {
	rho_plasmae[j] = 0.0;
	rho_plasmai[j] = 0.0;
	rho_EP[j] = 0.0;
	rho_all[j] = 0.0;
    }

    /* gather density onto grid from particles */

    for (i=0; i<ne; i++)
    {
        xa = xe[i]/dx;
        j1 = xa;
        j2 = j1 + 1;
        f2 = xa - j1;
        f1 = 1.0 - f2;
        rho_plasmae[j1] = rho_plasmae[j1] + re*f1;
        rho_plasmae[j2] = rho_plasmae[j2] + re*f2;
    }

    for (i=0; i<ni; i++)
    {
        xa = xi[i]/dx;
        j1 = xa;
        j2 = j1 + 1;
        f2 = xa - j1;
        f1 = 1.0 - f2;
        rho_plasmai[j1] = rho_plasmai[j1] + ri*f1;
        rho_plasmai[j2] = rho_plasmai[j2] + ri*f2;
    }

   if ( energic_particle == 1 )
    {
        for (i=0; i<ne_EP; i++)
        {
            xa = x_EP[i]/dx;
            j1 = xa;
            j2 = j1 + 1;
            f2 = xa - j1;
            f1 = 1.0 - f2;
            rho_EP[j1] = rho_EP[j1] + re*f1*w_EP[i]/weighting_EP;
            rho_EP[j2] = rho_EP[j2] + re*f2*w_EP[i]/weighting_EP;
        }
    }

    if ( energic_particle == 2 )
    {
        for (i=0; i<ni_EP; i++)
        {
            xa = x_EP[i]/dx;
            j1 = xa;
            j2 = j1 + 1;
            f2 = xa - j1;
            f1 = 1.0 - f2;
            rho_EP[j1] = rho_EP[j1] + ri*f1/weighting_EP;
            rho_EP[j2] = rho_EP[j2] + ri*f2/weighting_EP;
        }
    }

    for (j=0; j<=nx; j++)
	rho_all[j] = rho_plasmae[j] + rho_plasmai[j] + rho_EP[j];
/*	rho_all[j] = rho_plasmae[j] + 1.0;
*/
    if (bc_field == 1)
    {
        /* periodic boundaries */ 
        rho_all[0] += rho_all[nx];
        rho_all[nx] = rho_all[0];
    }

    else     			
	/* bc_field =2 */
    {
        /* reflective - 1st and last (ghost) cells folded back onto physical grid */
        iwl = wall_left/dx;
        rho_all[iwl+1] += rho_all[iwl];
        rho_all[iwl] = 0.0;	

        iwr = wall_right/dx;
        rho_all[iwr] += rho_all[iwr+1];
        rho_all[iwr+1] = rho_all[iwr];
    }     

}
