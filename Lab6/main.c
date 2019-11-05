#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,check,length,i,j;
    char n_1[100];
    double **a;
    double *x,*b,*xp,*a_1;
    double a_s=0;

    while(1){
        check = 0;
        printf("Enter n: ");
        scanf("%s", &n_1);
        length = strlen(n_1);
        for(i = 0; i < length; i++)
            if (!isdigit(n_1[i])){
                continue;
            }
            else
                check += 1;

        if(check == length){
            n = atoi(n_1);
            break;
        }else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }

    }

    a = (double **) calloc (n, sizeof (double *));
    for ( i = 0; i < n; i++)
        a[i] = (double *) calloc (n, sizeof (double));

    b = (double *) calloc (n, sizeof (double));
    xp = (double *) calloc (n, sizeof (double));
    x = (double *) calloc (n, sizeof (double));
    a_1 = (double *) calloc (n, sizeof (double));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter A[%d][%d] element: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for(i=0;i<n;i++){
        printf("Enter B[%d] element: ", i);
        scanf("%lf", &b[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%lf", a[i][j]);
        }
        printf(" = ");
        printf("%lf ", b[i]);
        printf("\n");
    }

    xp[0] = b[0] / a[0][0];

    /*for(i=0;i<n;i++){
        xp[i] = b[i] / a[i][i];
    }*/

    /*for(i=0;i<n;i++){
        a_s = 0;
        for(j=0;j<n;j++){
            if(j != i){
                a_s += a[i][j];
            }
        a_1[i] = a_s;
        }
    }*/

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j != i){
                x[i] = b[i] / a[i][i] - (a[i][j] * xp[j]) / a[i][i];
                xp[j+1] = x[i];
                /*x[i] = (b[i] - (a_1[j] * xp[j])) /a[i][j];
                xp[j+1] = x[i];*/
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%lf \n", x[i]);
    }



    for ( i = 0; i < n; i++)
        free (a[i]);
    free (a);
    free (b);

    return 0;
}
