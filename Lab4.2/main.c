#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a[100];
    int length_1;
    double c;
    int i = 0,j,num;
    char num_1[100] = "";
    char a_1[100] = "";
    char order[1] = "";
    int num_check = 0, a_check = 1, k =0, iter_count =0;

    while(1){
        printf("Enter order: ");
        scanf("%s", &order);
        if(order[0] == '+' || order[0] == '-'){
            break;
        }else{
            system("cls");
            fflush(stdout);
            printf("Incorrect input. Try another values. \n");
        }
    }

    while(1){
        num_check = 0;
        printf("Enter number: ");
        scanf("%s", &num_1);
        length_1 = strlen(num_1);
        for (i = 0; i < length_1; i++)
            if (!isdigit(num_1[i])){
                continue;
            }
            else
                num_check += 1;

        if(num_check == length_1){
            num = atoi(num_1);
            break;
        }else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }

    }

    i = 0;
    while(1){
        a_check = 1;
        printf("Enter %d ", i+1);
        printf(" number in array: \n");
        scanf("%s", a_1);
        int length_1 = strlen(a_1);
        for (k = 0; k < length_1-1; k++){
                j = a_1[k];
                if (j == 45 || j == 46 || isdigit(a_1[k])){
                    a_check += 1;
                }
                else
                    break;
        }

        if(a_check == length_1){
            a[i] = atof(a_1);
            iter_count++;
            i++;
        }else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }
        if(iter_count == num){
            break;
        }
    }

    if(order[0] == '+'){
        for (i = 0; i < num; ++i){
            for (j = i + 1; j < num; ++j){
                if (a[i] > a[j]){
                    c =  a[i];
                    a[i] = a[j];
                    a[j] = c;
                }
            }
        }
    }else{
        for (i = 0; i < num; ++i){
            for (j = i + 1; j < num; ++j){
                if (a[i] < a[j]){
                    c =  a[j];
                    a[j] = a[i];
                    a[i] = c;
                }
            }
        }
    }

    for(i = 0;i < num;i++)
        printf("%lf \n", a[i]);

    return 0;
}
