#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // For directories
//#include <sys/stat.h> //
#include <string.h> // To append string strncat()
//В сі немає файлів , але є потоки


int int_check();
double float_check();
void test();
void create_file();
void read_file();
void write_file();
void delete_record();
void delete_file();
void edit_record();
void sort_records();

struct record{
    double square[1000];
    int population[1000];
}record;

int int_check(){
    char num[100];
    int i,check;
    while(1){
        check = 0;
        scanf("%s", &num);
            for (i = 0; i < strlen(num); i++){
                if (isdigit(num[i])){
                    check += 1;
                }
                else
                    break;
            }

            if(check == strlen(num) && atoi(num) >= 0){
                return atoi(num);
                break;
            }else{
                printf("Incorrect input. Try another value \n");
            }
    }
}

double float_check(){
    char num[100];
    int i,check,dot,minus;

    while(1){
        dot = 0;
        check = 0;
        minus = 0;
        scanf("%s", &num);
        for (i = 0; i < strlen(num); i++){
            if ((num[i] == 46 || num[i] == 45 || isdigit(num[i])) && dot <=1 && minus <= 1 ){
                check += 1;
                if(num[i] == 46)
                    dot += 1;
                if(num[i] == 45)
                    minus += 1;
            }
            else
                break;
        }

        if(check == strlen(num)){
            return atof(num);
            break;
        }else{
            printf("Incorrect input. Try  another value \n");
        }
    }
}

void sort_records(){
    char name[260];
    FILE *fp;
    char line[1000];
    int i=0;
    char list[100][100];
    char *addr[100];

    printf("Enter name of the file to open it. All files in your directory:\n");

    struct dirent *de;  // Pointer for directory entry
    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");
    if (dr == NULL) { // opendir returns NULL if couldn't open directory
        printf("Could not open current directory" );
    }else{
        // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html  for readdir()
        while ((de = readdir(dr)) != NULL){
                //printf("%s\n", de->d_name); для виводу всіх файлів
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    printf("%s\n", de->d_name);
                }
        }
        closedir(dr);

        while(1){
            scanf("%s", &name);
            strncat(name, ".txt", 4);
            if ((fp = fopen(name, "r+")) == NULL){
                printf("Can't open file.Try another name of file:\n");
            }else{
                break;
            }
        }

        i=0;
        while ( fgets ( line, sizeof line, fp ) != NULL ){
            strcpy(list[i], line);
            i++;
        }

        int j = 0, number = i;
        for(i=0;i<number;i += 2){
            record.square[j] = atof(list[i]);
            record.population[j] = atoi(list[i+1]);
            j++;
        }

        printf("\n Number == %d\n", number);
        j=0;

        double c;
        int d;
        int sort_operator;
        sort_operator = int_check();
        for (i = 0; i < number/2; i++){
            for (j = i + 1; j < number/2; j++){
                if(sort_operator == 1){
                    if (record.square[i] > record.square[j]){
                        c =  record.square[i];
                        record.square[i] = record.square[j];
                        record.square[j] = c;
                        d =  record.population[i];
                        record.population[i] = record.population[j];
                        record.population[j] = d;
                    }
                }
                if(sort_operator == 2){
                    if (record.population[i] > record.population[j]){
                        c =  record.square[i];
                        record.square[i] = record.square[j];
                        record.square[j] = c;
                        d =  record.population[i];
                        record.population[i] = record.population[j];
                        record.population[j] = d;
                    }
                }
            }
        }

        fclose(fp);

        for(i=0;i < number/2;i++){
            printf("\n%d.\n", i + 1);
            printf("%lf\n", record.square[i]);
            printf("%d\n", record.population[i]);
        }

        while(1){
            if ((fp = fopen(name, "w")) == NULL){
                printf("Some problems occurred while operating file:\n");
            }else{
                break;
            }
        }

        for(i=0;i < number/2;i++){
            fprintf(fp, "%lf\n", record.square[i]);
            fprintf(fp, "%d\n", record.population[i]);
        }

        fclose(fp);
    }
}

int main(){
    //system("chcp 1251"); //Підтримка кирилиці
    int action;

    printf("Enter action:\n");
    printf("1.Create new file\n");
    printf("2.Read data from file\n");
    printf("3.Write data to file\n");
    printf("4.Delete records from file\n");
    printf("5.Delete file\n");
    printf("6.Edit record\n");
    printf("7.Sort records\n");
    action = int_check();
    switch(action){
        case 7:
            system("cls");
            sort_records();
    }

    getch();
    return 0;
}

void sort(char **a,char **b){
	char *c;
	c=*a;
	*a=*b;
	*b=c;
}
