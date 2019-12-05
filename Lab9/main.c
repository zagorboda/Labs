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
                //printf("%s\n", de->d_name); для виводу всіх файлів
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    strcpy(list[i], de->d_name);
                    addr[i] = list[i];
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
        }else{
            printf("File %s successfully created\n", name);
        }
    }

    printf("To open main menu press any button.\n");
    getch();
    system("cls");
    main();
}

void read_file(){
    FILE *fp;
    int MAXCHAR = 1000;
    char str[253];
    char name[260];
    char line [128];
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

    printf("\nTo continue press any button. To open main menu press ESC button.\n");
    if(getch() == 27){
        system("cls");
        main();
    }else{
        system("cls");
        read_file();
    }

}

void write_file(){
    FILE *fp;
    char name[260];
    int MAXCHAR = 1000;
    char str[MAXCHAR];

    printf("***  All your previous records in file will be deleted  ***\n");
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
            printf("Enter file name:\n");
            scanf("%s", &name);
            strncat(name, ".txt", 4);
            if ((fp = fopen(name, "r+")) == NULL){
                printf("Can't open file.");
            }else{
                break;
            }
        }
            getchar(); // Після scanf залишається символ нової лінії \n заллишається і тригерить fgets, який одразу закривається.
            // getchar відловлює цей символ .
            int i = 0;
            while(1){
                printf("Enter region name:\n");
                do{
                    fgets(record.name[i], 1000, stdin);
                }while(strlen(record.name[i]) <= 1);// Використовуєм 1 замість нуля оскільки є нульовий байт \0
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


        /*if ((fp = fopen(name, "r")) == NULL){
            printf("Can't open file.");
        }else{
            while (fgets(str, MAXCHAR, fp) != NULL)
            printf("%s", str);
        }*/
    }

    printf("To write data to another file press any button.To open main menu pres ESC button\n");
    if(getch() == 27){
        system("cls");
        main();
    }else{
        system("cls");
        write_file();
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
        getchar(); // Після scanf залишається символ нової лінії \n заллишається і тригерить fgets, який одразу закривається.
        // getchar відловлює цей символ .

        char list[100][100];
        char *addr[100];

        while ( fgets ( line, sizeof line, fp ) != NULL ){
            if(i % 3 == 0)
                printf("\n%d.\n", i/3 + 1);
            fputs ( line, stdout );
            strcpy(list[i], line);
            i++;
        }

        int j, number;
        number = i;
        j=0;

        printf("\nEnter number of record you want to delete:\n");
        int position = int_check();

        for(i=0;i<number;i += 3){
            if(j == position - 1){
                i += 3;
            }
            strcpy(record.name[j], list[i]);
            record.square[j] = atof(list[i+1]);
            record.population[j] = atoi(list[i+2]);
            j ++;
        }

        for(i=0;i<number/3 - 1;i ++){
            printf("\n%d.\n", i + 1);
            printf("%s", record.name[i]);
            printf("%lf\n", record.square[i]);
            printf("%d\n", record.population[i]);
        }
        fclose(fp);

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

        while(1){
            if ((fp = fopen(name, "w")) == NULL){
                printf("Can't open file.Try another name of file:\n");
            }else{
                break;
            }
        }

        for(i=0;i<number/3-1;i++){
            fprintf(fp, record.name[i]);
            fprintf(fp, "%lf\n", record.square[i]);
            fprintf(fp, "%d\n", record.population[i]);
        }

        printf("\nRecords are deleted from file\n");
        fclose(fp);
    }

    printf("To continue press any button. To open main menu press ESC button.\n");
    if(getch() == 27){
        system("cls");
        main();
    }else{
        system("cls");
        delete_record();
    }
}

void delete_file(){
    FILE *fp;
    char name[260];
    char list[100][100];
    char *addr[100];
    int overwrite;
    int file_exists = 0;

    printf("Choose file to delete:\n");
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL) {
        printf("Could not open current directory" );
    }else{
        // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html  for readdir()
        int i=0;
        while ((de = readdir(dr)) != NULL){
                //printf("%s\n", de->d_name);
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    strcpy(list[i], de->d_name);
                    addr[i] = list[i];
                    fputs(addr[i], stdout);
                    printf("\n");
                    i++;
                }
        }
        scanf("%s", &name);
        strncat(name, ".txt", 4);

        if (remove(name) == 0)
            printf("File %s deleted successfully.\n", name);
        else
            printf("Unable to delete the file.\n");

        printf("To open main menu press any button.\n");
        getch();
        system("cls");
        main();
    }
}

void edit_record(){

    FILE *fp;
    char name[260];
    char list[100][100];
    char *addr[100];
    char line[1000];

    printf("Choose file to edit:\n");
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL) {
        printf("Could not open current directory" );
    }else{
        // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html  for readdir()
        int i=0;
        while ((de = readdir(dr)) != NULL){
                //printf("%s\n", de->d_name); для виводу всіх файлів
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    strcpy(list[i], de->d_name);
                    addr[i] = list[i];
                    fputs(addr[i], stdout);
                    printf("\n");
                    i++;
                }
        }
        while(1){
            scanf("%s", &name);
            strncat(name, ".txt", 4);
            if ((fp = fopen(name, "r+")) == NULL){
                printf("Can't open file.Try another name of file:\n");
            }else{
                break;
            }
        }

        getchar();
        char list[100][100];
        char *addr[100];

        i=0;
        while ( fgets ( line, sizeof line, fp ) != NULL ){
            strcpy(list[i], line);
            i++;
        }

        int j = 0, number = i;
        for(i=0;i<number;i += 3){
            strcpy(record.name[j], list[i]);
            record.square[j] = atof(list[i+1]);
            record.population[j] = atoi(list[i+2]);
            j ++;
        }

        for(i=0;i<number/3;i ++){
            printf("\n%d.\n", i + 1);
            printf("%s", record.name[i]);
            printf("%lf\n", record.square[i]);
            printf("%d\n", record  .population[i]);
        }

        printf("\nEnter number of record you want to edit:\n");
        int position = int_check();

        getchar();
        int length;
        length = strlen(record.name[position-1]);
        printf("Enter region name:\n");
        do{
            fgets(record.name[position-1], 1000, stdin);
        }while(strlen(record.name[position - 1]) <= 1);
        printf("Enter region square :\n");
        record.square[position-1] = float_check();
        printf("Enter region population:\n");
        record.population[position-1] = int_check();

        for(i=0;i<number;i += 3){
            strcpy(record.name[j], list[i]);
            record.square[j] = atof(list[i+1]);
            record.population[j] = atoi(list[i+2]);
            j ++;
        }

        for(i=0;i<number/3;i ++){
            printf("\n%d.\n", i + 1);
            printf("%s", record.name[i]);
            printf("%lf\n", record.square[i]);
            printf("%d\n", record.population[i]);
        }

        fclose(fp);

        if ((fp = fopen(name, "w")) == NULL){
            printf("Some problems occurred with file processing.\n");
        }else{
            for(i=0;i < number/3;i++){
            fprintf(fp, record.name[i]);
            fprintf(fp, "%lf\n", record.square[i]);
            fprintf(fp, "%d\n", record.population[i]);
            }printf("Record number %d is edited in file. Press any key to continue or 'ESC' button to finish reading data.\n", i);
        }
        fclose(fp);
    }

    printf("To continue press any button. To open main menu press ESC button.\n");
    if(getch() == 27){
        system("cls");
        main();
    }else{
        system("cls");
        edit_record();
    }
}

void sort_records(){
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
        getchar();

        char list[100][100];
        char *addr[100];

        while ( fgets ( line, sizeof line, fp ) != NULL ){
            if(i % 3 == 0)
                printf("\n%d.\n", i/3 + 1);
            fputs ( line, stdout );
            strcpy(list[i], line);
            i++;
        }

        int j, number;
        number = i;
        j=0;
        int sort_operator=0, sort_order=0;

        printf("Enter sorting operator(1 - name;2 - square; 3 - population)");
        while(1){
            sort_operator = int_check();
            if(sort_operator == 1 || sort_operator == 2 || sort_operator == 3)
                break;
        }
        printf("Enter order to sort(1 - ''+'',2 - ''-'')");
        while(1){
            sort_order = int_check();
            if(sort_order == 1 || sort_order == 2)
                break;
        }

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
        case 5:
            system("cls");
            delete_file();
        case 6:
            system("cls");
            edit_record();
        case 7:
            system("cls");
            sort_records();
    }

    getch();
    return 0;
}
