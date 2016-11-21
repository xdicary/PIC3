/*************************************************
 **						**
 **    Set up particle velocity distribution	**
 **						**
 *************************************************/


#include "es.h"
#include "math.h"
#include "time.h"

void loadv(int n, double vt, double vx[])
{

    int i, j;
    double a[2];

    for (i = 0; i<n; i=i+2)
    {

	for (j=0; j<2; j++)
	    a[j] = (double) random() / random_max;

	vx[i] = sqrt(-2.0*vt*vt*log(a[0]))*cos(2.0*pi*a[1]);
	vx[i+1] = sqrt(-2.0*vt*vt*log(a[0]))*sin(2.0*pi*a[1]);

    }

}
