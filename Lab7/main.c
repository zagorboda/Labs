#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double c, double t){
    return (cos(t / c) - 2*sin(1/c) + 1/c);
}

double func2(double c, double t){
    return (sin(log(c))-cos(log(c))+t*log(c));
}

double derivative1(double c, double t){
    return ((t/c*c)*sin(t/c) + (2/c*c)*cos(1/c) - 1/c*c);
}

double second_derivative1(double c, double t){
    return ( -sin(log(c))/(c*c) + cos(log(c))/(c*c) - t/(c*c) + 1/c );
}

double derivative2(double c, double t){
    return ((-t*t/c*c*c*c)*cos(t/c) - (2/c*c*c*c)*sin(1/c) + 2/c*c*c);
}

double second_derivative2(double c, double t){
    return ( -sin(log(c))/(c*c) + cos(log(c))/(c*c) - t/(c*c) + 1/c );
}

/*double second_derivative2(double c, double t){
    return  (( (-sin(log(c)))/c + (cos(log(c)) - sin(log(c))) / c + 1 - t/c) / c );
}*/

int int_check(){
    char num[100];
    int i,check;
    while(1){
        check = 0;
        scanf("%s", &num);
            for (i = 0; i < strlen(num); i++){
                if (isdigit(num[i])){
                    check ++;
                }
                else
                    break;
            }

            if(check == strlen(num) && atoi(num) >= 0){
                return atoi(num);
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
                check ++;
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

    double delta, xp;

    switch(f){
        case 1:
            /*while(fabs(a2 - a1) > e){
                x = (a1 + a2) / 2;
                if(func1(x, t) == 0){
                    break;
                }
                if(func1(x,t) * func1(a1,t) > 0){
                    a1 = x;
                    printf("a = %lf \n", a1);
                }else{
                    a2 = x;
                    printf("b = %lf \n", a2);
                }
                printf("x = %lf \n\n", x);
            }*/



            if(func1(a1, t) * second_derivative1(a1, t) > 0)
                x = a1;
            if(func1(a2, t) * second_derivative1(a2, t) > 0)
                x = a2;
            //x = func2(a2, t);
            //printf("x1 = %lf \n", x);
            do{
                xp = x;
                x = xp - func1(xp, t) / derivative1(xp, t);
                printf("x = %lf \n", x);
            }while(fabs(x - xp) > e);//func2(a2, t) / derivative(a2, t) > e
            printf("x = %lf \n", x);

            break;
        case 2:
            if(func2(a1, t) * second_derivative2(a1, t) > 0)
                x = a1;
            if(func2(a2, t) * second_derivative2(a2, t) > 0)
                x = a2;
            //x = func2(a2, t);
            //printf("x1 = %lf \n", x);
            do{
                xp = x;

                x = xp - func2(xp, t) / derivative2(xp, t);
                printf("x = %lf \n", x);

                /*x = a2 - func2(a2, t) / derivative(a2, t);
                delta = func2(a2, t) - x;
                a2 = a2 - func2(a2, t) / derivative(a2, t);*/

                /*delta = func(a1+x, t) - func2(x, t);
                printf("delta = %lf \n", delta);
                x = x - delta;*/

                /*x = a2 - func2(a2, t) / derivative(a2, t);
                a2 = x;

                printf("x = %lf \n", x);
                printf("b = %lf \n", a2);*/



                /*x = (a1 + a2) / 2;
                if(func2(x, t) == 0){
                    break;
                }
                if(func2(x,t) * func2(a1,t) > 0){
                    a1 = x;
                    printf("a = %lf \n", a1);
                }else{
                    a2 = x;
                    printf("b = %lf \n", a2);
                }
                printf("x = %lf \n", x);*/
            }while(fabs(x - xp) > e);//func2(a2, t) / derivative(a2, t) > e
            printf("x = %lf \n", x);
            break;
    }

    printf("%lf \n", x);


    return 0;
}
