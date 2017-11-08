/*************************************************
 **						**
 **    Set up particle velocity distribution	**
 **						**
 *************************************************/


#include "es.h"
#include "math.h"
#include "time.h"

void loadv_EP(int n_EP, double v_EP, double vt, double vx_EP[])
{

    int i, j, k, pnx, pnv;
/*    double b, a[2];*/

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
/*    for (i=0; i<n_EP; i++)
    {
	b = (double) random() / random_max;
	vx_EP[i] = 15.0+15.0*b;
    }
*/

/*    for (i=0; i<n_EP; i++)
    {
	w_EP[i] = (double) i/n_EP;
	vx_EP[i] = 5.0+w_EP[i]*15.0;

	b = (double) n_EP/(n_EP-1);
	w_EP[i] = w_EP[i]*2.0*b;
    }
*/

/*    for (i=0; i<n_EP; i=i+2)
    {
	for (j=0; j<2; j++)
	    a[j] = (double) random() / random_max;

*//*	vx_EP[i] = v_EP+sqrt(-2*vt*vt*log(a[0]))*cos(2*pi*a[1]);
	vx_EP[i+1] = v_EP+sqrt(-2*vt*vt*log(a[0]))*sin(2*pi*a[1]);
*/
/*	vx_EP[i] = 23.127+sqrt(-2*0.6*0.6*log(a[0]))*cos(2*pi*a[1]);
        vx_EP[i+1] = 23.127+sqrt(-2*0.6*0.6*log(a[0]))*sin(2*pi*a[1]);
    }
*/
    pnx = 256;	/* 256 */
    pnv = 200;	/* 200 */
    for ( j=0; j<pnv; j++ )
    {
	for ( i=0; i<pnx; i++ )
	{
	    k = j*pnx+i;
	    vx_EP[k] = (double) 5.0+15.0/pnv*(j+1.0);
	    w_EP[k] =  (double) (1.0+j*2.0)/pnv;
	}
    }
}
