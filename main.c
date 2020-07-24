#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define NEWLINE ("\n")
#define FILENAME ("/home/cyborg/Desktop/Student_Information_Management_System/database.txt")



typedef struct 
{
    char regNo[100];
    char student_name[60];
    char grade[10];
    char phy[10];
    char math[10];
    char chem[10];
    char econ[10];
    int percentage;
} data;

int main()
{
    displayMessage();
    welcomeMessage();
    ifFileExists(FILENAME);
    // system("clear");
    
    
}

void displayMessage()
{

    system("clear");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Student Record Management System Project in C   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void welcomeMessage()
{
    system("clear");
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
}

void mainMenu()
{
    int user_input;
    printf("\t\t\tMAIN MENU\n");
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
        return 0;;
    default:
        mainMenu();
    }
}

void resultMenu()
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(FILENAME, "r");
    system("clear");
    char buff[ 100 ];
    fp = fopen(FILENAME,"r");
    
    system("clear");
    printf("\n\t\t\t\t\t\t\t ALL STUDENTS RESULT\t\t\t\t\n");
    printf("\t\t\t========================================================================================\n");
    printf("\t\t\tR.NO.\t\tNAME\t\tPHY.\tCHEM.\tMATH.\tECONS.\tPERCENTAGE\tGRADE\n");
    printf("\t\t\t========================================================================================\n");
    
   do
   {     
       
        fgets(buff, 255 , (FILE*)fp);
        printf("%s\n", buff );
        count += sizeof(fp);
    
   } while (count <= sizeof(data));
   

    fgets(buff, 255 , (FILE*)fp);
    printf("%s\n", buff );
    
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
    mainMenu();
}

void entryMenu()
{
    int user_input;
    system("clear");
    printf("\n\t\t\t\tENTRY MENU");
    printf("\n\t\t\t01.) CREATE STUDENT RECORD");
    printf("\n\t\t\t02.) DISPLAY ALL STUDENTS RECORDS");
    printf("\n\t\t\t03.) SEARCH STUDENT RECORD");
    printf("\n\t\t\t04.) MODIFY STUDENT RECORD");
    printf("\n\t\t\t05.) DELETE STUDENT RECORD");
    printf("\n\t\t\t06.) BACK TO MAIN MENU");

    printf("Please Select your option (1-6)");

    scanf("%d", &user_input);

    switch(user_input)
    {
        case 1:
            createStudentRecord();
            break;
        case 2:
            displayAllStudentRecord();
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
            mainMenu();
            break;
        default:
            mainMenu();
    }

    
}

void ifFileExists(const char *FileName)
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
        mainMenu();
    }
}

void createStudentRecord()
{
    data studentData;
    FILE *fp = NULL;
    fp = fopen(FILENAME, "a+");    
   
    system("clear");
    printf("\n\t\t\t\tPLASE ENTER NEW DETAIL OF STUDENT");
    printf("\n\t\t\t\tEnter Roll Number: ");
    scanf("%s", studentData.regNo);
   

    printf("\n\t\t\t\tEnter Student Name: ");
    scanf("%s", studentData.student_name);
    

    printf("\t\t\t\tEnter Marks in Physics (Out of 100): ");
    scanf("%s", studentData.phy);
    

    printf("\t\t\t\tEnter Marks in Chemistry (Out of 100): ");
    scanf("%s", studentData.chem);
    

    printf("\t\t\t\tEnter Marks in Mathematics (Out of 100): ");
    scanf("%s", studentData.math);
    

    printf("\t\t\t\tEnter Marks in Economics (Out of 100): ");
    scanf("%s", studentData.econ);

    // fwrite(&studentData,sizeof(studentData), 1, fp);
    fprintf(fp, "\t\t\t");
    fprintf(fp, studentData.regNo);
    fputs("\t\t", fp);
    fprintf(fp, studentData.student_name);
    fprintf(fp, "\t\t");
    fprintf(fp, studentData.phy);
    fprintf(fp, "\t");
    fprintf(fp, studentData.chem);
    fprintf(fp, "\t");
    fprintf(fp, studentData.math);
    fprintf(fp, "\t");
    fprintf(fp, studentData.econ); 
    fprintf(fp, NEWLINE);
    fclose(fp);
    
}
void displayAllStudentRecord()
{
    FILE *fp = NULL;
    fp = fopen(FILENAME, "r");
    system("clear");
    char buff[ 100 ];
    fp = fopen(FILENAME,"r");
    fgets(buff, 255 , (FILE*)fp);
    printf("%s\n", buff );
    
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
    mainMenu();
}
void searchStudentRecord(){system("clear");}
void modifyStudentRecord(){system("clear");}
void deleteStudentRecord(){system("clear");}
