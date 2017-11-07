#include "es.h"
#include "fftw3.h"
#include "math.h"

FILE *plot_file;

void filtering2(void)
{
fftw_complex *in, *out;
fftw_plan p;
char cfile[40];
int i;

in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fftsize);
out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fftsize);
p = fftw_plan_dft_1d(fftsize, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

for(i=0, i<1024, i++)
{
in[i][0] = sin(pi/512*i);
in[i][1] = 0.0;
out[i][0] = 0.0;
out[i][1] = 0.0;
}

fftw_execute(p);

sprintf(cfile,"test.data");
plot_file = fopen(cfile,"w");
for (i=0; i<1024; i++)
{
fprintf(plot_file, "%d	%f	%f	%f	%f\n", i, in[i][0], in[i][1], out[i][0], out[i][1]);
}

fftw_destroy_plan(p);
fftw_free(in); fftw_free(out);
}
