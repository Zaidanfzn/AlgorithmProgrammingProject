#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void loginAdmin(int n);
void loginTeacher(int n);
void loginStudent(int n);
void mainpageTeacher();
void mainpageStudent();
void teacherRegist();
void studentRegist();
void adminMenu();
void seestudentData();
void addeduLevels();
void addstuPackage();
void addstuSchedule1();
void addstuSchedule2();
void salaryData();
void salaryAdmin();
void teacherMenu(char t[50]);
void seelistStu(char t[50]);
void feedback(char t[50]);
void seesalTeach(char t[50]);
void studentMenu(char s[50]);
void seelearnPack(char s[50]);
void chooselearnPack(char s[50]);
// void sortdata1(char sort[50]);
// void sortdata2(struct CourseData2 stupackage[50], int n);
// void sortdata3(struct CourseData2 stupackage[50], int n, char type[]);
void learnpackPay(char s[50]);
void chooseSch(char s[50]);
void seeref(char s[50]);
void helpDesk(char s[50]);
void admin_hd();
void loading(int n);

FILE *teacherdata;
FILE *studentdata;
FILE *studentdata1;
FILE *order;
FILE *coursedata1;
FILE *coursedata2;
FILE *scheduledata1;
FILE *scheduledata2;
FILE *salarydata;
FILE *salarydata1;
FILE *ref;
FILE *revref;
FILE *helpdesk;

char unameAdmin[10], passAdmin[10], unameTeacher[50], passTeacher[50], unameStudent[10], passStudent[10], fix[10], name[50];
struct TeacherData{
    char email[50], name[50], phone_num[50], address[50], gender[50], age[50], edulevels[50], subject[50], uname[10], pass[10];
}teadat;
struct StudentData{
    char email[50], name[50], phone_num[50], address[50], edulevels[50], stupack[50], stuteach[50], cstatus[50], day[50], shift[50], uname[10], pass[10];
    float price;
    int status;
}studat;
struct CourseData1{
    char edulevels[50];
}coudata1;
struct CourseData2{
    char edulevels[50], stupack[50], stuteach[50];
    float price;
}coudata2;
struct ScheduleData1{
    char day[50];
}schdata1;
struct ScheduleData2{
    char day[50], shift[50];
}schdata2;
struct ListOrder{
    char email[50], name[50], phone_num[50], address[50], edulevels[50], stupack[50], stuteach[50], cstatus[50], day[50], shift[50];
    float price;
    int status;
}listorder;
struct SalaryData{
    char email[50], name[50], phone_num[50], address[50], edulevels[50], stupack[50], stuteach[50], cstatus[50], day[50], shift[50];
    float aprice, salmin, salteach;
    int status;
}saldata;
struct SalaryData1{
    char email[50], name[50], phone_num[50], address[50], edulevels[50], stupack[50], stuteach[50], cstatus[50], day[50], shift[50];
    float aprice, salmin, salteach;
    int status;
}saldata1;
struct ReviewFeedback{
    char name[50], teachname[50], message[1000];
}reback;
struct RevReviewFeedback{
    char name[50], teachname[50], message[1000];
}revrefback;
struct HelpDesk {
    char question[100], answer[100];
}hd;


int main(){
    system("cls");
    int n;

    printf("================= WELCOME TO D'COURSE =================");
    printf("\n\n1. Admin\n2. Teacher\n3. Student\n\n");
    printf("Select menu : "); scanf("%d", &n); getchar();

    switch (n){
    case 1 :
        loading(3);
        system("cls");
        loginAdmin(3);
        break;
    case 2 :
        loading(3);
        mainpageTeacher();
        break;
    case 3 :
        loading(3);
        mainpageStudent();
        break;
    default:
        printf("\nThe option is not available, please select again!");
        loading(3);
        main();
        break;
    }
}


void loginAdmin(int n){  
    printf("\n================= LOGIN ADMIN =================\n\n");
    printf("Username : ");
    gets(unameAdmin);
    printf("Password : ");
    gets(passAdmin);
    loading(3);

    if(n > 0){
        if(strcmp(unameAdmin,"admin")==0 && strcmp(passAdmin,"dcourse")==0){
            adminMenu();
        }
        else if(strcmp(unameAdmin,"admin")!=0 && strcmp(passAdmin,"dcourse")==0){
            printf("Please check your username!!\n");
            loginAdmin(n-1);
        }
        else if(strcmp(unameAdmin,"admin")==0 && strcmp(passAdmin,"dcourse")!=0){
            printf("Please check your password!!\n");
            loginAdmin(n-1);
        }
        else {
            printf("Please check your username and your password!!\n");
            loginAdmin(n-1);
        }
    } 
    else {
        printf("Your chance has run out, please return to the main menu!!\n\n");
        system("pause");
        main();
    }
}


void adminMenu(){
    system("cls");
    int n;
    
    printf("================= WELCOME ADMIN =================");
    printf("\n\n1. View Student Data\n2. Add the type of education\n3. Add study package\n4. Add study schedule\n5. Calculate the salaries of administrators and teachers\n6. Review the administrative salary\n7. Add helpdesk\n8. Back\n\n");
    printf("Select menu : "); scanf("%d", &n); getchar();

    switch (n){
    case 1 :
        seestudentData();
        break;
    case 2 :
        addeduLevels();
        break;
    case 3 :
        addstuPackage();
        break;
    case 4 :
        addstuSchedule1();
        break;
    case 5 :
        salaryData();
        break;
    case 6 :
        salaryAdmin();
        break;
    case 7 :
        admin_hd();
        break;
    case 8 :
        printf("\nAre you sure? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            main();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            adminMenu();
        }
        break;
    default:
        printf("\nThe option is not available, please select again!");
        loading(3);
        adminMenu();
        break;
    }
}


void seestudentData(){
    loading(3);
    system("cls");
    int j, i = 1;

    printf("================= WELCOME ADMIN =================\n\n");
    printf("================= Student Data =================\n\n");
    studentdata = fopen("Student Data.dat","rb");
    while(fread(&studat, sizeof(studat), 1, studentdata)==1){
        printf("Data - %d \n", i);
        printf("-----------------------------------\n");
        printf("Email \t\t\t : %s \n", studat.email);
        printf("Name \t\t\t : %s \n", studat.name);
        printf("Phone Number \t\t : %s \n", studat.phone_num);
        printf("Address \t\t : %s \n", studat.address);
        printf("Education Levels \t : %s \n", studat.edulevels);
        printf("Study Package \t\t : %s \n", studat.stupack);
        printf("Study Teacher \t\t : %s \n", studat.stuteach);
        printf("Study Schedule \t\t : %s \n", studat.day);
        printf("Shift Study Schedule \t : %s \n", studat.shift);
        printf("Status \t\t\t : %s \n\n", studat.cstatus);
        i++;
        j = 1;
    }
    fclose(studentdata);
    if(j == 0){
        printf("The student data was not found\n\n");
        system("pause");
        adminMenu();
    } 
    system("pause");
    adminMenu();
}


void addeduLevels(){
    loading(3);
    system("cls");
    int n, i, j = 1, x = 0, z = 1;
    
    printf("================= WELCOME ADMIN =================\n\n");
    printf("======== Add Educational Qualifications ========\n\n");
    teacherdata = fopen("Teacher Data.dat", "rb");
    while(fread(&teadat, sizeof(teadat), 1, teacherdata)==1){
        printf("Teacher - %d \n", z);
        printf("-----------------------------------\n");
        printf("Your Name\t\t: %s \n", teadat.name);
        printf("Your Level of Education : %s \n", teadat.edulevels);
        printf("Your Subject\t\t: %s \n\n", teadat.subject);
        x = 1;
        z++;
    }
    if(x == 0){
        printf("There are no available teachers, please come back later!\n\n");
        system("pause");
        adminMenu();
    }
    else {
        coursedata1 = fopen("Course Data1.dat", "ab");
        printf("The amount of educational levels : "); scanf("%d", &n); getchar();
        printf("\nNote :\nMake sure the input education level matches the availability of teachers above!\n");
        printf("-----------------------------------");
        for(i=0; i<n; i++){
            printf("\nEducation level %d \t: ", i+1);
            gets(coudata1.edulevels);
            fwrite(&coudata1, sizeof(coudata1), 1, coursedata1);
        }
        fclose(coursedata1);
        loading(3);
        system("cls");
        coursedata1 = fopen("Course Data1.dat", "rb");
        printf("Successfully advancing in education!!\n\n");
        printf("==============================================");
        printf("\n\nPlease review again!!\n");
        while(fread(&coudata1, sizeof(coudata1), 1, coursedata1)==1){
            printf("%d. \t%s \n",j, coudata1.edulevels);
            j++;
        }
        fclose(coursedata1);
        printf("\nIs it already in accordance? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            adminMenu();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            printf("\nJust leave it as is, alright? So I don't have extra work because I want to go on vacation, ehe :)\n\n");
            system("pause");
            printf("\n\n");
            adminMenu();
        }
    }
}


void addstuPackage(){
    loading(3);
    system("cls");
    char choose[10];
    int i, j = 1, x = 0, y = 0, z = 1;

    printf("================= WELCOME ADMIN =================\n\n");
    printf("============= Add Learning Package =============\n\n");
    teacherdata = fopen("Teacher Data.dat", "rb");
    while(fread(&teadat, sizeof(teadat), 1, teacherdata)==1){
        printf("Teacher - %d \n", z);
        printf("-----------------------------------\n");
        printf("Your Name\t\t: %s \n", teadat.name);
        printf("Your Level of Education : %s \n", teadat.edulevels);
        printf("Your Subject\t\t: %s \n\n", teadat.subject);
        x = 1;
        z++;
    }
    if(x == 0){
        printf("There are no available teachers, please come back later!\n\n");
        system("pause");
        adminMenu();
    }
    else {
        coursedata1 = fopen("Course Data1.dat", "rb");
        printf("The following are the education levels that have been added : \n");
        while(fread(&coudata1, sizeof(coudata1), 1, coursedata1)==1){
            printf("%d. %s \n",j, coudata1.edulevels);
            j++;
        }
        fclose(coursedata1);
        printf("\nNote :\nMake sure the learning package input and the teacher's name are in line with the availability of teachers above!\n");
        printf("-----------------------------------\n");
        printf("Select the education level to add learning packages and prices : "); gets(choose);
        coursedata1 = fopen("Course Data1.dat", "rb");
        while(fread(&coudata1, sizeof(coudata1), 1, coursedata1)==1){
            if(strcmp(choose, coudata1.edulevels)==0){
                y = 1;
            } 
        }
        fclose(coursedata1);
        
        if(y == 0){
            printf("\nThe option is not available, please select again!\n\n");
            system("pause");
            addstuPackage();
        }

        else {
            coursedata2 = fopen("Course Data2.dat", "ab"); 
            printf("\n");
            strcpy(coudata2.edulevels, choose);
            printf("Learning objectives \t: "); gets(coudata2.stupack);
            printf("Subject teacher \t: "); gets(coudata2.stuteach);
            printf("Price \t\t\t: "); scanf("%f", &coudata2.price); getchar();
            
            fwrite(&coudata2, sizeof(coudata2),1,coursedata2);
            fclose(coursedata2);

            printf("\nDo you want to add study packages and prices again? (y/n) : "); gets(fix);
            if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
                addstuPackage();
            }
            else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
                j = 1;
                loading(3);
                system("cls");
                coursedata2 = fopen("Course Data2.dat", "rb");
                printf("The learning package and price have been successfully added!!\n\n");
                printf("==============================================");
                printf("\n\nPlease review again!!\n\n");
                while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
                    printf("%d. \t%s\n",j, coudata2.edulevels);
                    printf("\tLearning objectives \t: %s\n", coudata2.stupack);
                    printf("\tSubject teacher \t: %s\n", coudata2.stuteach);
                    printf("\tPrice \t\t\t: %.2f\n\n", coudata2.price);
                    j++;
                }
                fclose(coursedata2);
                system("pause");
                adminMenu();
            }
        }
    }
}


void addstuSchedule1(){
    loading(3);
    system("cls");
    int i, n, x, j = 1;

    scheduledata1 = fopen("Schedule Data1.dat", "ab");
    printf("================= WELCOME ADMIN =================\n\n");
    printf("============== Add Study Schedule ==============\n\n");
    printf("1. Add days to the study schedule?\n2. Add shifts to the study schedule?\n\n");
    printf("Select menu : "); scanf("%d", &x); getchar();

    switch (x){
        case 1 :
            loading(3);
            system("cls");
            printf("================= WELCOME ADMIN =================\n\n");
            printf("============== Add Study Schedule ==============\n\n");
            printf("How many days would you like to add to the study schedule : "); scanf("%d", &n); getchar();
            for(i=0; i<n; i++){
                printf("\nDay %d \t: ", i+1); gets(schdata1.day);
                fwrite(&schdata1, sizeof(schdata1), 1, scheduledata1);
            }
            fclose(scheduledata1);
            loading(3);
            system("cls");
            scheduledata1 = fopen("Schedule Data1.dat", "rb");
            printf("Successfully added study schedule day!!\n\n");
            printf("==============================================");
            printf("\n\nPlease review again!!\n");
            while(fread(&schdata1, sizeof(schdata1), 1, scheduledata1)==1){
                printf("%d. \t%s \n",j, schdata1.day);
                j++;
            }
            fclose(scheduledata1);

            printf("\nIs it already in accordance? (y/n) : "); gets(fix);
            if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
                loading(3);
                addstuSchedule2();
            }
            else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
                printf("\nJust leave it as is, alright? So I don't have extra work because I want to go on vacation, ehe :)\n\n");
                system("pause");
                printf("\n\n");
                addstuSchedule2();
            }
            break;
        case 2 :
            loading(3);
            addstuSchedule2();
            break;
        default:
            printf("\nThe option is not available, please select again!");
            loading(3);
            addstuSchedule1();
            break;
    }
}

void addstuSchedule2(){
    system("cls");
    char choose[10], ns[50];
    int i, n, j = 1, x = 0;
    printf("================= WELCOME ADMIN =================\n\n");
    printf("============== Add Study Schedule ==============\n\n");
    scheduledata1 = fopen("Schedule Data1.dat", "rb");
    printf("Information about the available study schedule for the day : \n");
    while(fread(&schdata1, sizeof(schdata1), 1, scheduledata1)==1){
        printf("%d. %s \n",j, schdata1.day);
        j++;
    }
    fclose(scheduledata1);
    printf("-----------------------------------\n\n");
    printf("Information about shift format (every 2 hours): \n");
    printf("\nShift 1 : SHIFT 1 (09.00 - 11.00)\nShift 2 : SHIFT 2 (19.00 - 21.00)\n");
    printf("-----------------------------------\n\n");
    printf("Choose the day to add a shift : "); gets(choose);
    scheduledata1 = fopen("Schedule Data1.dat", "rb");
    while(fread(&schdata1, sizeof(schdata1), 1, scheduledata1)==1){
        if(strcmp(choose, schdata1.day)==0){
            x = 1;
        } 
    }
    fclose(scheduledata1);
    
    if(x == 0){
        loading(3);
        printf("\nThe option is not available, please select again!\n\n");
        system("pause");
        addstuSchedule1();
    }

    else {
        scheduledata2 = fopen("Schedule Data2.dat", "ab");
        printf("\nHow many shifts are added on day %s : ", choose); scanf("%d", &n); getchar();
        strcpy(schdata2.day, choose);
        for(i=0; i<n; i++){
            fflush(stdin);
            printf("\nShift %d : ", i+1); gets(schdata2.shift);
            fwrite(&schdata2, sizeof(schdata2), 1,scheduledata2);
        }
        fclose(scheduledata2);

        printf("\nDo you want to add another study schedule shift? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            addstuSchedule2();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            j = 1;
            loading(3);
            system("cls");
            scheduledata2 = fopen("Schedule Data2.dat", "rb");
            printf("The study schedule shift has been successfully added!!\n\n");
            printf("==============================================");
            printf("\n\nPlease review again!!\n\n");
            while(fread(&schdata2, sizeof(schdata2), 1,scheduledata2)==1){
                printf("%d. \t%s\n",j, schdata2.day);
                for(i=0; i<n; i++){
                    printf("\t%s", schdata2.shift);
                    printf("\n");
                }
                j++;
            }
            fclose(scheduledata2);
            printf("\n");
            system("pause");
            adminMenu();
        }
    }
}


void salaryData(){
    loading(3);
    system("cls");
    char select1[50], select2[50];
    int j, y = 0, i = 1, z = 0, x = 0;
    float aprice, tsal, asal;

    printf("================= WELCOME ADMIN =================\n\n");
    printf("============= Calculate the Salary =============\n\n");
    studentdata = fopen("Student Data.dat", "rb");
    printf("Please Review the order again!!\n\n");
    while(fread(&studat, sizeof(studat), 1, studentdata)==1){
        printf("Data - %d \n", i);
        printf("-----------------------------------\n");
        printf("Email \t\t\t : %s \n", studat.email);
        printf("Name \t\t\t : %s \n", studat.name);
        printf("Phone Number \t\t : %s \n", studat.phone_num);
        printf("Address \t\t : %s \n", studat.address);
        printf("Education Levels \t : %s \n", studat.edulevels);
        printf("Study Package \t\t : %s \n", studat.stupack);
        printf("Study Teacher \t\t : %s \n", studat.stuteach);
        printf("Study Schedule \t\t : %s \n", studat.day);
        printf("Shift Study Schedule \t : %s \n", studat.shift);
        printf("Status \t\t\t : %s \n\n", studat.cstatus);
        i++;
    }
    fclose(studentdata);

    studentdata = fopen("Student Data.dat", "rb");
    while(fread(&studat, sizeof(studat), 1, studentdata)==1){
        if(strcmp("LUNAS", studat.cstatus)==0){
            strcpy(select1, studat.stuteach);
            strcpy(select2, studat.stupack);
            y = 1;
        }
    }

    if(y == 0){
        printf("None of the students have fully paid their bills yet\n\n");
        system("pause");
        fclose(studentdata);
        adminMenu();
    } 
    else {
        fclose(studentdata);
        coursedata2 = fopen("Course Data2.dat", "rb");
        while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
            if(strcmp(select2, coudata2.stupack)==0 && strcmp(select1, coudata2.stuteach)==0){
                aprice += coudata2.price;
            }
        }
        fclose(coursedata2); 
        printf("Currently processing calculations, please wait!\n");
        loading(3);
    }
    salarydata1 = fopen("Salary Data1.dat", "wb+");
    long size = ftell(salarydata1);
    if(size == 0){
        saldata1.aprice = aprice;
        fwrite(&saldata1, sizeof(saldata1), 1, salarydata1);
        fclose(salarydata1);
    }
    salarydata1 = fopen("Salary Data1.dat", "rb");
    while(fread(&saldata1, sizeof(saldata1), 1, salarydata1)==1){
        printf("Total income : Rp %.2f", saldata1.aprice);
    }
    fclose(salarydata1);

    printf("\n\nDo you want to see your salary (Admin)? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        salaryAdmin();
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        loading(3);
        adminMenu();
    }
}


void salaryAdmin(){
    loading(3);
    system("cls");
    int i;
    float aprice;

    printf("================= WELCOME ADMIN =================\n\n");
    printf("============= See the Salary Admin =============\n\n");
    
    salarydata1 = fopen("Salary Data1.dat", "rb");
    while(fread(&saldata1, sizeof(saldata1), 1, salarydata1)==1){
        aprice = saldata1.aprice;
        i = 1;
    }
    fclose(salarydata1);

    if(i == 0){
        printf("Your salary (Admin) has not been processed yet\n\nDo you want to proceed with the calculation process? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            salaryData();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            adminMenu();
        }
    } 
    else {
        salarydata = fopen("Salary Data.dat", "ab+");
        fpos_t pos;
        fgetpos(salarydata, &pos);
        saldata.salmin = 0.4*aprice;
        fwrite(&saldata, sizeof(saldata),1, salarydata);
        fclose(salarydata);

        salarydata = fopen("Salary Data.dat", "rb");
        while(fread(&saldata, sizeof(saldata), 1, salarydata)==1){
            printf("Your salary (Admin) : Rp %.2f\n", saldata.salmin);
        }
        fclose(salarydata);
    }

    printf("-----------------------------------\n");
    printf("\nIs that all for the salary, besides it's cheap LoL\nNow, do you want to go back to the admin menu? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        loading(3);
        adminMenu();
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        printf("\nPlease just go back, there's nothing else that can be done here :)\n\n");
        system("pause");
        adminMenu();
    }
}


void admin_hd(){
    loading(3);
    system("cls");
    int i, j = 1, n;
    float aprice;

    printf("================= WELCOME ADMIN =================\n\n");
    printf("============= Add Helpdesk for D'course =============\n\n");

    helpdesk = fopen("Helpdesk.dat", "ab+");
    printf("How many questions would you like to add : ");
    scanf("%d",&n);getchar();

    for(i = 0; i < n; i++){
        printf("\nQuestion - %d \t: ", i+1);
        gets(hd.question);
        printf("Answer - %d \t: ", i+1);
        gets(hd.answer);
        fwrite(&hd, sizeof(hd), 1, helpdesk);
    }
    fclose(helpdesk);
    printf("Question and answer successfully added!!\n\n");
    printf("==============================================");
    printf("\n\nPlease review again!!\n\n");
    helpdesk = fopen("Helpdesk.dat", "rb");
    while(fread(&hd, sizeof(hd), 1, helpdesk)==1){
        printf("\n%d. \t%s\n", j, hd.question);
        printf("\t%s\n", hd.answer);
        j++;
    }
    fclose(helpdesk);
    printf("\n\nIs the addition to the helpdesk sufficient? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        loading(3);
        adminMenu();
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        admin_hd();
    }
}


void mainpageTeacher(){
    system("cls");
    int n;

    printf("================= WELCOME TEACHER =================");
    printf("\n\n1. Sign Up\n2. Login\n3. Back\n\n");
    printf("Select menu : "); scanf("%d", &n); getchar();

    switch (n){
    case 1 :
        teacherRegist();
        break;
    case 2 :
        loading(3);
        system("cls");
        loginTeacher(3);
        break;
    case 3 :
        printf("\nAre you sure? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            main();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            mainpageTeacher();
        }
        break;
    default:
        printf("\nThe option is not available, please select again!");
        loading(3);
        mainpageTeacher();
        break;
    }
}


void teacherRegist(){
    loading(3);
    system("cls");

    teacherdata = fopen("Teacher Data.dat", "ab");
    printf("================= WELCOME TEACHER =================\n\n");
    printf("Please Input Your Data !!\n\n");
    printf("Your Email\t\t: "); gets(teadat.email);
    printf("Your Name\t\t: "); gets(teadat.name);
    printf("Your Phone Number\t: "); gets(teadat.phone_num);
    printf("Your Address\t\t: "); gets(teadat.address);
    printf("Your Gender\t\t: "); gets(teadat.gender);
    printf("Your Age\t\t: "); gets(teadat.age);
    printf("Your Level of Education : "); gets(teadat.edulevels);
    printf("Your Subject\t\t: "); gets(teadat.subject);
    printf("Username\t\t: "); gets(teadat.uname);
    printf("Password\t\t: "); gets(teadat.pass);

    fwrite(&teadat, sizeof(teadat), 1, teacherdata);
    fclose(teacherdata);

    loading(3);
    printf("Your data has been successfully saved\n\n");
    system("Pause");
    mainpageTeacher();
}


void loginTeacher(int n){
    int x = 0;

    printf("\n================= LOGIN TEACHER =================\n\n");
    printf("Username : ");
    gets(unameTeacher);
    printf("Password : ");
    gets(passTeacher);
    loading(3);

    teacherdata = fopen("Teacher Data.dat", "rb"); 
    if(x == 0){
        if(n > 1){
            while(fread(&teadat, sizeof(teadat), 1, teacherdata)==1){
                if(strcmp(unameTeacher, teadat.uname)==0){
                    if(strcmp(unameTeacher, teadat.uname)==0 && strcmp(passTeacher, teadat.pass)==0){
                        fclose(teacherdata); 
                        strcpy(name, teadat.name); 
                        return teacherMenu(name);
                    }
                    else if(strcmp(unameTeacher, teadat.uname)==0 && strcmp(passTeacher, teadat.pass)!=0){
                        printf("Please check Your Password !! \n");
                        fclose(teacherdata);
                        loginTeacher(n-1);
                    }
        
                }
                else if(strcmp(passTeacher, teadat.pass)==0){
                    printf("Please check Your Username!! \n");
                    fclose(teacherdata);
                    loginTeacher(n-1);
                } 
                else x=1;
            }
        } 
        else { 
            printf("Your chance has run out, please return to the teacher's main menu page!!\n\n");
            fclose(teacherdata); 
            system("pause");
            mainpageTeacher(); 
        }
    }
    
    if(x == 1){
        printf("Please check Your Username and Your Password !! \n");
        fclose(teacherdata);
        loginTeacher(n-1);
    }
    fclose(teacherdata);
}


void teacherMenu(char t[50]){
    system("cls");
    int n;

    printf("================= WELCOME %s =================\n\n", t);
    printf("1. See the list of students in the class\n2. Give feedback to the students\n3. Check the teacher's salary\n4. Back\n\n");
    printf("Select menu : "); scanf("%d", &n); getchar();
    
    switch (n){
    case 1 :
        seelistStu(name);
        break;
    case 2 :
        feedback(name);
        break;
    case 3 :
        seesalTeach(name);
        break;
    case 4 :
        printf("\nAre you sure? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            main();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            teacherMenu(name);
        }
        break;
    default:
        printf("\nThe option is not available, please select again!");
        loading(3);
        teacherMenu(name);
        break;
    }
}


void seelistStu(char t[50]){
    loading(3);
    system("cls");
    int i = 1, j = 1, x = 0;

    printf("================= WELCOME %s =================\n\n", name);
    printf("============= See the List Data Student =============\n\n");
    studentdata = fopen("Student Data.dat","rb");
    while(fread(&studat, sizeof(studat), 1, studentdata)==1){
        if(strcmp(studat.stuteach, name)==0){
            x = 1;
        }
        i++;
    }
    fclose(studentdata);

    if(x == 0){
        printf("You don't have any students in your class yet\n\n");
        system("pause");
        teacherMenu(name);
    }
    else {
        studentdata = fopen("Student Data.dat","rb");
        while(fread(&studat, sizeof(studat), 1, studentdata)==1){
            if(strcmp(studat.stuteach, name)==0){
                printf("Student - %d \n", j);
                printf("-----------------------------------\n");
                printf("Name \t\t\t : %s \n", studat.name);
                printf("Phone Number \t\t : %s \n", studat.phone_num);
                printf("Education Levels \t : %s \n", studat.edulevels);
                printf("Study Package \t\t : %s \n", studat.stupack);
                printf("Study Teacher \t\t : %s \n", studat.stuteach);
                printf("Study Schedule \t\t : %s \n", studat.day);
                printf("Shift Study Schedule \t : %s \n\n", studat.shift);
                x = 1;
            }
            j++;
        }
    }
    fclose(studentdata);
    system("pause");
    teacherMenu(name);
}


void feedback(char t[50]){
    loading(3);
    system("cls");
    char choose[50], revchoose[50];
    int i = 1, j = 0, x = 0, y = 1;

    printf("================= WELCOME %s =================\n\n", name);
    printf("============= Add Student Reviews and Feedback =============\n\n");

    studentdata = fopen("Student Data.dat","rb");
    while(fread(&studat, sizeof(studat), 1, studentdata)==1){
        if(strcmp(studat.stuteach, name)==0){
            x = 1;
        }
        i++;
    }
    fclose(studentdata);

    if(x == 0){
        printf("You don't have any students in your class yet\n\n");
        system("pause");
        teacherMenu(name);
    }
    else {
        printf("Here is the list of students in your class : \n\n");
        studentdata = fopen("Student Data.dat","rb");
        while(fread(&studat, sizeof(studat), 1, studentdata)==1){
            if(strcmp(studat.stuteach, name)==0){
                printf("Student - %d \n", y);
                printf("-----------------------------------\n");
                printf("Name \t\t\t : %s \n", studat.name);
                printf("Phone Number \t\t : %s \n", studat.phone_num);
                printf("Education Levels \t : %s \n", studat.edulevels);
                printf("Study Package \t\t : %s \n", studat.stupack);
                printf("Study Teacher \t\t : %s \n", studat.stuteach);
                printf("Study Schedule \t\t : %s \n", studat.day);
                printf("Shift Study Schedule \t : %s \n\n", studat.shift);
            }
            else {
                printf("You don't have any students in your class yet\n\n");
                system("pause");
                teacherMenu(name);
            }
            y++;
        }
        fclose(studentdata);

        printf("Who do you want to give your review and feedback to? ");
        gets(choose);
        studentdata = fopen("Student Data.dat","rb");
        while(fread(&studat, sizeof(studat), 1, studentdata)==1){
            if(strcmp(choose, studat.name)==0){
                strcpy(choose, studat.name);
            }
        }
        fclose(studentdata);

        ref = fopen("RevFeedback.dat", "ab+");
        fpos_t pos;
        fgetpos(ref, &pos);
        strcpy(reback.teachname, name);
        strcpy(reback.name, choose);
        printf("\nReview and feedback for %s : \n", choose); gets(reback.message);
        fseek(ref, 0, SEEK_END);
        fwrite(&reback, sizeof(reback),1, ref);
        fclose(ref);
        loading(3);
        system("cls");
        ref = fopen("RevFeedback.dat","rb");
        printf("Successfully added review and feedback for %s from, %s!!\n\n", choose, name);
        printf("==============================================");
        printf("\n\nPlease review again!!");
        while(fread(&reback, sizeof(reback), 1, ref)==1){
            printf("\n\n%s\n\n", reback.message);
            j++;
        }
        fclose(ref);

        printf("Is the content of the review and feedback correct? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            teacherMenu(name);
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            system("cls");
            printf("Alright then, what is the name of the student whose review and feedback you want to delete? "); gets(revchoose);
            printf("\nOkay, please wait!\n");
            loading(3);
            ref = fopen("RevFeedback.dat","rb");
            revref = fopen("Rev RevFeedback.dat", "ab");
            while(fread(&reback, sizeof(reback), 1, ref)==1){
                if(strcmp(reback.name, revchoose)!=0){
                    fwrite(&revrefback, sizeof(revrefback), 1, revref);
                }
                j++;
            }
            fclose(ref);
            fclose(revref);
            remove("RevFeedback.dat");
            rename("Rev RevFeedback.dat","RevFeedback.dat");

            printf("Previous reviews and feedback have been successfully deleted, please fill them in again with focus, okay? (y/n) : "); gets(fix);
            if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
                feedback(name);
            }
            else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
                printf("\nPlease make sure to fill it in, for the evaluation of the student in their learning process!\n\n");
                system("pause");
                feedback(name);
            }
        }
    }
}


void seesalTeach(char t[50]){
    loading(3);
    system("cls");
    char select1[50];
    int i, y = 0;
    float aprice, aprices;

    printf("================= WELCOME %s =================\n\n", name);
    printf("============= See the Salary Teacher =============\n\n");
    studentdata = fopen("Student Data.dat", "rb");
    while(fread(&studat, sizeof(studat), 1, studentdata)==1){
        if(strcmp("LUNAS", studat.cstatus)==0 && strcmp(name, studat.stuteach)==0){
            strcpy(select1, studat.stupack);
            y = 1;
        }
    }

    if(y == 0){
        printf("None of the students have fully paid their bills yet\n\n");
        system("pause");
        fclose(studentdata);
        teacherMenu(name);
    } 
    else {
        fclose(studentdata);
        coursedata2 = fopen("Course Data2.dat", "rb");
        while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
            if(strcmp(select1, coudata2.stupack)==0 && strcmp(name, coudata2.stuteach)==0){
                aprice += coudata2.price;
            }
        }
        fclose(coursedata2); 
        printf("Currently processing calculations, please wait!\n");
        loading(3);
    }

    salarydata1 = fopen("Salary Data1.dat", "rb");
    while(fread(&saldata1, sizeof(saldata1), 1, salarydata1)==1){
        aprices = saldata1.aprice;
        i = 1;
    }
    fclose(salarydata1);

    if(i == 0){
        printf("Admin has not calculated your salary yet. Would you like to go to another menu? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            teacherMenu(name);
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            printf("\nPlease come back and continue teaching, there's nothing here anymore!\n\n");
            system("pause");
            teacherMenu(name);
        }
    } 
    else {
        salarydata = fopen("Salary Data.dat", "rb+");
        // fpos_t pos;
        // fgetpos(salarydata, &pos);
        saldata.salteach = 0.6*aprice;
        fwrite(&saldata, sizeof(saldata),1, salarydata);
        fclose(salarydata);

        salarydata = fopen("Salary Data.dat", "rb");
        while(fread(&saldata, sizeof(saldata), 1, salarydata)==1){
            printf("\nYour salary : Rp %.2f\n", saldata.salteach);
        }
        fclose(salarydata);
    }

    printf("-----------------------------------\n");
    printf("\nWould you like to return to the teacher menu? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        loading(3);
        teacherMenu(name);
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        printf("\nPlease come back and continue teaching, there's nothing here anymore!\n\n");
        system("pause");
        teacherMenu(name);
    }
}


void mainpageStudent(){
    system("cls");
    int n;

    printf("================= WELCOME STUDENT =================");
    printf("\n\n1. Sign Up\n2. Login\n3. Back\n\n");
    printf("Select menu : "); scanf("%d", &n); getchar();

    switch (n){
    case 1 :
        studentRegist();
        break;
    case 2 :
        loading(3);
        system("cls");
        loginStudent(3);
        break;
    case 3 :
        printf("\nAre you sure? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            main();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            mainpageStudent();
        }
        break;
    default:
        printf("\nThe option is not available, please select again!");
        loading(3);
        mainpageStudent();
        break;
    }
}


void studentRegist(){
    loading(3);
    system("cls");

    studentdata = fopen("Student Data.dat", "ab+");
    // long int data_size = ftell(studentdata);
    // rewind(studentdata);
    fpos_t pos;
    fgetpos(studentdata, &pos);
    // fseek(studentdata, 0, SEEK_END);
    printf("================= WELCOME STUDENT =================\n\n");
    printf("Please Input Your Data !!\n\n");
    printf("Your Email\t\t: "); gets(studat.email);
    printf("Your Name\t\t: "); gets(studat.name);
    printf("Your Phone Number\t: "); gets(studat.phone_num);
    printf("Your Address\t\t: "); gets(studat.address);
    printf("Username\t\t: "); gets(studat.uname);
    printf("Password\t\t: "); gets(studat.pass);
    fseek(studentdata, 0, SEEK_END);
    fwrite(&studat, sizeof(studat),1, studentdata);
    fclose(studentdata);

    loading(3);
    printf("Your data has been successfully saved\n\n");
    system("Pause");
    mainpageStudent();
}


void loginStudent(int n){
    int x = 0;

    printf("\n================= LOGIN STUDENT =================\n\n");
    printf("Username : ");
    gets(unameStudent);
    printf("Password : ");
    gets(passStudent);
    loading(3);

    studentdata = fopen("Student Data.dat", "rb"); 
    if(x == 0){
        if(n > 1){
            while(fread(&studat, sizeof(studat), 1, studentdata)==1){
                if(strcmp(unameStudent, studat.uname)==0){
                    if(strcmp(unameStudent, studat.uname)==0 && strcmp(passStudent, studat.pass)==0){
                        fclose(studentdata); 
                        strcpy(name, studat.name); 
                        studentMenu(name);
                    }
                    else if(strcmp(unameStudent, studat.uname)==0 && strcmp(passStudent, studat.pass)!=0){
                        printf("Please check Your Password !! \n");
                        fclose(studentdata);
                        loginStudent(n-1);
                    }
        
                }
                else if(strcmp(passStudent, studat.pass)==0){
                    printf("Please check Your Username!! \n");
                    fclose(studentdata);
                    loginStudent(n-1);
                } 
                else x=1;
            }
        } 
        else { 
            printf("Your chance has run out, please return to the student's main menu page!!\n\n");
            fclose(studentdata); 
            system("pause");
            mainpageStudent(); 
        }
    }
    
    if(x == 1){
        printf("Please check Your Username and Your Password !! \n");
        fclose(studentdata);
        loginStudent(n-1);
    }
    fclose(studentdata);
}


void studentMenu(char s[50]){
    system("cls");
    int n;

    printf("================= WELCOME %s =================\n\n", s);
    printf("1. See the learning package\n2. Order learning package\n3. Learning package payment\n4. Choose a study schedule\n5. See reviews and feedback\n6. Helpdesk\n7. Back\n\n");
    printf("Select menu : "); scanf("%d", &n); getchar();
    
    switch (n){
    case 1 :
        seelearnPack(name);
        break;
    case 2 :
        chooselearnPack(name);
        break;
    case 3 :
        learnpackPay(name);
        break;
    case 4 :
        chooseSch(name);
        break;
    case 5 :
        seeref(name);
        break;
    case 6 :
        helpDesk(name);
        break;
    case 7 :
        printf("\nAre you sure? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            loading(3);
            main();
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            studentMenu(name);
        }
        break;
    default:
        printf("\nThe option is not available, please select again!");
        loading(3);
        studentMenu(name);
        break;
    }
}


void seelearnPack(char s[50]){
    loading(3);
    system("cls");
    int x, j = 1;

    printf("================= WELCOME %s =================\n\n", s);
    printf("============== See Learning Package ==============\n\n");
    coursedata2 = fopen("Course Data2.dat", "rb");
    while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
        printf("%d. \t%s\n",j, coudata2.edulevels);
        printf("\tLearning objectives \t: %s\n", coudata2.stupack);
        printf("\tSubject teacher \t: %s\n", coudata2.stuteach);
        printf("\tPrice \t\t\t: %.2f\n\n", coudata2.price);
        j++;
    }
    fclose(coursedata2);
    printf("Do you want to place an order for the study package? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        chooselearnPack(name);
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        loading(3);
        studentMenu(name);
    }
}


void chooselearnPack(char s[50]){
    loading(3);
    system("cls");
    char chooselev[50], choosepack[50], select1[50], select2[50], select3[50], select4[50], select5[50], select6[50], select7[50], select8[50];
    int i, j = 1, x = 0, y = 0;

    coursedata1 = fopen("Course Data1.dat", "rb");
    printf("================= WELCOME %s =================\n\n", s);
    printf("============== See Learning Package ==============\n\n");
    while(fread(&coudata1, sizeof(coudata1), 1, coursedata1)==1){
        printf("%d. %s \n",j, coudata1.edulevels);
        j++;
    }
    fclose(coursedata1);

    printf("\nChoose the education level : "); gets(chooselev);
    coursedata2 = fopen("Course Data2.dat", "rb");
    while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
        if(strcmp(chooselev, coudata2.edulevels)==0){
            printf("-----------------------------------\n");
            printf("Learning objectives \t: %s\n", coudata2.stupack);
            printf("Subject teacher \t: %s\n", coudata2.stuteach);
            printf("Price \t\t\t: %.2f\n\n", coudata2.price);
            x = 1;
        } 
    }
    fclose(coursedata2);
    
    if(x == 0){
        loading(3);
        printf("\nThe option is not available, please select again!\n\n");
        system("pause");
        addstuPackage();
    }

    else {
        // sortdata1(chooselev);
        printf("\nChoose the type of learning package : "); gets(choosepack);
        coursedata2 = fopen("Course Data2.dat", "rb");
        while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
            if(strcmp(coudata2.stupack,choosepack)==0){
                y = 1;
            }
        }
        fclose(coursedata2);

        if(y == 0){
            loading(3);
            printf("\nThe option is not available, please select again!\n\n");
            system("pause");
            chooselearnPack(name);
        } 
        else {
            studentdata = fopen("Student Data.dat", "rb");
            // Fseek di bawah sblmnya dipake
            fseek(studentdata, 0, SEEK_SET);
            while(fread(&studat, sizeof(studat), 1, studentdata)==1){
                if(strcmp(studat.name,name)==0){ 
                    strcpy(select1, studat.name);
                    strcpy(select2, studat.phone_num);
                    strcpy(select3, studat.email);
                    strcpy(select4, studat.address);
                }
            }
            fclose(studentdata);

            coursedata2 = fopen("Course Data2.dat", "rb");
            order = fopen("List Order.dat", "ab");
            // fseek(order, 0, SEEK_SET);
            // fset dan fsetpos di bawah sebelumnya dipake
            fpos_t pos;
            fgetpos(studentdata, &pos);
            while(fread(&coudata2, sizeof(coudata2), 1, coursedata2)==1){
                if(strcmp(coudata2.stupack,choosepack)==0){
                    strcpy(listorder.edulevels, coudata2.edulevels);
                    strcpy(choosepack, coudata2.stupack);
                    strcpy(listorder.stupack, coudata2.stupack);
                    strcpy(listorder.stuteach, coudata2.stuteach);
                    listorder.price=coudata2.price;
                    listorder.status=0;
                    strcpy(listorder.cstatus, "BELUM LUNAS");
                    strcpy(listorder.name,select1);
                    strcpy(listorder.phone_num,select2);
                    strcpy(listorder.email,select3);
                    strcpy(listorder.address,select4);
                    // Fseek di bwh sblmnya dipake
                    fseek(order, 0, SEEK_END);
                    fwrite(&listorder, sizeof(listorder), 1, order);
                }
            }
            fclose(coursedata2);
            fclose(order);

            order = fopen("List Order.dat", "rb");
            studentdata = fopen("Student Data.dat", "rb+");
            while(fread(&listorder, sizeof(listorder), 1, order)==1){
                if(strcmp(listorder.name,name)==0){
                    // fread(&studat, sizeof(studat), 1, studentdata);
                    // studat.status=0;
                    strcpy(select8, listorder.stuteach);
                    strcpy(select7, listorder.cstatus);
                    strcpy(select6,listorder.stupack);
                    strcpy(select5,listorder.edulevels);
                    strcpy(studat.edulevels,select5);
                    strcpy(studat.stupack,select6);
                    strcpy(studat.cstatus,select7);
                    strcpy(studat.stuteach, select8);
                    // INII SUMBERNYAA, FIX
                    // Jadi, untuk data ke-1 tanpa seek_end ini, kalau untuk data stlhnya, hrs pake ini krna mode rb+ nnti bkl hps data dri atas klo ga make seek_end. Kalau make seek_End, dia bakal nulis di data baru (data ke-2), cuma nnti klo ada rb+ lg ya brrti bakal nmbh data ke-3 (misal rb+ nya di nmbh schedule dll).
                    // Fseek di bwh dblmnya dipake
                    fseek(studentdata, 0, SEEK_SET);
                    fwrite(&studat, sizeof(studat), 1, studentdata);
                }
            }
            fclose(order);
            fclose(studentdata);

            loading(3);
            printf("Your order has been received. Please proceed to the payment stage!!\n\n");
        }
        printf("Do you want to proceed to the payment stage? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            system("cls");
            learnpackPay(name);
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            studentMenu(name);
        }
    }
}


void learnpackPay(char s[50]){
    loading(3);
    system("cls");
    int x = 0, y = 0;
    float amount = 0, pay = 0;

    printf("================= WELCOME %s =================\n\n", s);
    printf("=========== Learning Package Payment ===========\n\n");
    order =fopen("List Order.dat","rb");
    while(fread(&listorder, sizeof(listorder), 1, order)==1){
        if(strcmp(listorder.name,name)==0){
            if(listorder.status==0){
                printf("Here is your learning package order: ");
                printf("\n\nThe learning package you have chosen : %s", listorder.stupack);
                printf("\n\nYour subject teacher \t\t  : %s", listorder.stuteach);
                printf("\nThe price of the learning package : Rp %.2f\n", listorder.price);
                x = 1;
                amount += listorder.price;
            }
            y = 1;  
        }
    }

    if(y == 0){
        printf("The order history is not available\n\n");
        system("pause");
        fclose(order);
        studentMenu(name);
    } 
    else {
        fclose(order);
        if(x == 1){
            studentdata = fopen("Student Data.dat","rb");
            studentdata1 = fopen("Student Data1.dat", "ab");
            printf("\nEnter the payment amount \t : Rp "); scanf("%f", &pay); getchar();

            if(pay > amount){
                loading(3);
                while(fread(&studat, sizeof(studat), 1, studentdata)==1){
                    if(studat.status==0 && strcmp(studat.name,name)==0){
                        if(strcmp(studat.cstatus,"BELUM LUNAS")!=0){
                            // Fseel di bwh sblmnya dipake
                            // fseek(studentdata, 0, SEEK_END);
                            fwrite(&studat, sizeof(studat), 1, studentdata1);
                        }
                    }
                    else {
                        printf("\n\nYour order has been paid in full. Please place another order or browse our other menus!!\n\n");
                        system("pause");
                        studentMenu(name);
                    }
                }
                fclose(studentdata);
                fclose(studentdata1);
                remove("Student Data.dat");
                rename("Student Data1.dat","Student Data.dat");

                studentdata = fopen("Student Data.dat","rb+");
                studat.status = 1;
                strcpy(studat.cstatus, "LUNAS");
                // Fseek di bwh sblmny dipake
                fseek(studentdata, 0, SEEK_SET);
                fwrite(&studat, sizeof(studat), 1, studentdata);
                fclose(studentdata);

                printf("\nPayment successful\nYour change is : Rp %.2f\n", pay-amount);
                printf("\n\nThank you for completing the payment for the learning package\n");
                printf("Next, would you like to proceed to the scheduling selection stage for your lessons? (y/n) : "); gets(fix);
                if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
                    loading(3);
                    chooseSch(name);
                }
                else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
                    loading(3);
                    studentMenu(name);
                }
            } 
            else if (pay == amount){
                loading(3);
                while(fread(&studat, sizeof(studat), 1, studentdata)==1){
                    if(studat.status==0 && strcmp(studat.name,name)==0){
                        if(strcmp(studat.cstatus,"BELUM LUNAS")!=0){
                            fwrite(&studat, sizeof(studat), 1, studentdata1);
                        }
                    }
                    else {
                        printf("\n\nYour order has been paid in full. Please place another order or browse our other menus!!\n\n");
                        system("pause");
                        studentMenu(name);
                    }
                }
                fclose(studentdata);
                fclose(studentdata1);
                remove("Student Data.dat");
                rename("Student Data1.dat","Student Data.dat");

                studentdata = fopen("Student Data.dat","ab");
                studat.status = 1;
                strcpy(studat.cstatus, "LUNAS");
                // Fseek di bwh sblmnya dipake
                fseek(studentdata, 0, SEEK_SET);
                fwrite(&studat, sizeof(studat), 1, studentdata);
                fclose(studentdata);

                printf("Thank you for completing the payment for the learning package\n\n");
                printf("Next, would you like to proceed to the scheduling selection stage for your lessons? (y/n) : "); gets(fix);
                if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
                    chooseSch(name);
                }
                else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
                    loading(3);
                    studentMenu(name);
                }
            }
            else {
                loading(3);
                printf("\nPayment failed to process due to insufficient funds of: Rp %.2f\n\nPlease make the payment again.\n\n", amount-pay);
                system("pause");
                learnpackPay(name); 
            }
        }
        else {
            loading(3);
            studentMenu(name); 
        }
    }
}


void chooseSch(char s[50]){
    loading(3);
    system("cls");
    char chooseday[50], chooseshift[50], select1[50], select2[50];
    int i, j = 1, x = 0, y = 0;

    scheduledata2 = fopen("Schedule Data2.dat", "rb");
    printf("================= WELCOME %s =================\n\n", s);
    printf("========== Study Schedule Selection ==========\n\n");
    while(fread(&schdata2, sizeof(schdata2), 1, scheduledata2)==1){
        printf("%d. \t%s\n",j, schdata2.day);
        printf("\t%s", schdata2.shift);
        printf("\n");
        j++;
    }
    fclose(scheduledata2);

    printf("\nChoose a study schedule day : "); gets(chooseday);
    printf("-----------------------------------\n\n");
    scheduledata2 = fopen("Schedule Data2.dat", "rb");
    while(fread(&schdata2, sizeof(schdata2), 1, scheduledata2)==1){
        if(strcmp(chooseday, schdata2.day)==0){
            printf("The available shifts on that day are : %s\n", schdata2.shift);
            x = 1;
        } 
    }
    fclose(scheduledata2);
    
    if(x == 0){
        loading(3);
        printf("\nThe option is not available, please select again!\n\n");
        system("pause");
        chooseSch(name);
    }

    else {
        // sortdata1(chooselev);
        printf("\nChoose your study schedule shift : "); gets(chooseshift);
        scheduledata2 = fopen("Schedule Data2.dat", "rb");
        while(fread(&schdata2, sizeof(schdata2), 1, scheduledata2)==1){
            if(strcmp(schdata2.shift,chooseshift)==0){
                y = 1;
            }
        }
        fclose(scheduledata2);

        if(y == 0){
            loading(3);
            printf("\nThe option is not available, please select again!\n\n");
            system("pause");
            chooseSch(name);
        } 
        else {
            scheduledata2 = fopen("Schedule Data2.dat", "rb");
            order = fopen("List Order.dat", "rb+");
            while(fread(&schdata2, sizeof(schdata2), 1, scheduledata2)==1){
                if(strcmp(schdata2.shift,chooseshift)==0){
                    strcpy(listorder.day, schdata2.day);
                    strcpy(listorder.shift, schdata2.shift);
                    fwrite(&listorder, sizeof(listorder), 1, order);
                }
            }
            fclose(scheduledata2);
            fclose(order);
            loading(3);
            printf("Your order has been successful. Thank you for trusting D'COURSE and happy learning!!!\n\n");
        }

        order = fopen("List Order.dat", "rb");
        while(fread(&listorder, sizeof(listorder), 1, order)==1){
            if(strcmp(listorder.name,name)==0){ 
                strcpy(select1, listorder.day);
                strcpy(select2, listorder.shift);
            }
        }
        fclose(order);
        
        order = fopen("List Order.dat", "rb");
        studentdata = fopen("Student Data.dat", "rb+");
        while(fread(&listorder, sizeof(listorder), 1, order)==1){
            if(strcmp(listorder.name,name)==0){
                // long int data_size = ftell(studentdata);
                // rewind(studentdata);
                // fpos_t pos;
                // fgetpos(studentdata, &pos);
                strcpy(studat.day,select1);
                strcpy(studat.shift,select2);
                fseek(studentdata, 0, SEEK_SET);
                fwrite(&studat, sizeof(studat), 1, studentdata);
            }
        }
        fclose(order);
        fclose(studentdata);

        printf("Do you want to see the details of your order? (y/n) : "); gets(fix);
        if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
            system("cls");
            studentdata = fopen("Student Data.dat","rb");
            while(fread(&studat, sizeof(studat), 1, studentdata)==1){
                if(strcmp(studat.name, name)==0){
                    printf("\nYour Order, %s \n", name);
                    printf("-----------------------------------\n");
                    printf("Education Levels \t : %s \n", studat.edulevels);
                    printf("Study Package \t\t : %s \n", studat.stupack);
                    printf("Study Teacher \t\t : %s \n", studat.stuteach);
                    printf("Study Schedule \t\t : %s \n", studat.day);
                    printf("Shift Study Schedule \t : %s \n", studat.shift);
                    printf("Status \t\t\t : %s \n\n", studat.cstatus);
                }
            }
            fclose(studentdata);
            system("pause");
            studentMenu(name);
        }
        else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
            loading(3);
            studentMenu(name);
        }
    }
}


void seeref(char s[50]){
    loading(3);
    system("cls");
    int j = 0;

    printf("================= WELCOME %s =================\n\n", s);
    printf("============== See Review and Feedback ==============\n\n");
    ref = fopen("RevFeedback.dat","rb");
    printf("Review and feedback for you, %s\n\n",name);
    while(fread(&reback, sizeof(reback), 1, ref)==1){
        if(strcmp(reback.name, name)==0){
            printf("From, %s : ",reback.teachname);
            printf("\n%s\n", reback.message);
            printf("-----------------------------------\n\n");
        }
        j++;
    }
    fclose(ref);
    printf("\nHave you seen the review and feedback? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        printf("\nAlright, when you're done, keep up the spirit for learning, okay!\n\n");
        system("pause");
        studentMenu(name);
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        printf("\nThere's nothing here anymore, let's just go back to the student menu!\n\n");
        system("pause");
        studentMenu(name);
    }
}


void helpDesk(char s[50]){
    loading(3);
    system("cls");

    printf("================= WELCOME %s =================\n\n", s);
    printf("============== See Helpdesk ==============\n\n");
    system("cls");
    int j = 1;

    printf("Here is a collection of dcourse usage guidelines :\n");
    helpdesk = fopen("Helpdesk.dat", "rb");
    while(fread(&hd, sizeof(hd), 1, helpdesk)==1){
        printf("\n%d. \t%s\n", j, hd.question);
        printf("\t%s\n", hd.answer);
        j++;
    }
    fclose(helpdesk);
    printf("\nHas the question you wanted to know been answered? (y/n) : "); gets(fix);
    if(strcmp(fix,"y")==0 || strcmp(fix,"Y")==0 || strcmp(fix,"yes")==0 || strcmp(fix,"YES")==0){
        loading(3);
        studentMenu(name);
    }
    else if(strcmp(fix,"n")==0 || strcmp(fix,"N")==0 || strcmp(fix,"no")==0 || strcmp(fix,"NO")==0){
        printf("\nOkay, I will let the admin know later, please be patient ( even though you're the admin yourself :) )\n\n");
        system("pause");
        studentMenu(name);
    }
}


void loading(int n){
    int m;
    printf("\nLoading");
    for(m=0; m<n; m++){
        printf(".");
        fflush(stdout);
        usleep(700 * 1000);
    }
    printf("\n\n");
}


// void sortdata1(char sort[50]){
//     struct CourseData2 stupackage[50]; 
//     int count = 0;
//     coursedata2 = fopen("Course Data2.dat","rb"); 
    
//     while(fread(&stupackage[count],sizeof(struct CourseData2),1, coursedata2)==1){
//         count++;
//     }
//     fclose(coursedata2);
//     sortdata2(stupackage, count);
//     sortdata3(stupackage, count, sort);
// }


// void sortdata2(struct CourseData2 stupackage[], int n){
//     int i, j;
//     struct CourseData2 temp;

//     for (i=0; i<n-1; i++) {
//         for (j=i+1; j<n; j++) {
//             if (stupackage[i].price > stupackage[j].price) {
//                 temp = stupackage[i];
//                 stupackage[i] = stupackage[j];
//                 stupackage[j] = temp;
//             }
//         }
//     }
// }


// void sortdata3(struct CourseData2 stupackage[], int n, char type[50]){
//     int i, j, x = 1;
//     printf("Data untuk kendaraan %s : \n", type);
//     for (i=0; i<n; i++){
//         printf("%d. \t%s\n", i+1, type);
//         for (j=0; j<n; j++) {
//             if (strcmp(stupackage[j].edulevels, type) == 0) {
//                 printf("\tLearning Package : %s\n", stupackage[j].stupack);
//                 printf("\tPrice \t\t : %.2f\n\n", stupackage[j].price);
//                 x++;
//             }
//         }
//         printf("-----------------------------------\n\n");
//     }
// }
