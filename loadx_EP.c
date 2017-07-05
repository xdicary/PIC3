
/*************************************************
 **						**
 **   Particle loading for uniform density	**
 **						**
 *************************************************/

#include "es.h"
#include "time.h"

/* local variables */

double dpx, tmp;					/* particle spacing */ 
int i, index;						/* counter */

void loadx_EP(int n_EP, double x_EP[])
{
    dpx = xload/n_EP;				/* particle spacing */

    /* set up initial positions */

    for (i = 0; i < n_EP; i++)
    { 
        x_EP[i] = plasma_start + dpx*(i+0.5);
    }

/*    srand(time(NULL));
    for(i = n_EP-1; i > 0; i--)
    {
	index = rand()%i;
	tmp = x_EP[i];
	x_EP[i] = x_EP[index];
	x_EP[index] = tmp;
    }
*/
}
