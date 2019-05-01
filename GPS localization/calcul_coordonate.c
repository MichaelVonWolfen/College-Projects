#include<stdio.h>
#include<stdlib.h>
#define p(x) (x * x)
int main()
{
    int i=0;
    double x1, x2, x3, y1, y2, y3, r1, r2, r3, x, y;
    double A, B, C, D, E, F;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2, &x3, &y3, &r3);
    C = p(r1) - p(r2) - p(x1) - p(y1) + p(x2) + p(y2);
    F = p(r2) - p(r3) - p(x2) - p(y2) + p(x3) + p(y3);
    A = 2*x2-2*x1;
    B = 2*y2-2*y1;
    D = 2*x3-2*x2;
    E = 2*y3-2*y2;
    y = C*D-F*A;
    y/= B*D-E*A;
    x = C*E-F*B;
    x/= A*E-D*B;
    printf("%lf %lf ", x, y);
    return 0;
}

