/*********************************************************
 **							**
 **			 init.c				**
 **							**
 **     initialise main particle and grid variables	**
 **							**
 *********************************************************/


#include <stdio.h>
#include <math.h>
#include "es.h"

void init(void)
{

    /* local variables */

    int i;

    int necell, nicell, epcell;
    double xdodx;

    i_time = 0;		 	/* initialise time counter */


    /* derived parameters */

    dx = grid_length/nx;	/* mesh size */

    omega_p = sqrt(rho0);	/* plasma frequency */

    lambda_d = vte/omega_p;	/* Debye length */

    q_over_mi = q_over_me/1836.0;

    xdodx = lambda_d/dx;	/* ratio */

    necell = ne/nx;
    nicell = ni/nx;		/* # particles per cell */

    epcell = ni_EP/nx;

    for (i=0; i<=nx; i++)
	pphi[i] = 0.0;

    for ( i=0; i<=nt; i++ )
    {
	Energy_Pe[i] = 0.0;
	Energy_Pi[i] = 0.0;
	Energy_E[i] = 0.0;
	Energy_P_EP[i] = 0.0;
	TotalEnergy[i] = 0.0;
    }

    /* printf("time: %f, x: %f, y: %f\n", time, x, y); */  

    printf("\n Input parameters: \n\n");
    printf("# mesh points = %d\n", nx);
    printf("# plasma electrons = %d\n", ne);
    printf("# plasma electrons/cell = %d\n", necell);
    printf("# plasma ions = %d\n", ni);
    printf("# plasma ions/cell = %d\n", nicell);


    if (energic_particle != 0)
    {
	printf("# EP = %d\n", ni_EP);
	printf("# EP/cell = %d\n", epcell);
    }

    printf("grid length = %f\n\n", grid_length);
    printf("\nelectronic thermal velocity = %f",vte);
    printf("\nionic thermal velocity = %f",vti);
    printf("\nmesh size = %f\n",dx);
    printf("Debye length = %f\n\n",lambda_d);

    printf("timestep = %f\n",dt);
    printf("# timesteps = %d\n", nt);
    printf("run time = %f\n",dt*nt);

    dt = dt*2*pi;

}
