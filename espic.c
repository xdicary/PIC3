/************************************************* 
**						**
**	      Electrostatic PIC code 		**
**						**
**	  1d1v,  slab geometry, C version	**
**						**
**************************************************/

#include "es.h"				/* common variables */

/*  external routines  */

extern void init(void);			/* initialisation */ 
extern void loadx(int, double[]);		/* particle loading - positions */
extern void loadv(int, double, double[]);		/* particle loading - velocities */
extern void loadx_EP(int, double[]);
extern void loadv_EP(int, double, double, double[]);
extern void density(void);		/* density gather */
extern void field(void);		/* Poisson solver */
extern void push(int, double[], double[], double[], double);			/* particle pusher */
extern void boundaries(int, double[], double[]);		/* particle boundary conditions */
extern void diagnostics(void);		/* diagnostic routine */
extern void phiplots(void);
extern void input(void);
extern void perturbation(void);
/*extern void filtering2(void);*/

FILE *history_file;			/* file for writing out time histories */            

int main() 
{

    int i;

    history_file = fopen("hist.data", "w");

    input();

    init();				/* do initialisation */

    loadx(ne, xe);
    loadx(ni, xi);				/* load particles onto grid */

    loadv(ne, vte, vxe);
    loadv(ni, vti, vxi);				/* define velocity distribution */

    if (energic_particle == 1)
    {
	loadx_EP(ne_EP, x_EP);
	loadv_EP(ne_EP, ve_EP, vte, vx_EP);
    }

    if (energic_particle == 2)
    {
	loadx_EP(ni_EP, x_EP);
	loadv_EP(ni_EP, vi_EP, vti, vx_EP);
    }

    density();				/* compute initial density from particles */

    perturbation();	

    field();				/* compute initial electric field */

    diagnostics();			/* output initial conditions */

 
    for (i_time=1; i_time<=nt; i_time++) 
    {

        push(ne, xe, Ex, vxe, q_over_me);				/* push particles */
	push(ni, xi, Ex, vxi, q_over_mi);

        boundaries(ne, xe, vxe);			/* particle boundary conditions */
	boundaries(ni, xi, vxi);

	if (energic_particle == 1)
	{
	    push(ne_EP, x_EP, Ex, vx_EP, q_over_me);
	    boundaries(ne_EP, x_EP, vx_EP);
	}

        if (energic_particle == 2)
        {
            push(ni_EP, x_EP, Ex, vx_EP, q_over_mi);
            boundaries(ni_EP, x_EP, vx_EP);
        }

        density();			/* compute density */

        field();			/* compute electric field (Poisson) */

        diagnostics();			/* output snapshots and time-histories */

    }

    phiplots();

/*    filtering2();*/

    close(history_file);          /*   close time-hist files */

}
