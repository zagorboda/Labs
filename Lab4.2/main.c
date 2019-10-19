#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a[100];
    int i,j,c,num;

    printf("Enter number: ");
    scanf("%d", &num);
    for(i = 0;i < num;i++){
        printf("Enter numbers:");
        scanf("%lf", &a[i]);
    }

    for(i = 0;i < num;i++){
        for(j = 1;j < num + 1;j++){
            if(a[j-1] > a[j]){
                c = a[j-1];
                a[j-1] = a[j];
                a[j] = c;
            }
        }
    }

    for(i = 1;i < num+1;i++)
        printf("%lf \n", a[i]);

    return 0;
}
