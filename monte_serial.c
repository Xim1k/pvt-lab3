#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hpctimer.h"
const double PI = 3.14159265358979323846;
const int n = 100000000;

double func (double x, double y)
{
  return exp(x-y);
}

double getrand()
{ return (double)rand() / RAND_MAX; }

int main(int argc, char **argv)
{
double t = hpctimer_getwtime();
int in = 0;
double s = 0;
for (int i = 0; i < n; i++) {
double x = getrand() - 1;
double y = getrand();
if (y <= sin(x)) {
in++;
s += func(x, y);
}
}
double v = PI * in / n;
double res = v * s / in;
/* x in [0, pi] */
/* y in [0, sin(x)] */
printf("Result: %.12f, n %d\n", res, n);

t = hpctimer_getwtime() - t;
printf("Elapsed time (sec.): %.6f\n", t);
return 0;
}
