#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,check,length,i,j,check_4;
    char n_1[100];
    double **a;
    double *x,*b,*xp,*a_1;
    double a_s=0, delta=0, e, check_e, k;
    char e_1[100];

    /*double *xk, *xk1;
    double t, l1, l2, max, Axk = 0, eps;
    int k, count = 0;
    int compare(){
        max = abs(xk[0] - xk1[0]);
        for (i = 1; i < n; i++){
            if (abs(xk[i] - xk1[i]) > max)
            max = abs(xk[i] - xk1[i]);
        }
        if (max <= eps)
            return 1;
        else
            return 0;
    }*/

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

    i = 0;
    while(1){
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

        printf("e = %lf \n", e);

        if(check_4 == 1 && e > 0){
            break;
        }else{
            system("cls");
            printf("Try another value \n");
        }
    }

    /*a = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++)
        a[i] = (double*)malloc((n + 1)*sizeof(double));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter A[%d][%d] element: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    scanf("%lf %lf", &l1, &l2);

    xk = (double*)malloc(n*sizeof(double));
    xk1 = (double*)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        xk[i] = 1;
        xk1[i] = 0;
    }
    t = 2 / (l1 + l2);

    do{
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                Axk += a[i][j] * xk[j];
            }
        xk1[i] = xk[i] - t*(Axk - a[i][n]);
        Axk = 0;
        }
        for (k = 0; k < n; k++){
            xk[k] = xk1[k];
        }
        count++;
     } while (compare() == 0);

     for (i = 0; i < n; i++)
        printf("%.4lf \n", xk1[i]);*/





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

    for(i=0;i<n;i++){
        xp[i] = b[i] / a[i][i];
        printf("xp = %lf \n", xp[i]);
    }

    for(i=0;i<n;i++){
        a_s = 0;
        for(j=0;j<n;j++){
            if(j != i){
                a_s += a[i][j];
                printf("as = %lf \n", a_s);
            }
        }
        a_1[i] = a_s;
        printf("a1 = %lf \n", a_1[i]);
    }


    for(i=0;i<n;i++){
        do{
            x[i] = (b[i] - a_1[i]*xp[i]) / a[i][i];
            delta = abs(x[i] - xp[i]);
            xp[i] = x[i];
            printf("delta = %lf", delta);
        }while(delta > e);
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
