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

int int_check(){
    char num[100];
    int i,check;
    while(1){
        check = 0;
        scanf("%s", &num);
            for (i = 0; i < strlen(num); i++){
                if (isdigit(num[i])){
                    check += 1;
                }
                else
                    break;
            }

            if(check == strlen(num) && atoi(num) >= 0){
                return atoi(num);
                break;
            }else{
                printf("Incorrect input. Try another value \n");
            }
    }
}

double float_check(){
    char num[100];
    int i,check,dot;

    while(1){
        dot = 0;
        check = 0;
        scanf("%s", &num);
        for (i = 0; i < strlen(num); i++){
            if ((num[i] == 46 || isdigit(num[i])) && dot <=1 ){
                check += 1;
                if(num[i] == 46)
                    dot += 1;
                printf("%c \n", num[i]);
            }
            else
                break;
        }

        if(check == strlen(num)){
            return atof(num);
            break;
        }else{
            printf("Incorrect input. Try another value \n");
        }
    }
}

//struct scheme *p;

void calculate(func, f_min, f_max, d_f){
    printf("f_0 = %lf\n\n", 1/(2*M_PI*sqrt(S.L*S.C)));
    while(f_min <= f_max){
        switch(func){
            case 1:
                printf("f = %d \n\n", f_min);
                printf("\t%lf - i*%lf \n", S.L/S.C, S.r/(S.C*2*M_PI*f_min));
                printf("Z (%d) = --------------------\n", f_min);
                printf("\t%lf + i*%lf\n", S.r, 2*M_PI*f_min*S.L - 1/(S.C*2*M_PI*f_min));
                printf("\n\n");
                break;

            case 2:
                printf("f = %d \n\n", f_min);
                printf("\t%lf + i*%lf \n", S.L/S.C, S.r/(S.C*2*M_PI*f_min));
                printf("Z (%d) = --------------------\n", f_min);
                printf("\t%lf + i*%lf\n", S.r, 2*M_PI*f_min*S.L - 1/(S.C*2*M_PI*f_min));
                printf("\n\n");
                break;

            case 3:
                printf("f = %d \n\n", f_min);
                printf("\t%lf + i*%lf \n", S.r1*S.r2, S.r1*(2*M_PI*f_min*S.L - 1/S.C*2*M_PI*f_min));
                printf("Z (%d) = --------------------\n", f_min);
                printf("\t%lf + i*%lf\n", S.r1 + S.r2, 2*M_PI*f_min*S.L - 1/(S.C*2*M_PI*f_min));
                printf("\n\n");
                break;

            case 4:
                printf("f = %d \n\n", f_min);
                printf("\t%lf + i*%lf \n", S.r1*S.r2 + S.L/S.C, (2*M_PI*f_min*S.L*S.r1 - S.r2/S.C*2*M_PI*f_min));
                printf("Z (%d) = --------------------\n", f_min);
                printf("\t%lf + i*%lf\n", S.r1 + S.r2, 2*M_PI*f_min*S.L - 1/(S.C*2*M_PI*f_min));
                printf("\n\n");
                break;
        }
        f_min += d_f;
    }
}

int main(){
    int func,f_min, f_max, d_f;

    while(1){
        printf("Choose scheme(1,2,3,4):\n");
        func = int_check();
        if(func == 1 || func == 2 || func == 3 || func == 4)
            break;
        else
            printf("Scheme not found. Try another one.");
    }

    printf("Enter f_min: ");
    f_min = int_check();

    printf("Enter f_max: ");
    f_max = int_check();

    printf("Enter d_f: ");
    d_f = int_check();

    if(func == 1 || func == 2){
        printf("Enter R: ");
        S.r = float_check();
    }
    if(func == 3 || func == 4){
        printf("Enter R1: ");
        S.r1 = float_check();
        printf("Enter R2: ");
        S.r2 = float_check();
    }

    printf("Enter L: ");
    S.L = float_check();
    printf("Enter C: ");
    S.C = float_check();

    /*sstruct scheme S = {r1, r2, L, Z};
    S.r1 = r1;
    S.r1 = r2;
    S.L = L;
    S.C = C;*/

    calculate(func, f_min, f_max, d_f);

    getch();

    return 0;
}
