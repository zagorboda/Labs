#include <stdio.h>
#include <stdlib.h>

int main(){

    int a;
    printf("Enter number: ");

    while(1){
        scanf("%u", &a);
        if(a < 0){
            printf("Try another value");
        }
        if(a >= 0){
            break;
        } /* Enter -1 then char -2 */
    }

    if(a == 0){
        putchar('0');
    }

    while (a >= 1000){
        putchar('M');
        a -= 1000;
    }

    while (a >= 500){
        putchar('D');
        a -= 500;
    }

    while (a >= 100){
        putchar('C');
        a -= 100;
    }

    while (a >= 50){
        putchar('L');
        a -= 50;
    }

    while (a >= 10){
        putchar('X');
        a -= 10;
    }

    while (a >= 5){
        putchar('V');
        a -= 5;
    }

    while (a >= 1){
        putchar('I');
        a -= 1;
    }

    getch();

    return 0;
}
