
/*************************************************
 **						**
 **   Particle loading for uniform density	**
 **						**
 *************************************************/

#include "es.h"

/* local variables */

double dpx;					/* particle spacing */ 
int i;						/* counter */

void loadx_EP(int n_EP, double x_EP[])
{
    dpx = xload/n_EP;				/* particle spacing */

    /* set up initial positions */

    for (i = 0; i < n_EP; i++)
    { 
        x_EP[i] = plasma_start + dpx*(i+0.5);
    }
}
