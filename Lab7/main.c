#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(float c, float t){
    return (cos(t / c) - 2*sin(1/c) + 1/c);
}

double func2(float c, float t){
    return (sin(log(c) - cos(log(c)) + t*log(c)));
}

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
    int i,check,minus,dot;

    while(1){
        dot = 0;
        check = 0;
        minus = 0;
        scanf("%s", &num);
        for (i = 0; i < strlen(num); i++){
            if ((num[i] == 45 || num[i] == 46 || isdigit(num[i])) && dot <=1 && minus <=1){
                check += 1;
                if(num[i] == 46)
                    dot++;
                if(num[i] == 45)
                    minus++;
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

int main()
{

    double t, a1, a2, e, x, f_a, f_x;
    int f;

    while(1){
        printf("Enter function(1, 2):");
        f = int_check();
        if(f == 1 || f == 2)
            break;
        else
            printf("Function number is incorrect. Try another one");
    }

    printf("Enter t: ");
    t = float_check();

    printf("Enter a1: ");
    a1 = float_check();

    printf("Enter a2: ");
    a2 = float_check();

    printf("Enter e: ");
    e = float_check();

    switch(f){
        case 1:
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
        case 2:
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

    return 0;
}
