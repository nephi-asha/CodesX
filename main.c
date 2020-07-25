




void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}

void mainMenu()
{
    int user_input;
    // printf("\t\t\tMAIN MENU\n");
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
        system("exit");
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

void displayAllStudentRecord()
{
    resultMenu();
}
void searchStudentRecord(){system("clear");}
void modifyStudentRecord(){system("clear");}
void deleteStudentRecord(){system("clear");}

//Head message
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
    
   } while (count <= sizeof(fp) * 3);
   

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

    if(user_input==1 || user_input==2 || user_input==3 || user_input==4 || user_input==5 || user_input==6)
    {
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
    else
    {
        system("clear");
        printf("\n\t\t\tIncorrect Value...\n\n");
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



int main()
{
    displayMessage();
    welcomeMessage();
    ifFileExists(FILENAME);
    // system("clear");
    
    
}