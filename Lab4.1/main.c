#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int d_x, n;
    double e, x, d, sin_x, cos_x, x_1, x_2;

    printf("Enter x_1: \n");
    scanf("%lf", &x_1);
    printf("Enter x_2: \n");
    scanf("%lf", &x_2);
    printf("Enter dx: \n");
    scanf("%d", &d_x);

    x_1 = x_1 * M_PI / 180;
    x_2 = x_2 * M_PI / 180;

    x = x_1;
    n = 1;
    d = 1;
    sin_x = 1;
    printf("%lf", x_1);
    printf("\n");
    printf("%lf", x_2);
    /*while(x != x_2){
        d = d * (-1 * pow(x,2) / ((n + 1) * (n + 2)));
        sin_x = sin_x * d;
        printf("Here");
    }*/
    printf("Sin(x) is %lf", sin_x);

    return 0;
}
