#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double k;
    double x;
    double d = 1;
    double y = 1;
    double a = 1;
    double b = 1;
    double e;

    scanf("%lf" , &x);
    scanf("%lf" , &k);
    scanf("%lf" , &e);

    //якщо числа п≥сл€ коми з заданою точн≥стб не зм≥нюютьс€ за ≥терац≥ю значить кор≥нь порахований до данноњ точност≥
    while(1){

        y = ((k-1) * y + x/pow(y,k-1) ) / k;

        b = a;

        a = round(y / e) * e;
        if(a == b){
            printf("%f \n", y);
            break;
        }

    }



    getch();
}
