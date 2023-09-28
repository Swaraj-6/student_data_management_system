#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>


void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();

struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};


void main(){
    printf("Press any key to continue.");
    getch();
    menu();
}


void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void menu(){
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10, 5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(0);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
        fflush(stdin);
        Sleep(2000);
        menu();
    }
}


void add(){
    FILE *fp;
    int length;
    struct student std;
    char another = 'y';
    system("cls");

    fp = fopen("record.txt", "ab+");
    if (fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        Sleep(2000);
        exit(1);
    }
    fflush(stdin);
    while (another == 'y'){
        gotoxy(10,3);
        printf("Enter details of student.");

        gotoxy(10,7);
        printf("Enter Name : ");
        fgets(std.name, sizeof(std.name), stdin);
        length = strlen(std.name);
        if (length > 0 && std.name[length - 1] == '\n') {
            std.name[length - 1] = '\0';
        }
        fflush(stdin);

        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        fgets(std.mobile, sizeof(std.mobile), stdin);
        length = strlen(std.mobile);
        if (length > 0 && std.mobile[length - 1] == '\n') {
            std.mobile[length - 1] = '\0';
        }
        fflush(stdin);

        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d", &std.rollno);
        fflush(stdin);

        gotoxy(10,10);
        printf("Enter Course : ");
        fgets(std.course, sizeof(std.course), stdin);
        length = strlen(std.course);
        if (length > 0 && std.course[length - 1] == '\n') {
            std.course[length - 1] = '\0';
        }
        fflush(stdin);

        gotoxy(10,11);
        printf("Enter Branch : ");
        fgets(std.branch, sizeof(std.branch), stdin);
        length = strlen(std.course);
        if (length > 0 && std.course[length - 1] == '\n') {
            std.course[length - 1] = '\0';
        }
        fflush(stdin);

        fwrite(&std, sizeof(std), 1, fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}

void view(){
    FILE *fp;
    int i=1, j=8;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Student       Mobile No   Roll No  Course      Branch");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt", "rb+");
    if (fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        Sleep(2000);
        exit(1);
    }
    while(fread(&std, sizeof(std), 1, fp) == 1){
        gotoxy(10, j);
        printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}

void search(){
    FILE *fp;
    struct student std;
    int ent_roll_no;
    system("cls");
    gotoxy(10,3);
    printf("Enter the roll no of the Student : ");
    fflush(stdin);
    scanf("%d", &ent_roll_no);
    fp = fopen("record.txt","rb+");
    if (fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        Sleep(2000);
        exit(1);
    }

    while(fread(&std, sizeof(std), 1, fp) == 1){
        if(ent_roll_no == std.rollno){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,11);
            printf("Course : %s",std.course);
            gotoxy(10,12);
            printf("Branch : %s",std.branch);
        }else{
            gotoxy(10, 5);
            printf("Record Not found.");
            Sleep(2000);
            menu();
        }
        fclose(fp);
        gotoxy(10,16);
        printf("Press any key to continue.");
        getch();
        fflush(stdin);
        menu();
    }
}

void modify(){
    FILE *fp;
    struct student std;
    int ent_roll_no, length;
    system("cls");
    gotoxy(10,3);
    printf("Enter the roll no of the Student : ");
    fflush(stdin);
    scanf("%d", &ent_roll_no);
    fflush(stdin);
    fp = fopen("record.txt","rb+");
    if (fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        Sleep(2000);
        exit(1);
    }

     while(fread(&std, sizeof(std), 1, fp) == 1){
        if(ent_roll_no == std.rollno){
            gotoxy(10,7);
        printf("Enter Name : ");
        fgets(std.name, sizeof(std.name), stdin);
        length = strlen(std.name);
        if (length > 0 && std.name[length - 1] == '\n') {
            std.name[length - 1] = '\0';
        }
        fflush(stdin);

        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        fgets(std.mobile, sizeof(std.mobile), stdin);
        length = strlen(std.mobile);
        if (length > 0 && std.mobile[length - 1] == '\n') {
            std.mobile[length - 1] = '\0';
        }
        fflush(stdin);

        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d", &std.rollno);
        fflush(stdin);

        gotoxy(10,10);
        printf("Enter Course : ");
        fgets(std.course, sizeof(std.course), stdin);
        length = strlen(std.course);
        if (length > 0 && std.course[length - 1] == '\n') {
            std.course[length - 1] = '\0';
        }
        fflush(stdin);

        gotoxy(10,11);
        printf("Enter Branch : ");
        fgets(std.branch, sizeof(std.branch), stdin);
        length = strlen(std.course);
        if (length > 0 && std.course[length - 1] == '\n') {
            std.course[length - 1] = '\0';
        }
        fflush(stdin);

        fseek(fp ,-sizeof(std),SEEK_CUR);
        fwrite(&std, sizeof(std), 1, fp);
        break;
        }
    }

    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}

void deleterec(){
    FILE *fp, *ft;
    struct student std;
    int ent_roll_no;
    system("cls");
    gotoxy(10,3);
    printf("Enter the roll no of the Student : ");
    fflush(stdin);
    scanf("%d", &ent_roll_no);
    fp = fopen("record.txt","rb+");
    if (fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        Sleep(2000);
        exit(1);
    }
    ft = fopen("temp.txt", "wb+");
    if (ft == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        Sleep(2000);
        exit(1);
    }

    while(fread(&std, sizeof(std), 1, fp) == 1){
        if (ent_roll_no != std.rollno){
            fwrite(&std,sizeof(std),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();

}