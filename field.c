
/*************************************************
 **						**
 **      Field calculation - slab geometry	**
 **						**
 *************************************************/

#include "es.h"
#include "math.h"

extern void tdma(void);
extern void filtering(void);

void field(void)
{
    int j, x_midpoint;
    double particle_coefficient;

    /* Add neutral background to get net density */
 
    for (j=0; j<=nx; j++)
	rhot[j] = rho_all[j];

    /* Use tridiagonal matrix algorithm to solve Poisson equation and work out the potential from the density of charge */

    tdma();

    if ( filtering_switch != 0 )
	filtering();

    if ( perturbation_switch == 2 )
    {
/*	for (j=nx; j>71; j--)
	{
	    pphi[j] = pphi[j-22];
	    phi[j] = phi[j] + pphi[j];
	}
	for (j=0; j<29; j++)
	{
	    pphi[j] = pphi[j+22];
	    phi[j] = phi[j] + pphi[j];
	}

	for (j=29; j<=71; j++)
	{
	    pphi[j] = 0.5*sin(2.0*pi*(0.1*(j-50)+0.22*i_time));
	    phi[j] = phi[j] + pphi[j];
	}
*/
	if ( i_time%22 == 0 )
	{
	for (j=nx; j>0; j--)
	{
	    pphi[j] = pphi[j-1];
	    phi[j] = phi[j] + pphi[j];
	}
	pphi[0] = 0.1*sin(2.0*pi*0.22*i_time);
	phi[0] = phi[0] + pphi[0];
	}
	else
	{
	for (j=nx; j>=0; j--)
	    phi[j] = phi[j] + pphi[j];
	}
    }

    /* Field is calculated by central difference */

    Ex[0] = 0.5*( phi[nx-1] - phi[1] )/dx;

    for (j=1; j<=nx-1; j++)
        Ex[j] = 0.5*( phi[j-1] - phi[j+1] )/dx;

    Ex[nx] = Ex[0];
/*
    for (j=0; j<nx; j++)
	Ex[j] = ( phi[j] - phi[j+1] )/dx;

    Ex[nx] = ( phi[nx] - phi[1] )/dx;
*/

    /* Record E&phi at midgrid  */

    x_midpoint = nx/2;
    Ex_mid[i_time] = Ex[x_midpoint];
    phi_mid[i_time] = phi[x_midpoint];

    /* Record energy */
/*
    for ( j=0; j<nx; j++ )
	Energy_E[i_time] = Energy_E[i_time] + Ex[j]*Ex[j];
*/
    for (j=0; j<nx; j=j+2)
	Energy_E[i_time] = Energy_E[i_time] + 2.0*Ex[j]*Ex[j];
    for (j=1; j<nx; j=j+2)
	Energy_E[i_time] = Energy_E[i_time] + 4.0*Ex[j]*Ex[j];
    Energy_E[i_time] = Energy_E[i_time]*dx/6.0;

    particle_coefficient = (double) grid_length/ne;

    for ( j=0; j<ne; j++ )
	Energy_Pe[i_time] = Energy_Pe[i_time] + 0.5*vxe[j]*vxe[j];
    Energy_Pe[i_time] = Energy_Pe[i_time]*particle_coefficient;

    for ( j=0; j<ni; j++ )
	Energy_Pi[i_time] = Energy_Pi[i_time] + 918.0*vxi[j]*vxi[j];
    Energy_Pi[i_time] = Energy_Pi[i_time]*particle_coefficient;

    TotalEnergy[i_time] = 0.0*Energy_E[i_time] + Energy_Pe[i_time] + Energy_Pi[i_time];

    for ( j=0; j<5; j++)
	x_time[j][i_time] = xe[ni/10+j*ni/5+0];

    if ( energic_particle == 1 )
    {
        for ( j=0; j<5; j++)
            x_EP_time[j][i_time] = x_EP[ni_EP/10+j*ni_EP/5];

    for ( j=0; j<ne_EP; j++ )
        Energy_P_EP[i_time] = Energy_P_EP[i_time] + w_EP[j]*vx_EP[j]*vx_EP[j];
    }

    if ( energic_particle == 2 )
    {
	for ( j=0; j<5; j++)
	    x_EP_time[j][i_time] = x_EP[ni_EP/10+j*ni_EP/5];

    for ( j=0; j<ni_EP; j++ )
        Energy_P_EP[i_time] = Energy_P_EP[i_time] + vx_EP[j]*vx_EP[j];

    }

}

 
