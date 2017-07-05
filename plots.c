
/*************************************************
 **						**
 **		Graphical snapshots		**
 **						**
 *************************************************/

#include "es.h"

 
FILE  *plot_file;     		/* file for dumping plot data */            

int isnap = 0;                	/* counts number of calls to routine 'plots' */

void plots(void)
{

    double phip[nx];

    double xgrid[nx];    	/* grid work array */

    char cfile[40];         	/* plot filename string */

    int i,j;

    for (j=0; j<=nx; j++)
    {
	xgrid[j] = j*dx;   	/* set up x-values for grid plots */
    }


    /* electron density */

    sprintf(cfile,"density%d.data", isnap ); 
    plot_file = fopen(cfile, "w");

    for (j=0; j<=nx; j++)
    {
	fprintf( plot_file, "%f	%f	%f\n" ,xgrid[j],-rho_all[j],rhot[j] );
    }

    fclose(plot_file);


    /* electrostatic field */

    sprintf(cfile,"phie%d.data", isnap ); 
    plot_file = fopen(cfile, "w");

    for (j=0; j<=nx; j++)
    {
	fprintf( plot_file, "%f	%f	%f	%f\n" ,xgrid[j],phi[j],Ex[j],pphi[j] );
    }

    fclose(plot_file);


    sprintf(cfile,"phifft%d.data", isnap );
    plot_file = fopen(cfile, "w");

    for (j=0; j<fftsize; j++)
    {
        fprintf( plot_file, "%f\n" , phifft[j] );
    }

    fclose(plot_file);


    sprintf(cfile,"vxt%d.data", isnap );
    plot_file = fopen(cfile, "w");

    for (j=0; j<ne; j++)
    {
	fprintf( plot_file, "%f	%f	%f	%f\n", vxe[j], vxi[j], xe[j], xi[j]);
    }

    if ( energic_particle == 1 )
    {
    for (j=0; j<ne_EP; j++)
    {
        fprintf( plot_file, "%f %f	%f	%f\n" , vx_EP[j], vx_EP[j], x_EP[j], x_EP[j]);
    }
    }

    if ( energic_particle == 2 )
    {
    for (j=0; j<ni_EP; j++)
    {
	fprintf( plot_file, "%f	%f	%f	%f\n" , vx_EP[j], vx_EP[j], x_EP[j], x_EP[j]);
    }
    }

    fclose(plot_file);

    isnap++;        	       /* increment snapshot counter */

}     

