#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int day;
    int year = 0;
    int month = 0;
    int date = 0;
    int n;
    char year_1[4] = "";
    char month_1[2] = "";
    char date_1[2] = "";
    int i;
    int d_check;
    int m_check;
    int y_check;

    while(1){

        printf("Enter day: ");
        scanf("%s", &date_1);
        date = atoi(date_1);
        printf("%d", date);
        int length_1 = strlen(date_1);
        for (i = 0; i < length_1; i++)
            if (!isdigit(date_1[i])){
                d_check = 0;
                break;
            }
            else
                d_check = 1;

        printf("\nEnter month: ");
        scanf("%s", &month_1);
        month = atoi(month_1);
        printf("%d", month);
        int length_2 = strlen(month_1);
        for (i = 0; i < length_2; i++)
            if (!isdigit(month_1[i])){
                m_check = 0;
                break;
            }
            else
                m_check = 1;

        printf("\nEnter year: ");
        scanf("%s", &year_1);
        year = atoi(year_1);
        printf("%d \n", year);
        int length_3 = strlen(year_1);
        for (i = 0; i < length_3; i++)
            if (!isdigit(year_1[i])){
                y_check = 0;
                break;
            }
            else
                y_check = 1;

        if (y_check && m_check && d_check)
            if(year > 0 && (month >= 1 && month <= 12 && date >= 1 && date <= 31))
                if(((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (date <= 31)) || ((month == 4 || month == 6 || month == 9 || month == 7 || month == 11) && (date <= 30)) || (year % 100 != 0 && year % 4 == 0 && month == 2 && date <= 29) || (year % 100 == 0 || year % 4 != 0 && month == 2 && date <= 28))
                    break;
        else{
            system("cls");
            printf("Incorrect input. Try another values. \n");
        }
    }


    if(month > 2)
        n = 0;
    if(month <= 2 && year % 100 != 0 && year % 4 == 0)
        n = 1;
    if(month <= 2 && (year % 100 == 0 || year % 4 != 0))
        n = 2;

    day = ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7 + 1;

    switch(day){
        case(1):
            printf("Monday(1)");
            break;
        case(2):
            printf("Tuesday(2)");
            break;
        case(3):
            printf("Wednesday(3)");
            break;
        case(4):
            printf("Thursday(4)");
            break;
        case(5):
            printf("Friday(5)");
            break;
        case(6):
            printf("Saturday(6)");
            break;
        case(7):
            printf("Sunday(7)");
            break;
    }

    return 0;
}
