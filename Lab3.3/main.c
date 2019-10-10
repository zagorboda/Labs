#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double x,y,y_1,y_2,y_3;
    double a,b,c,d,q,p,u,v,f,r;
    char a_1[100] = "";
    char b_1[100] = "";
    char c_1[100] = "";
    int i,j;
    int a_check = 0;
    int b_check = 0;
    int c_check = 0;
    int a_check_1;
    int b_check_1;
    int c_check_1;
    int a_count_m = 0;
    int a_count_d = 0;

    while(1){
        printf("Enter a: \n");
        scanf("%s", &a_1);
        a = atof(a_1);
        printf("a = %lf", a);
        int length_1 = strlen(a_1);
        for (i = 0; i < length_1; i++){
                j = a_1[i];
                if (j == 45 || j == 46 || isdigit(a_1[i])){
                    a_check += 1;
                }
                else
                    continue;
        }

        if(a_check == length_1){
            a_check_1 = 1;
        }


        printf("Enter b: \n");
        scanf("%s", &b_1);
        b = atof(b_1);
        printf("b = %lf", b);
        int length_2 = strlen(b_1);
        for (i = 0; i < length_2; i++){
                j = b_1[i];
                if (j == 45 || j == 46 || isdigit(b_1[i])){
                    b_check += 1;
                }
                else
                    continue;
        }

        if(b_check == length_1){
            b_check_1 = 1;
        }

        printf("Enter c: \n");
        scanf("%s", &c_1);
        c = atof(c_1);
        printf("c = %lf", c);
        int length_3 = strlen(c_1);
        for (i = 0; i < length_3; i++){
                j = c_1[i];
                if (j == 45 || j == 46 || isdigit(c_1[i])){
                    c_check += 1;
                }
                else
                    continue;
        }

        if(c_check == length_1){
            c_check_1 = 1;
        }

        if(a_check_1 == 1 || b_check_1 == 1 || c_check_1 == 1){
            break;
        }else{
            //system("cls");
            printf("Try another value \n");
        }
    }

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
