#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, check, length, i, j, check_4, k, check_sum_1;
    char n_1[100];
    double **a;
    double *x,*b,*xp;
    double delta, e, check_e, check_sum;
    char e_1[100];

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

        if(check == length && atoi(n_1) > 0){
            n = atoi(n_1);
            break;
        }else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }

    }

    while(1){
        printf("Enter e:");
        scanf("%s", &e_1);
        e = atof(e_1);
        length = strlen(e_1);
        for (i = 0; i < length; i++){
            j = e_1[i];
            if (j == 46 || isdigit(e_1[i])){
                check_e += 1;
            }
            else
                continue;
        }

        if(check_e == length){
            check_4 = 1;
        }

        if(check_4 == 1 && e >= 0){
            break;
        }else{
            system("cls");
            printf("Try another value \n");
        }
    }

    a = (double **) calloc (n, sizeof (double *));
    for ( i = 0; i < n; i++)
        a[i] = (double *) calloc (n, sizeof (double));

    b = (double *) calloc (n, sizeof (double));
    xp = (double *) calloc (n, sizeof (double));
    x = (double *) calloc (n, sizeof (double));

    while(1){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                while(1){
                    printf("Enter A[%d][%d] element: ", i, j);
                    scanf("%s", &e_1);
                    length = strlen(e_1);
                    check_e = 0;
                    for (k = 0; k < length; k++){
                        if (e_1[k] == 46 || e_1[k] == 45 || isdigit(e_1[k])){
                            check_e += 1;
                        }
                        else
                            continue;
                    }

                    if(check_e == length){
                        a[i][j] = atof(e_1);
                        break;
                    }else{
                        system("cls");
                        printf("Try another value \n");
                    }
                }
            }
        }

        check_sum_1 = 0;
        for(i=0;i<n;i++){
            check_sum = 0;
            for(j=0;j<n;j++){
                if(i != j)
                check_sum += a[i][j];
            }
            if(check_sum < a[i][i])
                check_sum_1 += 1;
        }
        if(check_sum_1 == n)
            break;
        else{
            system("cls");
            printf("For simple iteration method elements of main diagonal must be bigger than sum of elements of this row except element on main diagonal. Try another matrix \n");
        }

    }

    for(i=0;i<n;i++){
        while(1){
            printf("Enter B[%d] element: ", i);
            scanf("%s", &e_1);
            length = strlen(e_1);
            check_e = 0;
            for (k = 0; k < length; k++){
                if (e_1[k] == 46 || e_1[k] == 45 || isdigit(e_1[k])){
                    check_e += 1;
                }
                else
                    continue;
            }

            if(check_e == length){
                b[i] = atof(e_1);
                break;
            }else{
                system("cls");
                printf("Try another value \n");
            }
        }
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
    }

    do{
        for(i=0;i<n;i++){
            x[i]=0;
            delta = 0;
            for(j=0;j<n;j++){
                if(i!=j)
                    x[i]+=a[i][j]*xp[j];
            }
            x[i] = (b[i]-x[i]) / a[i][i];
            if(fabs(x[i] - xp[i]) > delta)
                delta = fabs(x[i] - xp[i]);

            xp[i] = x[i];
        }
    }while(delta > e);

    for(i=0;i<n;i++){
        printf("%lf \n", x[i]);
    }

    for ( i = 0; i < n; i++)
        free (a[i]);
    free (a);
    free (b);

    return 0;
}
