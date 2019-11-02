#include <stdio.h>
#include "comp.h"

int main()
{
double r1, i1, r2, i2, rr, ir;
printf("\nEnter the first complex number: ");
scanf("%lf+%lfi", &r1, &i1);
printf("\nEnter the second complex number: ");
scanf("%lf+%lfi", &r2, &i2);
add(r1, i1, r2, i2, &rr, &ir);
printf("\nThe sum of the two complex numbers is: %lf+%lfi\n", rr, ir);
getchar();
return 0;
}

void add(double r1, double i1, double r2, double i2, double *rr, double *ir)
{
*rr = r1 + r2;
*ir = i1 + i2;
}
