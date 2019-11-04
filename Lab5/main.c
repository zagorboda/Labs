#include <stdio.h>
#include <stdlib.h>

int main(){

    int m,n=100;
    char a[100];
    char b[100];
    int length_1, num_check;
    int i, j, num;
    char m_1[100];
    char n_1[100];
    int check;

    while(1){
        check = 0;
        printf("Enter m: ");
        scanf("%s", &m_1);
        length_1 = strlen(m_1);
        for (i = 0; i < length_1; i++)
            if (!isdigit(m_1[i])){
                continue;
            }
            else
                check += 1;

        if(check == length_1){
            m = atoi(m_1);
            break;
        }else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }

    }

    /*while(1){
        check = 0;
        printf("Enter n: ");
        scanf("%s", &n_1);
        length_1 = strlen(n_1);
        for (i = 0; i < length_1; i++)
            if (!isdigit(n_1[i])){
                continue;
            }
            else
                check += 1;

        if(check == length_1){
            n = atoi(n_1);
            break;
        }else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }

    }*/

    /*    char list[20];
    char *addr;

    scanf("%s", list);
    addr = &list;
    printf("%s", addr);*/

    char list[m][n];
    char *addr[m];
    char *c;

    for (i=0;i<m;i++){
        scanf("%s", list[i]);
    }

    for (i=0; i<m; i++)
        addr[i] = list[i];

    for (i=0;i<m;i++){
        printf("%s", addr[i]);
    }
    printf("\n");
    for(i = 0;i < m-1;i++){
        printf("Kurwa");
        for(j = i+1;j < m;j++){
            printf("BLET");
            if(addr[j-1] > addr[j]){
                c = addr[j-1];
                addr[j-1] = addr[j];
                addr[j] = c;
                printf("Fuck");
            }
        }
    }
    printf("\n");

    for (i=0;i<m;i++){
        printf("%s", addr[i]);
    }

    /*
    i = 0;
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            printf("Enter %d ", j+i+1);
            printf(" element in array: \n");
            scanf("%s", &a[j]);
        }
        b[i] = a;
        printf("Fuck b");
    }

    printf("%s", b);*/

    /*for(i=0;i<m;i++){
        printf("Hello");
        printf("%s", b[i]);
    }*/



    /*if(order[0] == '+'){
        for(i = 0;i < num-1;i++){
            for(j = i+1;j < num;j++){
                if(a[j-1] > a[j]){
                    c = a[j-1];
                    a[j-1] = a[j];
                    a[j] = c;
                }
            }
        }
    }else{
        for(i = 0;i < num-1;i++){
            for(j = i+1;j < num;j++){
                if(a[j-1] < a[j]){
                    c = a[j-1];
                    a[j-1] = a[j];
                    a[j] = c;
                }
            }
        }
    }*/

    return 0;
}
