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


    //���� ����� ���� ���� � ������� �������� �� ��������� �� �������� ������� ����� ����������� �� ����� �������
    while(1){
        printf("Enter x: ");
        scanf("%lf" , &x);
        printf("Enter k: ");
        scanf("%d" , &k);
        printf("Enter e: ");
        scanf("%lf" , &e);

        if( (e > 0) && (((k > 0) && ((k % 2 == 0 && x >= 0) || (k % 2 != 0))) || ((k < 0) && ((k % 2 == 0 && x > 0) || (k % 2 != 0 && x != 0)))) ){
            while(1){
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
