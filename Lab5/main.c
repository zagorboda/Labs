#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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

    char list[m][n];
    char *addr[m];
    char *c;

    for (i=0;i<m;i++){
        scanf("%s", list[i]);
    }

    for (i=0; i<m; i++)
        addr[i] = list[i];

    for (i=0;i<m;i++){
        printf("List[%d] = %s \n", i, addr[i]);
    }
    printf("\n");

    for(i = 0;i < m-1;i++){
        for(j = i+1;j < m;j++){
            if(strcmp(addr[j-1], addr[j]) > 0){
                c = addr[j-1];
                addr[j-1] = addr[j];
                addr[j] = c;
            }
        }
    }
    printf("\n");

    for (i=0;i<m;i++){
        printf("List[%d] = %s \n", i, addr[i]);
    }

    return 0;
}
