#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    double d_x, e, x, d, sin_x, cos_x, cos_x_f, sin_x_f, x_1, x_2;
    char x_1_1[20] = "";
    char x_2_2[20] = "";
    char d_x_1[20] = "";
    char e_1[20] = "";
    int check_x_1 = 0;
    int check_1;
    int check_x_2 = 0;
    int check_2;
    int check_d_x = 0;
    int check_3;
    int check_e = 0;
    int check_4;
    int count_m = 0;
    int count_d = 0;
    int length;
    int i = 0;
    int j = 0;

    while(1){

        printf("Enter x_1:");
        scanf("%s", &x_1_1);
        x_1 = atof(x_1_1);
        length = strlen(x_1_1);
        for (i = 0; i < length; i++){
            j = x_1_1[i];
            if (j == 45 || j == 46 || isdigit(x_1_1[i])){
                check_x_1 += 1;
            }
            else
                continue;
        }

        if(check_x_1 == length){
            check_1 = 1;
        }


        printf("\n");

        printf("Enter x_2:");
        scanf("%s", &x_2_2);
        x_2 = atof(x_2_2);
        length = strlen(x_2_2);
        for (i = 0; i < length; i++){
            j = x_2_2[i];
            if (j == 45 || j == 46 || isdigit(x_2_2[i])){
                check_x_2 += 1;
            }
            else
                continue;
        }

        if(check_x_2 == length){
            check_2 = 1;
        }

        printf("\n");

        printf("Enter d_x:");
        scanf("%s", &d_x_1);
        d_x = atof(d_x_1);
        length = strlen(d_x_1);
        for (i = 0; i < length; i++){
            j = d_x_1[i];
            if (j == 45 || j == 46 || isdigit(d_x_1[i])){
                check_d_x += 1;
            }
            else
                continue;
        }

        if(check_d_x == length){
            check_3 = 1;
        }

        printf("\n");

        printf("Enter e:");
        scanf("%s", &e_1);
        e = atof(e_1);
        length = strlen(e_1);
        for (i = 0; i < length; i++){
            j = e_1[i];
            if (j == 45 || j == 46 || isdigit(e_1[i])){
                check_e += 1;
            }
            else
                continue;
        }

        if(check_e == length){
            check_4 = 1;
        }

        if(check_1 == 1 && check_1 == 1 && check_1 == 1 && check_4 == 1){
            break;
        }else{
            system("cls");
            printf("Try another value \n");
        }

    }
    x_1 = x_1 * M_PI / 180;
    x_2 = x_2 * M_PI / 180;
    d_x = d_x * M_PI / 180;

    x = x_1;
    n = 1;
    d    = 1;
    sin_x = 1;
    cos_x = 1;

    /*while(x < x_2){// коли зміна синуса менша за точність то все пораховано
        x = x + d_x;
        d = d * ((-1 * x * x) / ((n + 1) * (n + 2)));
        sin_x = sin_x + d;
        n = n + 2;
        sin_x_f = sin(x);
    }*/

    x = x_1;
    n = 1;
    d = 1;
    printf("X is");
    printf("        Cos x Taylor is");
    printf("        Cos(x) is");
    printf("        Cos x Taylor - cos(x)  is \n");
    while(x < x_2){
        x = x + d_x;
        d = d * (-1 * x * x / (2 * n * (2 * n - 1)));
        cos_x = cos_x + d;
        n = n + 1;
        cos_x_f = cos(x);
        printf("%lf", x * 180 / M_PI);
        printf("        %lf", round(cos_x/e)*e);
        printf("        %lf", round(cos_x_f/e)*e);
        printf("        %lf \n", fabs(cos_x - cos_x_f));
    }
    /*printf("Sin x is %lf \n", round(sin_x/e)*e);
    printf("Sin(x) is %lf \n", round(sin_x_f/e)*e);*/
    /*printf("Cos x is %lf \n", round(cos_x/e)*e);
    printf("Cos(x) is %lf \n", round(cos_x_f/e)*e);*/

    return 0;
}
