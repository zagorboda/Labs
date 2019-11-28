#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(float c, float t){
    return (cos(t / c) - 2*sin(1/c) + 1/c);
}

double func2(float c, float t){
    return (sin(log(c) - cos(log(c)) + t*log(c)));
}

int main()
{

    double t, a1, a2, e, x, f_a, f_x;
    char f;

    printf("Enter function(1, 2):");
    scanf("%s", &f);
    printf("Enter t: ");
    scanf("%lf", &t);
    printf("Enter a1: ");
    scanf("%lf", &a1);
    printf("Enter a2: ");
    scanf("%lf", &a2);
    printf("Enter e: ");
    scanf("%lf", &e);

    switch(f){
        case '1':
            while(fabs(a2 - a1) > e){
                x = (a1 + a2) / 2;
                if(func1(x,t) * func1(a1,t) > 0){
                    a1 = x;
                    printf("a = %lf \n", a1);
                }else{
                    a2 = x;
                    printf("b = %lf \n", a2);
                }
                printf("x = %lf \n", x);
            }
            break;
        case '2':
            while(fabs(a2 - a1) > e){
                x = (a1 + a2) / 2;
                if(func2(x,t) * func2(a1,t) > 0){
                    a1 = x;
                    printf("a = %lf \n", a1);
                }else{
                    a2 = x;
                    printf("b = %lf \n", a2);
                }
                printf("x = %lf \n", x);
            }
            break;
    }

    printf("%lf \n", x);
    printf("Hello");

    return 0;
}
