#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // For directories
//#include <sys/stat.h> //
#include <string.h> // To append string strncat()
//В сі немає файлів , але є потоки


int int_check();
double float_check();
void create_file();
void read_file();
void write_file();
void delete_record();
void delete_file();
void edit_record();
void sort_records();
void append_sorted();

struct record{
    char name[1000][1000];
    double square[1000];
    unsigned long int population[1000];
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

            if(check == strlen(num) && atoi(num) > 0){
                return atoi(num);
                break;
            }else{
                printf("Incorrect input. Try another value \n");
            }
    }
}

double float_check(){
    char num[100];
    int i,check,dot;

    while(1){
        dot = 0;
        check = 0;
        scanf("%s", &num);
        for (i = 0; i < strlen(num); i++){
            if ((num[i] == 46 || isdigit(num[i])) && dot <=1){
                check += 1;
                if(num[i] == 46)
                    dot += 1;
            }
            else
                break;
        }

        if(check == strlen(num) && atof(num) > 0){
            return atof(num);
            break;
        }else{
            printf("Incorrect input. Try another value \n");
        }
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

    fprintf(fp, "Lab9\n");
    fprintf(fp, "0\n");
    fprintf(fp, "0\n");

    fclose(fp);

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

    printf("All files in your directory\n");
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
    }

    while(1){
        printf("Enter file name:\n");
        scanf("%s", &name);
        fflush(stdin);
        strncat(name, ".txt", 4);
        if ((fp = fopen(name, "r")) == NULL){
            printf("Can't open file.");
        }else{
            break;
        }
    }


    fseek (fp, 0, SEEK_END);
    int size = ftell(fp);

    if (0 == size) {
            printf("\n !File is not your . You can't operate it.!\n");
            printf("\nTo read another file press any button. To open main menu press ESC button.\n");
            if(getch() == 27){
                system("cls");
                fclose(fp);
                main();
            }else{
                system("cls");
                fclose(fp);
                read_file();
            }
    }
    fseek(fp, 0, SEEK_SET);

    while ( fgets ( line, sizeof line, fp ) != NULL ){
        if(i < 3){
            if(i == 0){
                if (strcmp(line, "Lab9\n") != 0){
                    printf("\n !File is not your . You can't operate it.!\n");
                    printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                    if(getch() == 27){
                        system("cls");
                        main();
                    }else{
                        system("cls");
                        read_file();
                    }
                }
            }
        }
        else{
            if(i % 3 == 0)
                printf("\n%d.\n", i/3);
            if((i + 3) % 3 == 0){
                printf("Name : ");
            }
            if((i + 2) % 3 == 0){
                printf("Square : ");
            }
            if((i + 1) % 3 == 0){
                printf("Population : ");
            }
            fputs ( line, stdout );
        }
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
        getchar();

        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size) {
                printf("\n !File is not your . You can't operate it.! \n");
                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    write_file();
                }
        }
        fseek(fp, 0, SEEK_SET);

        char line[1000];
        while ( fgets ( line, sizeof line, fp ) != NULL ){
                    if (strcmp(line, "Lab9\n") != 0){
                        printf("\n !File is not your . You can't operate it. !\n");
                        printf("\nTo delete another file press any button. To open main menu press ESC button.\n");
                        if(getch() == 27){
                            system("cls");
                            fclose(fp);
                            main();
                        }else{
                            system("cls");
                            fclose(fp);
                            write_file();
                        }
                    }else{
                        break;
                    }
        }

        fclose(fp);

        if ((fp = fopen(name, "w")) == NULL){
                printf("Some problems occurred while operating file.");
        }

        fprintf(fp, "Lab9\n");
        fprintf(fp, "0\n");
        fprintf(fp, "0\n");

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

    printf("Enter name of the file to delete record from it. All files in your directory:\n");

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

        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size) {
                printf("\n !File is not your . You can't operate it.! \n");
                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    delete_record();
                }
        }
        fseek(fp, 0, SEEK_SET);



        char list[100][100];
        char *addr[100];

        while ( fgets ( line, sizeof line, fp ) != NULL ){
            if(i < 3){
                if(i == 0){
                    if (strcmp(line, "Lab9\n") != 0){
                        printf("\n !File is not your . You can't operate it. !\n");
                        printf("\nTo delete another file press any button. To open main menu press ESC button.\n");
                        if(getch() == 27){
                            system("cls");
                            fclose(fp);
                            main();
                        }else{
                            system("cls");
                            fclose(fp);
                            delete_record();
                        }
                    }
                }
            }else{
                if(i % 3 == 0)
                    printf("\n%d.\n", i/3);
                if((i + 3) % 3 == 0){
                    printf("Name : ");
                }
                if((i + 2) % 3 == 0){
                    printf("Square : ");
                }
                if((i + 1) % 3 == 0){
                    printf("Population : ");
                }
                fputs ( line, stdout );
                strcpy(list[i-3], line);
            }
            i++;
        }
        if(i < 4){
            printf("File %s is empty.Try another one.\n\n", name);
            delete_record();
        }else{

            int j, number;
            number = i - 3;
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
                printf("Name : %s", record.name[i]);
                printf("Square : %lf\n", record.square[i]);
                printf("Population : %d\n", record.population[i]);
            }
            fclose(fp);

            while(1){
                if ((fp = fopen(name, "w")) == NULL){
                    printf("Can't open file.Try another name of file:\n");
                }else{
                    break;
                }
            }

            fprintf(fp, "Lab9\n");
            fprintf(fp, "0\n");
            fprintf(fp, "0\n");

            for(i=0;i<number/3-1;i++){
                fprintf(fp, record.name[i]);
                fprintf(fp, "%lf\n", record.square[i]);
                fprintf(fp, "%d\n", record.population[i]);
            }

            printf("\nRecords are deleted from file\n");
            fclose(fp);
        }
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
    char line[1000];

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

        if ((fp = fopen(name, "r")) == NULL){
            printf("Unable to open this file.");
            printf("To open another file press any key.To open main menu press ESC button.\n");
            if(getch() == 27){
                system("cls");
                main();
            }else{
                system("cls");
                delete_file();
            }
        }

        int check=0;

        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size) {
                printf("\n !File is not your . You can't delete it.! 1\n");
                printf("\nTo delete another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    delete_file();
                }
        }
        fseek(fp, 0, SEEK_SET);

        i = 0;
        while ( fgets ( line, sizeof line, fp ) != NULL ){
                    if (strcmp(line, "Lab9\n") != 0){
                        printf("\n !File is not your . You can't delete it.!\n");
                        printf("\nTo delete another file press any button. To open main menu press ESC button.\n");
                        if(getch() == 27){
                            system("cls");
                            fclose(fp);
                            main();
                        }else{
                            system("cls");
                            fclose(fp);
                            delete_file();
                        }
                    }else{
                        break;
                    }
        }

        fclose(fp);


        printf("\nFile is deleting\n");
        if (remove(name) == 0){
            printf("File %s deleted successfully.\n", name);
        }else{
            printf("Unable to delete the file.\n");
        }


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

        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size) {
                printf("\n !File is not your . You can't operate it.! \n");
                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    edit_record();
                }
        }
        fseek(fp, 0, SEEK_SET);

        while ( fgets ( line, sizeof line, fp ) != NULL ){
            if (strcmp(line, "Lab9\n") != 0){
                printf("\n !File is not your . You can't operate it.!\n");
                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    edit_record();
                }
            }else{
                break;
            }
        }


        char list[100][100];
        char *addr[100];

        fseek(fp, 0, SEEK_SET);
        i=0;
        while ( fgets ( line, sizeof line, fp ) != NULL ){
            if(i < 3){}
            else
                strcpy(list[i-3], line);
            i++;
        }
        if(i < 4){
            printf("File %s is empty.Try another one.\n\n", name);
            edit_record();
        }else{

            int j = 0, number = i - 3;
            for(i=0;i<number;i += 3){
                strcpy(record.name[j], list[i]);
                record.square[j] = atof(list[i+1]);
                record.population[j] = atoi(list[i+2]);
                j ++;
            }

            for(i=0;i<number/3;i ++){
                printf("\n%d.\n", i + 1);
                printf("Name : %s", record.name[i]);
                printf("Square : %lf\n", record.square[i]);
                printf("Population : %d\n", record  .population[i]);
            }

            int position = 1002;
            printf("\nEnter number of record you want to edit:\n");
            do{
                position = int_check();
            }while(position < 1 || position > number/3);

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
                printf("Name : %s", record.name[i]);
                printf("Square : %lf\n", record.square[i]);
                printf("Population : %d\n", record.population[i]);
            }

            fclose(fp);

            while(1){
                if ((fp = fopen(name, "w")) == NULL){
                    printf("Can't open file.Try another name of file:\n");
                }else{
                    break;
                }
            }

            fprintf(fp, "Lab9\n");
            fprintf(fp, "0\n");
            fprintf(fp, "0\n");

            for(i=0;i < number/3;i++){
                fprintf(fp, record.name[i]);
                fprintf(fp, "%lf\n", record.square[i]);
                fprintf(fp, "%d\n", record.population[i]);
            }
            printf("Record number %d is edited in file.", i);
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
}

void sort_records(){
    char name[260];
    FILE *fp;
    char line[1000];
    int i=0;
    char list[100][100];

    printf("Enter name of the file you want to sort. All files in your directory:\n");

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
            fflush(stdin);
            strncat(name, ".txt", 4);
            if ((fp = fopen(name, "r+")) == NULL){
                printf("Can't open file.Try another name of file:\n");
            }else{
                break;
            }
        }

        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size) {
                printf("\n !File is not your . You can't operate it.! \n");
                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    sort_records();
                }
        }
        fseek(fp, 0, SEEK_SET);


        i=0;
        while ( fgets ( line, sizeof line, fp ) != NULL ){
            if(i<3){
                if(i == 0){
                    if (strcmp(line, "Lab9\n") != 0){
                            printf("\n !File is not your . You can't operate it.!\n");
                            printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                            if(getch() == 27){
                                system("cls");
                                fclose(fp);
                                main();
                            }else{
                                system("cls");
                                fclose(fp);
                                sort_records();
                            }
                    }
                }
            }else{
                strcpy(list[i-3], line);
            }
            i++;
        }
        if(i < 4){
            printf("File %s is empty.Try another one.\n\n", name);
            sort_records();
        }else{
            int j = 0, number = i-3;
            for(i=0;i<number;i += 3){
                strcpy(record.name[j], list[i]);
                record.square[j] = atof(list[i+1]);
                record.population[j] = atoi(list[i+2]);
                j++;
            }
            for(i=0;i < number/3;i++){
                printf("\n%d.\n", i + 1);
                printf("Name : %s", record.name[i]);
                printf("Square : %lf\n", record.square[i]);
                printf("Population : %d\n", record.population[i]);
            }

            j=0;
            double c;
            int d;
            char e[1000];
            int sort_operator, sort_order;
            printf("Enter sort operator(1 - name, 2 - square, 3 - population)\n");
            while(1){
                sort_operator = int_check();
                if(sort_operator == 1 || sort_operator == 2 || sort_operator == 3){
                    break;
                }else
                    printf("Incorrect sort operator");
            }
            printf("Enter sort order(1 : '+',2 : '-')\n");
            while(1){
                sort_order = int_check();
                if(sort_order == 1 || sort_order == 2){
                    break;
                }else
                    printf("Incorrect sort order");
            }
            for (i = 0; i < number/3; i++){
                for (j = i + 1; j < number/3; j++){
                    switch(sort_operator){
                        case 1:
                            if(sort_order == 1){
                                if (strcmp(record.name[i], record.name[j]) > 0){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            else{
                                if (strcmp(record.name[i], record.name[j]) < 0){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            break;

                        case 2:
                            if(sort_order == 1){
                                if (record.square[i] > record.square[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            else{
                                if (record.square[i] < record.square[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            break;

                        case 3:
                            if(sort_order == 1){
                                if (record.population[i] > record.population[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            else{
                                if (record.population[i] < record.population[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            break;
                    }
                }
            }

                fclose(fp);

        for(i=0;i < number/3;i++){
            printf("\n%d.\n", i + 1);
            printf("Name : %s", record.name[i]);
            printf("Square : %lf\n", record.square[i]);
            printf("Population : %d\n", record.population[i]);
        }

        while(1){
            if ((fp = fopen(name, "w")) == NULL){
                printf("Some problems occurred while operating file:\n");
            }else{
                break;
            }
        }

        fprintf(fp, "Lab9\n");
        fprintf(fp, "%d\n", sort_operator);
        fprintf(fp, "%d\n", sort_order);

        for(i=0;i < number/3;i++){
            fprintf(fp, "%s", record.name[i]);
            fprintf(fp, "%lf\n", record.square[i]);
            fprintf(fp, "%d\n", record.population[i]);
        }

        fclose(fp);

        }

    }

    printf("To continue press any button. To open main menu press ESC button.\n");
    if(getch() == 27){
        system("cls");
        main();
    }else{
        system("cls");
        sort_records();
    }
}

void append_sorted(){
    char name[260];
    FILE *fp;
    char line[1000];
    int i=0;
    char list[100][100];

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
            fflush(stdin);
            strncat(name, ".txt", 4);
            if ((fp = fopen(name, "r")) == NULL){
                printf("Can't open file.Try another name of file:\n");
            }else{
                break;
            }
        }

        fseek (fp, 0, SEEK_END);
        int size = ftell(fp);

        if (0 == size) {
                printf("\n !File is not your . You can't operate it.! \n");
                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                if(getch() == 27){
                    system("cls");
                    fclose(fp);
                    main();
                }else{
                    system("cls");
                    fclose(fp);
                    append_sorted();
                }
        }


        i=0;
        int sort_operator, sort_order;

            fseek(fp, 0, SEEK_SET);
            while ( fgets ( line, sizeof line, fp ) != NULL ){
                if(i < 3){
                    if(i == 0){
                        if (strcmp(line, "Lab9\n") != 0){
                            printf("\n !File is not your . You can't operate it.!\n");
                            printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                            if(getch() == 27){
                                system("cls");
                                fclose(fp);
                                main();
                            }else{
                                system("cls");
                                fclose(fp);
                                append_sorted();
                            }
                        }/*else{
                            fseek (fp, 0, SEEK_END);
                            int size = ftell(fp);

                            if (0 == size) {
                                printf("File is empty.\n");
                                printf("\nTo open another file press any button. To open main menu press ESC button.\n");
                                if(getch() == 27){
                                    system("cls");
                                    fclose(fp);
                                    main();
                                }else{
                                    system("cls");
                                    fclose(fp);
                                    append_sorted();
                                }
                            }
                            //fseek(fp, 0, SEEK_SET);
                        }*/
                    }
                    if(i == 1){
                        sort_operator = atoi(line);
                        printf("Sort operator = %d\n", sort_operator);
                    }
                    if(i == 2){
                        sort_order = atoi(line);
                        printf("sort_order = %d\n", sort_order);
                    }
                }else{
                    strcpy(list[i-3], line);
                }
                i++;
            }


            int j = 0, number = i-3;
            for(i=0;i<number;i += 3){
                strcpy(record.name[j], list[i]);
                record.square[j] = atof(list[i+1]);
                record.population[j] = atoi(list[i+2]);
                j++;
            }
            for(i=0;i < number/3;i++){
                printf("\n%d.\n", i + 1);
                printf("Name : %s", record.name[i]);
                printf("Square : %lf\n", record.square[i]);
                printf("Population : %d\n", record.population[i]);
            }

            printf("Enter region name:\n");
            do{
                fgets(record.name[number/3], 1000, stdin);
            }while(strlen(record.name[number/3]) <= 1);
            printf("Enter region square :\n");
            record.square[number/3] = float_check();
            printf("Enter region population:\n");
            record.population[number/3] = int_check();

            double c;
            int d;
            char e[1000];

            for (i = 0; i < number/3 + 1; i++){
                for (j = i + 1; j < number/3 + 1; j++){
                    switch(sort_operator){
                        case 1:
                            if(sort_order == 1){
                                if (strcmp(record.name[i], record.name[j]) > 0){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            else{
                                if (strcmp(record.name[i], record.name[j]) < 0){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            break;

                        case 2:
                            if(sort_order == 1){
                                if (record.square[i] > record.square[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            else{
                                if (record.square[i] < record.square[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            break;

                        case 3:
                            if(sort_order == 1){
                                if (record.population[i] > record.population[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            else{
                                if (record.population[i] < record.population[j]){
                                    strcpy(e, record.name[i]);
                                    strcpy(record.name[i], record.name[j]);
                                    strcpy(record.name[j]   , e);
                                    c =  record.square[i];
                                    record.square[i] = record.square[j];
                                    record.square[j] = c;
                                    d =  record.population[i];
                                    record.population[i] = record.population[j];
                                    record.population[j] = d;
                                }
                            }
                            break;
                    }
                }
            }

            fclose(fp);

            for(i=0;i < number/3 + 1;i++){
                printf("\n%d.\n", i + 1);
                printf("Name : %s", record.name[i]);
                printf("Square : %lf\n", record.square[i]);
                printf("Population : %d\n", record.population[i]);
            }

            while(1){
                if ((fp = fopen(name, "w")) == NULL){
                    printf("Some problems occurred while operating with file:\n");
                }else{
                    break;
                }
            }

            fprintf(fp, "Lab9\n");
            fprintf(fp, "%d\n", sort_operator);
            fprintf(fp, "%d\n", sort_order);

            for(i=0;i < number/3 + 1;i++){
                fprintf(fp, record.name[i]);
                fprintf(fp, "%lf\n", record.square[i]);
                fprintf(fp, "%d\n", record.population[i]);
            }

            fclose(fp);





        printf("To continue press any button.To open main menu pres ESC button.\n");
        if(getch() == 27){
            system("cls");
            main();
        }else{
            system("cls");
            append_sorted();
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
    printf("8.Append record to sorted file\n");
    do{
        action = int_check();
    }while(action < 0 || action > 8);
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
        case 8:
            system("cls");
            append_sorted();
    }
    getch();
    return 0;
}
