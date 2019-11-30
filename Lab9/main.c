#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


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


void test(){
    FILE *fp;
    int MAXCHAR = 1000;
    char str[MAXCHAR];
    char name[] = "test.txt";
    if ((fp = fopen(name, "w")) == NULL){
        printf("Can't open file.");
    }else{
        fprintf(fp, "Hello world 1 \ntest123 \n\t54757456");
        fclose(fp);
    }

    if ((fp = fopen(name, "r")) == NULL){
        printf("Can't open file.");
    }else{
        while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    }
}

void write_file(){

    char name[260];
    FILE *fp;
    int MAXCHAR = 1000;
    char str[MAXCHAR];

    printf("Enter name of the file to open it. All text file in your directory:");

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
                if(len > 4 && strcmp(de->d_name + len - 4, ".txt") == 0)
                    printf("%s\n", de->d_name);
        }
        closedir(dr);

        //scanf("%s", &name);
        scanf("%s", &name);
        if ((fp = fopen(name, "w")) == NULL){
            printf("Can't open file.");
        }else{
            printf("Fuck");
            fprintf(fp, "Hello world bla-bla blya-blya blyat");
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
    printf("1.Create test file\n");
    printf("2.Create new file and write data\n");
    action = int_check();
    if(action == 1){
        system("cls");
        test();
    }
    if(action == 2){
        system("cls");
        write_file();
    }

    getch();
    return 0;
}
