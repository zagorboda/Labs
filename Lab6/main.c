#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,check,length,i,j;
    char n_1[100];
    double **a,**x,**b,**xp;

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

    b = (double **) calloc (n, sizeof (double *));
    for ( i = 0; i < n; i++)
        b[i] = (double *) calloc (n, sizeof (double));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter A[%d][%d] element: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for(i=0;i<n;i++){
        printf("Enter B[%d] element: ", i);
        scanf("%lf", &b[i][0]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%lf ", a[i][j]);
        }
        printf(" = ");
        printf("%lf ", b[i][0]);
        printf("\n");
    }

    /*for(i=0;i<n;i++){
        printf("%lf", b[i][0]);
    }*/

    /*int i, j, n, a, b;

    int ( * ( * p ) [] ) [];

    printf ( "\n\tEnter the size of the matrix in the form aXb\t\n" );

    scanf ( "%d", &a);

    p = malloc ( a * sizeof ( int ( * ) [] ) );

    for ( i = 0;i < a;i++ ) {
        (*p)[i] = malloc (a * sizeof(int));
        printf ( "\t\bEnter Column %d\t\n", i );
        for ( j = 0;j < a;j++ )
            scanf ( "%d", & ( * ( *p ) [i] ) [j] );
    }*/




    /*int n;
    scanf("%d", &n);
    int **sArray;
    sArray = (int **)malloc(n * sizeof(int *));

    int i,j;
    for(i = 0; i < n; i++)
    {
        sArray[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &sArray[i][1], &sArray[i][2]);
    }*/

    return 0;
}
