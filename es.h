/*************************************************  
 **						**
 **			es.h			**
 **						**
 ** 	      Header file for espic.c 		**
 **    containing global arrays and variables	**
 ** 						**
 *************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
   
#define pi 3.14159265
#define exp 2.71828185
#define random_max 2147483647   /* max. allowed integer (32-bit) */
#define Q = 1.602e-19
#define Me = 9.109e-31
#define K = 1.381e-23
#define EPS0 = 8.854e-12

#define MaxParticle 500000
#define MaxEP 500000
#define MaxGrid 3000
#define MaxTime 100000
#define fftpoint 3000

/* particle arrays */ 

double xe[MaxParticle];
double vme[MaxParticle];
double vxe[MaxParticle];

double xi[MaxParticle];
double xmi[MaxParticle];
double vxi[MaxParticle];

double x_EP[MaxParticle];
double vx_EP[MaxEP];
double w_EP[MaxEP];

double x_time[5][MaxTime];
double x_EP_time[5][MaxTime];

/* grid arrays */

double rho_plasmae[MaxGrid];
double rho_plasmai[MaxGrid];
double rho_EP[MaxGrid];
double rho_all[MaxGrid];
double rhot[MaxGrid];
double Ex[MaxGrid];
double phi[MaxGrid];
double pphi[MaxGrid];

double phifft[fftpoint];

double Ex_mid[MaxTime];
double phi_mid[MaxTime];
double phiAt[10][MaxTime];

double Energy_E[MaxTime];
double Energy_Pe[MaxTime];
double Energy_Pi[MaxTime];
double Energy_P_EP[MaxTime];
double TotalEnergy[MaxTime];
double error[MaxTime];

/* plasma constants, parameters */

 double qe;                      /* macro-electron charge */
 double qi;
 double vte;                     /* thermal velocity */
 double vti;
 double q_over_me;               /* charge/mass ratio */
 double q_over_mi;
 double e_mass;                  /* macro-electron mass */
 double i_mass;
 double xload;                   /* plasma length */
 double plasma_start;            /* LH edge of plasma */
 double plasma_end;              /* RH edge of plasma */
 double wall_left;               /* LH particle boundary */
 double wall_right;              /* RH particle boundary */
 double rho0;                    /* background (ion) density */
 double grid_length;             /* grid length */
 double omega_p;                 /* plasma frequency */
 double lambda_d;                /* Debye-length */ 
 double weighting_EP;

 double ve_EP;
 double vi_EP;

 int ne, ni;                    /* # simulation electrons, ions */
 int ne_EP, ni_EP;

/* grid variables */

 int  nt;                       /* # timesteps */
 int  i_time;                   /* current timestep */
 double  dt;                     /* timestep */

 int fftsize;

 long  nx;                       /* # grid points */
 double  dx;                     /* mesh size */

 int  bc_particle;              /* particle boundary condition switch */
 int  bc_field;                 /* field boundary condition */

 int filtering_switch;
 int perturbation_switch;
 int energic_particle;

/* diagnostic parameters */
 
 int  iout;                     /* frequeny of printed output */
 int  igraph;                   /* frequeny of graphical output */
 int  ihist;                    /* frequeny of time-history output */

