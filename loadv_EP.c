/*************************************************
 **						**
 **    Set up particle velocity distribution	**
 **						**
 *************************************************/


#include "es.h"
#include "math.h"
#include "time.h"

void loadv_EP(void)
{

    int i, j;
    double b, a[2];

/*    for (i=0; i<ni_EP; i++)
    {
        b = (double) random() / random_max;

        if ( b < 0.5 )
            vx_EP[i] = 0.2*log(2.0*b);

        else
            vx_EP[i] = -0.2*log(2.0*(1-b));

        vx_EP[i] = vx_EP[i]+2.5;
    }
*/

    for (i=0; i<ni_EP; i=i+2)
    {
	for (j=0; j<2; j++)
	    a[j] = (double) random() / random_max;

	vx_EP[i] = vi_EP+sqrt(-2*vti*vti*log(a[0]))*cos(2*pi*a[1]);
	vx_EP[i+1] = vi_EP+sqrt(-2*vti*vti*log(a[0]))*sin(2*pi*a[1]);
    }

}
