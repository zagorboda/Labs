#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // For directories
//#include <sys/stat.h> //
#include <string.h> // To append string strncat()
//� � ���� ����� , ��� � ������


int int_check();
double float_check();
void test();
void create_file();
void read_file();
void write_file();
void delete_record();


struct record{
    char *name[1000][260];
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
            printf("Incorrect input. Try another value \n");
        }
    }
}

void test(){
    FILE *fp;
    int MAXCHAR = 1000;
    char *str[3][MAXCHAR];
    char *text[3];
    char name[260];
    int i;
    printf("Enter file name:\n");
    scanf("%s", &name);
    strncat(name, ".txt", 4);

    if ((fp = fopen(name, "r")) == NULL){
        printf("Can't open file.");
    }else{
        i = 0;
        do{
            fscanf(fp,"%[^\n]", str[i]);
            text[i] = str[i];
            printf("%s\n", text[i]);
            i++;
        }while(fgets(str, MAXCHAR, fp) != NULL);
        /*for(i=0;i<=2;i++){
            text[i] = str[i+1];
            printf("%s\n", text[i]);
        }*/
    }
}

void create_file(){
    FILE *fp;
    char name[260];
    char **arrays;
    char list[100][100];
    char *addr[100];
    int overwrite;
    int file_exists = 0;

    printf("Enter file name:\n");
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL) {
        printf("Could not open current directory" );
    }else{
        // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html  for readdir()
        int i=0;
        while ((de = readdir(dr)) != NULL){
                //printf("%s\n", de->d_name); ��� ������ ��� �����
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    strcpy(list[i], de->d_name);
                    addr[i] = list[i];
                    //fputs(addr[i], stdout);
                    i++;
                }
        }
        scanf("%s", &name);
        int j;
        for(j=0;j<i;j++){
            if(strcmp(name, addr[j]) == 0){
                file_exists = 1;
                printf("This file already exists.Do you want to overwrite it(1 - yes, 2 - no)");
                while(1){
                    overwrite = int_check();
                    if(overwrite == 1 || overwrite == 2){
                        if(overwrite == 2){
                                system("cls");
                            create_file();
                        }
                        break;
                    }else{
                        printf("Enter correct value(1 - yes, 2 -no)");
                    }
                }
            }
        }
        closedir(dr);
    }
    strncat(name, ".txt", 4);
    if(file_exists == 0 || overwrite == 1){
        if ((fp = fopen(name, "w")) == NULL){
            printf("Some problems occurred. Can't create file");
            getch();
        }else{
            printf("File %s successfully created", name);
            getch();
        }
    }

    system("cls");
    main();
}

void read_file(){
    FILE *fp;
    int MAXCHAR = 1000;
    char str[253];
    char name[260];
    char line [ 128 ];
    int i = 0;

    while(1){
        printf("Enter file name:\n");
        scanf("%s", &name);
        strncat(name, ".txt", 4);
        if ((fp = fopen(name, "r")) == NULL){
            printf("Can't open file.");
        }else{
            break;
        }
    }

    while ( fgets ( line, sizeof line, fp ) != NULL ){
        if(i % 3 == 0)
            printf("\n%d.\n", i/3 + 1);
        fputs ( line, stdout );
        i++;
    }

    printf("\nTo open main menu press any button");
    getch();
    system("cls");
    main();
}

void write_file(){
    char name[260];
    FILE *fp;
    int MAXCHAR = 1000;
    char str[MAXCHAR];

    printf("Enter name of the file to open it. All files in your directory:\n");

    struct dirent *de;  // Pointer for directory entry
    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");
    if (dr == NULL) { // opendir returns NULL if couldn't open directory
        printf("Could not open current directory" );
    }else{
        // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html  for readdir()
        while ((de = readdir(dr)) != NULL){
                //printf("%s\n", de->d_name); ��� ������ ��� �����
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    printf("%s\n", de->d_name);
                }
        }
        closedir(dr);

        scanf("%s", &name);
        strncat(name, ".txt", 4);
        if ((fp = fopen(name, "w")) == NULL){
            printf("Can't open file.\n");
        }else{
            getchar(); // ϳ��� scanf ���������� ������ ���� ���� \n ����������� � ��������� fgets, ���� ������ �����������.
            // getchar �������� ��� ������ .
            int i = 0;
            while(1){
                printf("Enter region name:\n");
                fgets(record.name[i], 1000, stdin);
                printf("Enter region square :\n");
                record.square[i] = float_check();
                printf("Enter region population:\n");
                record.population[i] = int_check();

                fprintf(fp, record.name[i]);
                fprintf(fp, "%lf\n", record.square[i]);
                fprintf(fp, "%d\n", record.population[i]);
                printf("Record number %d is written to file. Press any key to continue or 'ESC' button to finish reading data.\n", i+1);
                i++;
                if(getch() == 27)
                    break;
                getchar();
            }
            fclose(fp);
        }

        /*if ((fp = fopen(name, "r")) == NULL){
            printf("Can't open file.");
        }else{
            while (fgets(str, MAXCHAR, fp) != NULL)
            printf("%s", str);
        }*/

    }
}

void delete_record(){
    char name[260];
    FILE *fp;
    char line[1000];
    int i=0;

    printf("Enter name of the file to open it. All files in your directory:\n");

    struct dirent *de;  // Pointer for directory entry
    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");
    if (dr == NULL) { // opendir returns NULL if couldn't open directory
        printf("Could not open current directory" );
    }else{
        // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html  for readdir()
        while ((de = readdir(dr)) != NULL){
                //printf("%s\n", de->d_name); ��� ������ ��� �����
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
        getchar(); // ϳ��� scanf ���������� ������ ���� ���� \n ����������� � ��������� fgets, ���� ������ �����������.
        // getchar �������� ��� ������ .

        char list[100][100];
        char *addr[100];

        while ( fgets ( line, sizeof line, fp ) != NULL ){
            /*if(i % 3 == 0)
                printf("%d.\n", i/3 + 1);*/
            //fputs ( line, stdout );
            strcpy(list[i], line);
            i++;
        }

        int j, number;
        number = i;
        printf("\nNUmber is %d\n", i);
        j=0;

        printf("\nEnter number of record you want to delete:\n");
        int position = int_check();

        for(i=0;i<number;i += 3){
            if(j == position){
                i += 3;
            }
            strcpy(record.name[j], list[i]);
            record.square[j] = atof(list[i+1]);
            record.population[j] = atoi(list[i+2]);
            j ++;
        }

        for(i=0;i<number/3 - 1;i ++){
            printf("%s", record.name[i]);
            printf("%lf\n", record.square[i]);
            printf("%d\n", record.population[i]);
        }

        /*j = 0;
        for(i=0;i<number;i += 3){
            if(i == position){
                strcpy(record.name[j], list[i+3]);
                record.square[j] = atof(list[i+4]);
                record.population[j] = atoi(list[i+5]);
            }
            j ++;
        }

        for(i=0;(number/3)-1;i++){
            printf(record.name[i]);
            printf("%lf\n", record.square[i]);
            printf("%d\n", record.population[i]);
        }*/



        /*for(j=0;j<number/3;j++){
            for(i=0;i<number/3;i += 3){
                strcpy(record.name[j], list[i]);
                record.square[j] = atof(list[i+1]);
                record.population[j] = atoi(list[i+2]);
            } // TODO FUCKING INDEXES
            printf("%s", record.name[j]);
            printf("%lf\n", record.square[j]);
            printf("%d\n", record.population[j]);
        }*/

        /*for(j=0;j<i;j++){
            if(j == position){
                addr[j] = list[j+3];
                addr[j+1] = list[j+4];
                addr[j+2] = list[j+5];
                j += 3;
            }else{

            }
        }*/

        /*for(j=0;j<(i-3)/3;j++){
            fprintf(fp, record.name[j]);
            fprintf(fp, "%lf\n", record.square[j]);
            fprintf(fp, "%d\n", record.population[j]);
        }*/

        printf("\nRecords are written to file\n");
        getch();
        fclose(fp);
    }

    system("cls");
    main();
}

int main(){

    //system("chcp 1251"); //ϳ������� ��������

    int action;

    printf("Enter action:\n");
    printf("1.Create new file\n");
    printf("2.Read data from file\n");
    printf("3.Write data to file\n");
    printf("4.Delete records from file(test)\n");
    //printf("2.Create test file\n");
    //printf("3.Create new file and write data\n");
    action = int_check();
    switch(action){
        case 1:
            system("cls");
            create_file();
        case 2:
            system("cls");
            read_file();
        case 3:
            system("cls");
            write_file();
        case 4:
            system("cls");
            delete_record();
    }

    getch();
    return 0;
}
