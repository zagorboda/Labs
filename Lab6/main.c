#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,check,length,i,j,check_4, counter, stop, k, check_sum_1;
    char n_1[100];
    double **a;
    double *x,*b,*xp,*a_1;
    double a_s=0, delta, e, check_e, a0, check_sum=0;
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

        if(check == length && atoi(n_1) > 0){
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

    /*for(i=0;i<n;i++){
        printf("Enter B[%d] element: ", i);
        scanf("%lf", &b[i]);
    }*/

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

    /*for(i=0;i<n;i++){
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
                delta = fabs(x[i] - xp[i]);
                xp[i] = x[i];
                printf("i = \n %d", i);
                printf("x = %lf \n", x);
                printf("delta = %lf \n", delta);
            }while(delta > e);
    }printf("\n");
    for(i=0;i<n;i++){
        printf("%lf \n", x[i]);
    }*/



    /*for(i=0;i<n;i++){
        a_s = 0;
        for(j=0;j<n;j++){
            if(j != i){
                a_s += - 1 * a[i][j] / a[i][i];
                //printf("as = %lf \n", a_s);
            }
        }
        a_1[i] = a_s;
        //printf("a1 = %lf \n", a_1[i]);
    }

    for(i=0;i<n;i++){
        do{
            x[i] = b[i] / a[i][i]  + a_1[i]*xp[i];
            delta = fabs(xp[i] - x[i]);
            xp[i] = x[i];
        }while(delta > e);
    }*/

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

        //counter++;

    /*for(i = 0; i < n; i++){
        xp[i] = b[i] / a[i][i];
    }

    for(i=0;i<n;i++){
        a_s = 0;
        for(j=0;j<n;j++){
            if(j != i){
                a_s += a[i][j];
                //printf("as = %lf \n", a_s);
            }
        }
        a_1[i] = a_s;
        //printf("a1 = %lf \n", a_1[i]);
    }

    for(i=0;i<n;i++){
        for(j = 0; j < n; j++){
            xp[i] = xp[i] + (a[i][j] * x[j]);
        }
    }

    for(i = 0; i < n; i++){
        do{
            x[i] = (b[i] - xp[i]) / a[i][i];
            delta = fabs(xp[i] - x[i]);
            xp[i] = x[i];
        }while(delta > e);
    }

    for(i = 0; i < n; i++){
        printf("%lf", x[i]);
    }
    printf("Hello");*/
    //delta = 0;

    /*for(i = 0; i < n; i++){
        if(fabs(x[i] - xp[i]) > delta){
            delta = fabs(x[i] - xp[i]);
        }
        x[i] = xp[i];
    }*/

    /*if (counter>1000){
        printf(">>>This system can't be solved with this method!!!\n");
        stop = 0;
        }*/



    for ( i = 0; i < n; i++)
        free (a[i]);
    free (a);
    free (b);

    return 0;
}
