/*****************************************
**					**
**	 Plot phi E v with time		**
**					**
******************************************/

#include "es.h"

FILE *plot_file;

void phiplots(void)
{
    char cfile[40];
    int i;


    sprintf(cfile,"phiet.data");

    plot_file = fopen(cfile,"w");

    for (i=0; i<=nt; i++)
    {
	fprintf(plot_file, "%d	%0.6e	%0.6e\n", i, phi_mid[i], Ex_mid[i]);
    }

    fclose(plot_file);


    sprintf(cfile,"ErrorPhi.data");

    plot_file = fopen(cfile,"w");

    for (i=0; i<=nt; i++)
    {
        fprintf(plot_file, "%d  %0.6e\n", i, error[i]);
    }

    fclose(plot_file);


    sprintf(cfile,"phiAt.data");

    plot_file = fopen(cfile,"w");

    for (i=0; i<=nt; i++)
    {
        fprintf(plot_file, "%0.6e	%0.6e	%0.6e	%0.6e	%0.6e	%0.6e	%0.6e	%0.6e	%0.6e	%0.6e\n", phiAt[0][i], phiAt[1][i], phiAt[2][i], phiAt[3][i], phiAt[4][i], phiAt[5][i], phiAt[6][i], phiAt[7][i], phiAt[8][i], phiAt[9][i]);
    }

    fclose(plot_file);


    sprintf(cfile,"wep.data");

    plot_file = fopen(cfile,"w");

    for (i=0; i<ne_EP; i++)
    {
	fprintf(plot_file, "%0.6e\n", w_EP[i]);
    }

    fclose(plot_file);



    sprintf(cfile,"Energy.data");

    plot_file = fopen(cfile,"w");

    if ( energic_particle != 0 )
    {    
	for (i=0; i<=nt; i++)
	{
            fprintf(plot_file, "%d  %0.6e	%0.6e	%0.6e	%0.6e	%0.6e\n", i, TotalEnergy[i], Energy_Pe[i], Energy_Pi[i], Energy_E[i], Energy_P_EP[i]);
	}
    }
    else
    {
	for (i=0; i<=nt; i++)
	{
	    fprintf(plot_file, "%d  %0.6e	%0.6e	%0.6e	%0.6e\n", i, TotalEnergy[i], Energy_Pe[i], Energy_Pi[i], Energy_E[i]);
	}
    }

    fclose(plot_file);


/*    sprintf(cfile,"xt.data");

    plot_file = fopen(cfile,"w");

    for (i=1; i<=nt; i++)
    {
        fprintf(plot_file, "%d  %0.6e	%0.6e	%0.6e	%0.6e	%0.6e\n", i, x_time[0][i], x_time[1][i], x_time[2][i], x_time[3][i], x_time[4][i]);
    }

    fclose(plot_file);


    if ( energic_particle != 0 )
    {
    sprintf(cfile,"xept.data");

    plot_file = fopen(cfile,"w");

    for (i=1; i<=nt; i++)
    {
        fprintf(plot_file, "%d  %0.6e      %0.6e      %0.6e      %0.6e      %0.6e\n", i, x_EP_time[0][i], x_EP_time[1][i], x_EP_time[2][i], x_EP_time[3][i], x_EP_time[4][i]);
    }

    fclose(plot_file);
    }
*/
}
