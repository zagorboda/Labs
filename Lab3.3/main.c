#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double x,y,y_1,y_2,y_3;
    double a,b,c,d,q,p,u,v,f,r;

    printf("Enter a: \n");
    scanf("%lf", &a);

    printf("Enter b: \n");
    scanf("%lf", &b);

    printf("Enter c: \n");
    scanf("%lf", &c);

    p = b - (pow(a,2) / 3);
    q = (2 * pow(a,3) / 27) - a * b / 3 + c;

    d = pow(p,3) / 27 + pow(q,2) / 4;
    //printf("%lf", d);

    if(d > 0){
        u = cbrt(-1 * q / 2 + sqrt(d));
        v = -1 * p /(3 * u);
        //printf("%lf", u);
        //printf("%lf", v);

        y_1 = u + v;
        //y_2 = -1*(u + v) / 2 + sqrt(-1) * sqrt(3) * (u - v) / 2;
        //y_3 = -1*(u + v) / 2 - sqrt(-1) * sqrt(3) * (u - v) / 2;

        printf("%lf", y_1 , "\n");
        printf("\n");
        printf("%lf", -1*(u + v) / 2);
        printf(" + i * ");
        printf("%lf", sqrt(3) * (u - v) / 2);
        printf("\n");
        printf("%lf", -1*(u + v) / 2);
        printf(" - i * ");
        printf("%lf", sqrt(3) * (u - v) / 2);
        printf("\n");

    }

    if( d == 0){
        printf("%lf", 3 * q / p);
        printf("%lf", -1 * 3 * q /(2 * p));
    }

    if(d < 0){
        r = sqrt(-1 * pow(p,3) / 27);
        f = acos(-1 * q /(2 * r));
        printf("%lf", 2 * abs(cbrt(r)) * cos(f/3));
        printf("\n");
        printf("%lf", 2 * abs(cbrt(r)) * cos((f + 2 * M_PI)/3));
        printf("%lf", 2 * abs(cbrt(r)) * cos((f + 4 * M_PI)/3));
    }

    return 0;
}
