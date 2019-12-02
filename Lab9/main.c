#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // For directories
//#include <sys/stat.h> //
#include <string.h> // To append string strncat()

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

void create_file(){  //ACTION 1
    FILE *fp;
    char name[260];

    printf("Enter file name:\n");
    scanf("%s", &name);
    strncat(name, ".txt", 4);
    if ((fp = fopen(name, "w")) == NULL){
        printf("Some problems occurred. Can't create file");
    }else{
        printf("File %s successfully created", name);
    }
    printf("Enter records:\n"); // TODO;

}

void read_file(){
    FILE *fp;
    int MAXCHAR = 1000;
    char str[253];
    char name[260];
    char line [ 128 ];

    printf("Enter file name:\n");
    scanf("%s", &name);
    //strncat(name, ".txt", 4);

    if ((fp = fopen(name, "r")) == NULL){
        printf("Can't open file.");
    }else{
        while ( fgets ( line, sizeof line, fp ) != NULL ){
         fputs ( line, stdout );
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
    /*if ((fp = fopen(name, "w")) == NULL){
        printf("Can't open file.");
    }else{
        fprintf(fp, "Hello world 1 \ntest123 \n\t54757456");
        fclose(fp);
    }*/

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
                //printf("%s\n", de->d_name); для виводу всіх файлів
                size_t len = strlen(de->d_name);
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0){
                    de->d_name[strlen(de->d_name) - 4] = '\0';
                    printf("%s\n", de->d_name);
                }
        }
        closedir(dr);

        //scanf("%s", &name);
        scanf("%s", &name);
        strncat(name, ".txt", 4);
        if ((fp = fopen(name, "w")) == NULL){
            printf("Can't open file.\n");
        }else{
            getchar(); // Після scanf залишається символ нової лінії \n заллишається і тригерить fgets, який одразу закривається.
            // getchar відловлює цей символ .
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

int main(){

    //system("chcp 1251"); //Підтримка кирилиці

    int action;

    printf("Enter action:\n");
    printf("1.Create new file\n");
    printf("2.Read data from file\n");
    //printf("2.Create test file\n");
    //printf("3.Create new file and write data\n");
    action = int_check();
    if(action == 1){
        system("cls");
        create_file();
    }
    if(action == 2){
        system("cls");
        read_file();
    }
    if(action == 3){
        system("cls");
        write_file();
    }

    getch();
    return 0;
}
