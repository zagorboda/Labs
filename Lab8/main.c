#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct scheme{
        double r;
        double r1;
        double r2;
        double L;
        double C;
}S;

//struct scheme *p;

void calculate(func, f_min, f_max, d_f){
    while(f_min <= f_max){
        switch(func){
            case '1':
                printf("\t%lf - i*%lf \n", S.L/S.C, S.r/(S.C*2*M_PI*f_min));
                printf("Z = \t--------------------\n");
                printf("\t%lf + i*%lf\n", S.r, 2*M_PI*f_min*S.L - 1/(S.C*2*M_PI*f_min));
                printf("\n\n");
        }
        f_min += d_f;
    }
}

int main(){
    char func;
    int f_min, f_max, d_f;

    printf("Choose a scheme (1,2,3,4):\n");
    scanf("%c", &func);
    printf("Enter f_min: ");
    scanf("%d", &f_min);
    printf("Enter f_max: ");
    scanf("%d", &f_max);
    printf("Enter d_f: ");
    scanf("%d", &d_f);

    if(func == '1' || func == '2'){
        printf("Enter R: ");
        scanf("%lf", &S.r);
    }
    if(func == '3' || func == '4'){
        printf("Enter R1: ");
        scanf("%lf", &S.r1);
        printf("Enter R2: ");
        scanf("%lf", &S.r2);
    }

    printf("Enter L: ");
    scanf("%lf", &S.L);
    printf("Enter C: ");
    scanf("%lf", &S.C);

    /*sstruct scheme S = {r1, r2, L, Z};
    S.r1 = r1;
    S.r1 = r2;
    S.L = L;
    S.C = C;*/

    calculate(func, f_min, f_max, d_f);

    return 0;
}
