#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int k;
    double x;
    double d = 1;
    double y = 1;
    double a = 1;
    double b = 1;
    double e;


    //якщо числа п≥сл€ коми з заданою точн≥стб не зм≥нюютьс€ за ≥терац≥ю значить кор≥нь порахований до данноњ точност≥
    while(1){
        scanf("%lf" , &x);
        scanf("%d" , &k);
        scanf("%lf" , &e);
        if( ((k > 0) && ((k % 2 == 0 && x >= 0) || (k % 2 != 0))) || ((k < 0) && ((k % 2 == 0 && x > 0) || (k % 2 != 0 && x != 0))) ){
            while(1){
                //printf("FUCK");
                y = ((double)(k-1) * y + x/pow(y,((double)k) - 1) ) / (double)k;

                printf("y : %lf \n", y);

                b = a;
                printf("b : %lf \n", b);

                a = round(y / e) * e;
                printf("a : %lf \n", a);
                if(a == b){
                    printf("%f \n", y);
                    break;
                }
            }
            break;
        }else{
            printf("Try another value");
        }
    }
    getch();
}
