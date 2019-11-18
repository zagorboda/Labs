#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double t, a1, a2, e, x, f_a, f_x;

    printf("Enter t: ");
    scanf("%lf", &t);
    printf("Enter a1: ");
    scanf("%lf", &a1);
    printf("Enter a2: ");
    scanf("%lf", &a2);
    printf("Enter e: ");
    scanf("%lf", &e);

    double calculate(float c){
        return (cos(t / c) - 2*sin(1/c) + 1/c);
    }

    while(fabs(a2 - a1) > e){
        printf("Itterate \n");
        x = (a1 + a2) / 2;
        /*f_x = cos(t / x) - 2*sin(1 / x) + 1 / x;
        f_a = cos(t / a) - 2*sin(1 / a) + 1 / a;*/
        if(calculate(x) * calculate(a1) > 0){
            a1 = x;
            printf("a = %lf \n", a1);
        }else{
            a2 = x;
            printf("b = %lf \n", a2);
        }
        printf("x = %lf \n", x);
        if(calculate(x) == 0)
            break;
    }

    printf("%lf \n", x);
    printf("Hello");

    return 0;
}
