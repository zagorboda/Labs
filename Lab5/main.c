#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void sort(char **a,char **b);

int main(){
    int m,n;
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

    while(1){
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

    }

    char list[m][n];
    char *addr[m];
    char *c;

    for (i=0;i<=m;i++){
        fgets (list[i], n, stdin);
    }

    for (i=1; i<=m; i++)
        addr[i] = list[i];

    for (i=1;i<=m;i++){
        printf("List[%d] = %s \n", i, addr[i]);
    }
    printf("\n");

    for (i=1;i<m;i++){
        for(j = i+1;j <= m;j++){
            if(strcmp(addr[i], addr[j]) > 0){
                sort(&addr[i],&addr[j]);
            }
        }
    }

    printf("\n");

    for (i=1;i<=m;i++){
        printf("List[%d] = %s \n", i, addr[i]);
    }

    return 0;
}

void sort(char **a,char **b){
	char *c;
	c=*a;
	*a=*b;
	*b=c;
}
