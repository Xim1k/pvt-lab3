#include <stdio.h>
#include <math.h>
#include "hpctimer.h"
const double eps = 1E-5;
const int n0 = 100000000;

double func (double x)
{
  return ((x*x*x*x)/(0.5*x*x + x + 6));
}

int main()
{
double t = hpctimer_getwtime();
const double a = 0.4;
const double b = 1.5;
int n = n0, k;
double sq[2], delta = 1;
for (k = 0; delta > eps; n *= 2, k ^= 1) {
double h = (b - a) / n;
double s = 0.0;
for (int i = 0; i < n; i++)
s += func(a + h * (i + 0.5));
sq[k] = s * h;
if (n > n0)
delta = fabs(sq[k] - sq[k ^ 1]) / 3.0;
}
t = hpctimer_getwtime() - t;
printf("Elapsed time (sec.): %.6f\n", t);
printf("Result Pi: %.12f; Runge rule: EPS %e, n %d\n", sq[k] * sq[k], eps, n / 2);
return 0;
}
