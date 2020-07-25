#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define NEWLINE ("\n")
#define FILENAME "/home/cyborg/Desktop/Student_Record_Management_System/database.txt"

#define MAX_FATHER_NAME 50
#define MAX_STUDENT_FIRST_NAME 50
#define MAX_STUDENT_LAST_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  400

typedef struct
{
    int student_id; 
    int age;
    char fatherName[MAX_FATHER_NAME];
    char studentFirstName[MAX_STUDENT_FIRST_NAME];
    char studentLastName[MAX_STUDENT_LAST_NAME];
    // char studentAddr[MAX_STUDENT_ADDRESS];
} studentInfo;


void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        printf(" ");
    }
    printf("%s",message);
}

void headMessage(const char *message)
{
    system("clear");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Student Record Management System Project in C   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Student Record              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
    system("clear");
}

void createStudentRecord()
{
    int status = 0;
    studentInfo studentData = {0};
    FILE *fp = NULL;
    fp = fopen(FILENAME, "a+");

    system("clear");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter("PLASE ENTER NEW DETAIL OF STUDENT");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    printf("\n\t\t\t\tEnter Student ID: ");
    scanf("%d", &studentData.student_id);  

    printf("\n\t\t\t\tEnter Student First Name: ");
    scanf("%s", studentData.studentFirstName);

    printf("\n\t\t\t\tEnter Student Last Name: ");
    scanf("%s", studentData.studentLastName);

    printf("\n\t\t\t\tEnter Student Age: ");
    scanf("%d", &studentData.age);

    printf("\n\t\t\t\tEnter Father's First Name: ");
    scanf("%s", studentData.fatherName);

   
    fprintf(fp, "\t\t\t");
    fprintf(fp, &studentData.student_id);
    fputs("\t\t", fp);
    fprintf(fp, studentData.studentFirstName);
    fprintf(fp, "\t\t");
    fprintf(fp, studentData.studentLastName);
    fprintf(fp, "\t");
    fprintf(fp, &studentData.age);
    fprintf(fp, "\t");
    fprintf(fp, studentData.fatherName);
    fprintf(fp, NEWLINE);

    fclose(fp);
}

void displayStudentRecord()
{
    int count = 0;
    int found = 0;
    char buff[ 1000 ];
    studentInfo studentData = {0};
    FILE *fp = NULL;
    unsigned int countStudent = 1;
    // headMessage("VIEW STUDENT DETAILS");
    fp = fopen(FILENAME,"r");

      system("clear");
    printf("\n\t\t\t\t\t\t\t ALL STUDENTS RESULT\t\t\t\t\n");
    printf("\t\t\t========================================================================================\n");
    printf("\t\t\tR.NO.\t\tNAME\t\tPHY.\tCHEM.\tMATH.\tECONS.\tPERCENTAGE\tGRADE\n");
    printf("\t\t\t========================================================================================\n");

    /* if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }

    while (fread (&studentData, sizeof(studentData), 1, fp))
    {
        printf("\n\t\t\tStudent Count = %d\n\n", &countStudent);
        printf("\t\t\tStudent id = %d\n",&studentData.student_id);
        printf("\t\t\tStudent First Name = %s",studentData.studentFirstName);
        printf("\t\t\tStudent Last Name = %s",studentData.studentLastName);
        printf("\t\t\tStudent Age = %d",&studentData.age);
        printf("\t\t\tFather Name = %s",studentData.fatherName);
        found = 1;
        ++countStudent;
    } */
    while (fgets(buff, 1000, fp) != NULL)
    {
        printf("%s", buff);
    }
        
    
    fclose(fp);
    
}

void searchStudentRecord()
{

}

void modifyStudentRecord()
{

}

void deleteStudentRecord()
{

}

void resultMenu()
{
    printf(NEWLINE);
    headMessage("RESULT MENU");
    printf(NEWLINE);
}

void entryMenu()
{
    printf(NEWLINE);
    headMessage("ENTRY MENU");
    printf(NEWLINE);

    int user_input;
    printf("\n\t\t\t01.) CREATE STUDENT RECORD");
    printf("\n\t\t\t02.) DISPLAY ALL STUDENTS RECORDS");
    printf("\n\t\t\t03.) SEARCH STUDENT RECORD");
    printf("\n\t\t\t04.) MODIFY STUDENT RECORD");
    printf("\n\t\t\t05.) DELETE STUDENT RECORD");
    printf("\n\t\t\t06.) BACK TO MAIN MENU");

    printf("Please Select your option (1-6)");

    scanf("%d", &user_input);

    if(user_input==1 || user_input==2 || user_input==3 || user_input==4 || user_input==5 || user_input==6)
    {
        switch(user_input)
        {
            case 1:
                createStudentRecord();
                break;
            case 2:
                displayStudentRecord();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                modifyStudentRecord();
                break;
            case 5:
                deleteStudentRecord();
                break;
            case 6:
                menu();
                break;
            default:
                entryMenu();
        }
    }
    else
    {
        system("clear");
        printf("\n\t\t\tIncorrect Value...\n\n");
        menu();
    }
}

int menu()
{
    int user_input;
    printf(NEWLINE);
    headMessage("MAIN MENU");
    printf("\n\t\t\t01.) RESULT MENU");
    printf("\n\t\t\t02.) ENTRY/EDIT MENU");
    printf("\n\t\t\t03.) EXIT");
    printf("\n\t\t\tPlease Select your Option (1-3): ");
    scanf("%d", &user_input);

    switch (user_input)
    {
    case 1:
        resultMenu();
        break;
    case 2:
        entryMenu();
        break;
    case 3:
        return 0;
    default:
        menu();
    }
}

int ifFileExists(const char *FileName)
{
    FILE *fp = NULL;
    fp = fopen(FILENAME, "r+");
    if(fp == NULL)
    {
        printf("File Does not Exist");
        system("clear");
        return 0;
    }
    else
    {
        fp = fopen(FileName, "a+");
        menu();
    }
}

int main()
{
    printf(NEWLINE);
    headMessage("Created By: Nephi Asha");
    welcomeMessage();
    printf(NEWLINE);
    ifFileExists(FILENAME);
}