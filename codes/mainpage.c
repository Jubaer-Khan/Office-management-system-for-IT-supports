#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
struct emp                                                                               ///STRUCTURE FOR EMPLOYEE
{
    char name[40]; ///name of employee
    int age; /// age of employee
    char id[12];/// id of employee
    char expe[40];///  employee in expert
    char conno[12];/// contact no of employee
    char mail[40];/// contact email of employee
    int rat;
    float bs; /// basic salary of employee
};
struct pro                                                                           ///STRUCTURE FOR PROJECT
{
    char name[40]; ///name of Project
    char id[12];///   id of project
    char plat[40];/// project platform
    char concli[12];///contact no of Client
    char status[10];///Project status
    float roy; ///     royalty of project
};
struct acc                                                                           ///STRUCTURE FOR ACCOUNT
{
    int revenue;/// Revenue of account
    int payments;///      Payment
    int officer;///       Office Rent
    int utility;///        utility.
    int profit;///         Profit
    int loss; ///           loss
    char date[30];///         Date
};

COORD coord = {0,0};



void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

main()
{
    int i,check,tot=0;
    char password[8],pass[8]="google21";
    char ch;
    printf("Enter Password(8 Characters):");
    for(i=0; i<8; i++)
    {
        ch=getch();
        password[i]=ch;
        ch='*';
        printf("%c",ch);
    }
    for(i=0; i<8; i++)
    {
        if(password[i]!=pass[i])
            check=0;
        else
            check=1;
    }

    FILE *fp, *ft; /// file pointers
    FILE *fpp, *ftt;
    FILE *fpa, *fta;
    char another, choice,choicep,choicea;

    /** structure that represent a employee */


    struct emp e;/// structure variable for Employee
    struct pro p;/// structure Variable for project
    struct acc a;/// structure variable for account

    char empid[30]; /// string to store name of the employee

    long int recsize; /// size of each record of employee
    if(check==1)
    {
        fp = fopen("EMP.DAT","rb+");                                                                   ///File For Employeee
        if(fp == NULL)
        {
            fp = fopen("EMP.DAT","wb+");
            if(fp == NULL)
            {
                printf("Cannot open file");
                exit(1);
            }
        }
        fpp = fopen("PRO.DAT","rb+");                                                                  ///File For Project
        if(fpp == NULL)
        {
            fpp = fopen("PRO.DAT","wb+");
            if(fpp == NULL)
            {
                printf("Cannot open file");
                exit(1);
            }
        }
        fpa = fopen("ACC.DAT","rb+");                                                                   ///File For Account
        if(fpa == NULL)
        {
            fpa = fopen("ACC.DAT","wb+");
            if(fpa == NULL)
            {
                printf("Cannot open file");
                exit(1);
            }
        }

        /// sizeo of each record i.e. size of structure variable e
        recsize = sizeof(e);
        while(1)
        {
            system("cls"); ///clear the console window
            gotoxy(26,05);
            printf("IT OFFICE MANAGEMENT");
            gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
            printf("1. Employee."); /// option for add record
            gotoxy(30,12);
            printf("2. Projects."); /// option for showing existing record
            gotoxy(30,14);
            printf("3. Accounts."); /// option for editing record
            gotoxy(30,16);
            printf("4. Exit."); /// option for deleting record
            gotoxy(30,18);     /// option for deleting record
            printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
            fflush(stdin); /// flush the input buffer
            choice  = getche(); /// get the input from keyboard
            switch(choice)
            {
            case '1':                                                                                  ///MAIN PAGE CASE 1
                //while(1)
            {
                system("cls"); ///clear the console window
                gotoxy(26,05);
            printf("EMPLOYEE INFORMATION DESK");
                gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                printf("1. Add Record"); /// option for add record
                gotoxy(30,12);
                printf("2. List Records"); /// option for showing existing record
                gotoxy(30,14);
                printf("3. Modify Records"); /// option for editing record
                gotoxy(30,16);
                printf("4. Delete Records"); /// option for deleting record
                gotoxy(30,18);
                printf("5. Exit"); /// exit from the program
                gotoxy(30,20);
                printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
                fflush(stdin); /// flush the input buffer
                choice  = getche(); /// get the input from keyboard
                switch(choice)
                {
                case '1':  /// if user press 1
                    system("cls");
                    fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
                    /// here 0 indicates moving 0 distance from the end of the file

                    another = 'y';
                    while(another == 'y')  /// if user want to add another record
                    {
                        printf("\nEnter name: ");
                        scanf("%s",e.name);
                        printf("\nEnter id: ");
                        scanf("%s",e.id);
                        printf("\nEnter speciality: ");  //
                        scanf("%s",e.expe);
                        printf("\nEnter contact no.: ");   //
                        scanf("%s",e.conno);
                        printf("\nEnter contact email: ");   //
                        scanf("%s",e.mail);
                        printf("\nEnter rating on 10: ");      //
                        scanf("%d", &e.rat);
                        printf("\nEnter age: ");
                        scanf("%d", &e.age);
                        printf("\nEnter basic salary: ");
                        scanf("%f", &e.bs);


                        fwrite(&e,recsize,1,fp); /// write the record in the file

                        printf("\nAdd another record(y/n) ");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '2':
                    system("cls");
                    rewind(fp); ///this moves file cursor to start of the file
                    int l=1;
                    while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
                    {
                        printf("\n%d  Name: %s\n   ID:%s\n   Experience:%s\n   Contact:%s\n   Email:%s\n   Rating%d\n   Age:%d\n   Salary:%.2f\n\n",l,e.name,e.id,e.expe,e.conno,e.mail,e.rat,e.age,e.bs); /// print the name, age and basic salary
                        l++;
                    }
                    getch();
                    break;

                case '3':  /// if user press 3 then do editing existing record
                    system("cls");
                    another = 'y';
                    while(another == 'y')
                    {
                        printf("Enter the employee id to modify: ");
                        scanf("%s", empid);
                        rewind(fp);
                        while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
                        {
                            if(strcmp(e.id,empid) == 0)  ///if entered name matches with that in file
                            {
                                printf("\nEnter new name,age and bs: ");
                                scanf("%s%s%s%s%d%d%f",e.name,e.expe,e.conno,e.mail,&e.rat,&e.age,&e.bs);
                                fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                                fwrite(&e,recsize,1,fp); /// override the record
                                break;
                            }
                        }
                        printf("\nModify another record(y/n)");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '4':
                    system("cls");
                    another = 'y';
                    while(another == 'y')
                    {
                        printf("\nEnter id of employee to delete: ");
                        scanf("%s",empid);
                        ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                        rewind(fp); /// move record to starting of file
                        while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
                        {
                            if(strcmp(e.id,empid) != 0)  /// if the entered record match
                            {
                                fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                            }
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("EMP.DAT"); /// remove the orginal file
                        rename("Temp.dat","EMP.DAT"); /// rename the temp file to original file name
                        fp = fopen("EMP.DAT", "rb+");
                        printf("Delete another record(y/n)");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '5':
                    fclose(fp);  /// close the file
                    break; /// Break from the Employee SWITCH
                }
            }

            break;

            case '2':                                                                                  ///MAIN PAGE CASE 2.
                //  while(1)
            {
                system("cls"); ///clear the console window

                 gotoxy(26,05);
            printf("PROJECT INFORMATION DESK");
                gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                printf("1. Add Project."); /// option for add record
                gotoxy(30,12);
                printf("2. List Current Projects."); /// option for showing existing record
                gotoxy(30,14);
                printf("3. List Previous Projects."); /// option for editing record
                gotoxy(30,16);
                printf("4. Delete Records."); /// option for deleting record
                gotoxy(30,18);
                printf("5. Modify Records."); /// exit from the program
                gotoxy(30,20);
                printf("6.Exit."); /// exit from the program
                gotoxy(30,22);
                printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
                fflush(stdin); /// flush the input buffer
                choicep  = getche(); /// get the input from keyboard
                switch(choicep)
                {
                case '1':  /// if user press 1
                    system("cls");
                    fseek(fpp,0,SEEK_END); /// search the file and move cursor to end of the file
                    /// here 0 indicates moving 0 distance from the end of the file

                    another = 'y';
                    while(another == 'y')  /// if user want to add another record
                    {
                        printf("\nEnter Project name: ");
                        scanf("%s",p.name);
                        printf("\nEnter Project id: ");
                        scanf("%s",p.id);
                        printf("\nEnter Project Platform: ");  //
                        scanf("%s",p.plat);
                        printf("\nEnter Client contact no.: ");   //
                        scanf("%s",p.concli);
                        printf("\nEnter Project Status: ");   //
                        scanf("%s",p.status);
                        printf("\nEnter Royalty: ");
                        scanf("%f", &p.roy);


                        fwrite(&p,sizeof(p),1,fpp); /// write the record in the file

                        printf("\nAdd another record(y/n) ");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '2':
                    system("cls");
                    rewind(fpp); ///this moves file cursor to start of the file
                    int l=1;
                    while(fread(&p,sizeof(p),1,fpp)==1)  /// read the file and fetch the record one record per fetch
                    {
                        if(strcmp(p.status,"in")==0)
                        {
                            printf("\n%d Project Name: %s\n  Project ID:%s\n   Project Platform:%s\n  Client Contact:%s\n   Project Status:%s\n   Royalty:%.2f\n\n",l,p.name,p.id,p.plat,p.concli,p.status,p.roy); /// print Project Info
                            l++;
                        }
                    }
                    getch();
                    break;

                case '3':  /// if user press 3 then do editing existing record
                    system("cls");
                    rewind(fpp); ///this moves file cursor to start of the file
                    int lp=1;
                    while(fread(&p,sizeof(p),1,fpp)==1)  /// read the file and fetch the record one record per fetch
                    {
                        if(strcmp(p.status,"in")!=0)
                        {
                            printf("\n%d Project Name: %s\n  Project ID:%s\n   Project Platform:%s\n  Client Contact:%s\n   Project Status:%s\n   Royalty:%.2f\n\n",lp,p.name,p.id,p.plat,p.concli,p.status,p.roy); /// print Project Info
                            lp++;
                        }

                    }
                    getch();
                    break;
                case '4':
                    system("cls");
                    another = 'y';
                    while(another == 'y')
                    {
                        printf("\nEnter id of employee to delete: ");
                        scanf("%s",empid);
                        ftt = fopen("Tempp.dat","wb");  /// create a intermediate file for temporary storage
                        rewind(fpp); /// move record to starting of file
                        while(fread(&p,sizeof(p),1,fpp) == 1)  /// read all records from file
                        {
                            if(strcmp(p.id,empid) != 0)  /// if the entered record match
                            {
                                fwrite(&p,sizeof(p),1,ftt); /// move all records except the one that is to be deleted to temp file
                            }
                        }
                        fclose(fpp);
                        fclose(ftt);
                        remove("PRO.DAT"); /// remove the orginal file
                        rename("Tempp.dat","EMP.DAT"); /// rename the temp file to original file name
                        fpp = fopen("PRO.DAT", "rb+");
                        printf("Delete another record(y/n)");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '5':
                    system("cls");
                    another = 'y';
                    while(another == 'y')
                    {
                        printf("Enter the Project id to modify: ");
                        scanf("%s", empid);
                        rewind(fpp);
                        while(fread(&p,sizeof(p),1,fpp)==1)  /// fetch all record from file
                        {
                            if(strcmp(p.id,empid) == 0)  ///if entered name matches with that in file
                            {
                                printf("\nEnter Project Status: ");
                                scanf("%s",p.status);
                                fseek(fpp,-sizeof(p),SEEK_CUR); /// move the cursor 1 step back from current position
                                fwrite(&p,sizeof(p),1,fpp); /// override the record
                                break;
                            }
                        }
                        printf("\nModify another record(y/n)");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '6':
                    fclose(fpp);/// close the file
                    getch();
                    break; /// Break PROJECT SWITCH
                }
            }
            break;
            case '3':                                                                                      ///MAIN CASE 3
            {
                system("cls"); ///clear the console window
                gotoxy(26,05);
            printf("ACCOUNT INFORMATION DESK");
                gotoxy(30,10); /// move the cursor to postion 30, 10 from top-left corner
                printf("1. Add Record"); /// option for add record
                gotoxy(30,12);
                printf("2. List Records"); /// option for showing existing record
                gotoxy(30,14);
                printf("3. Delete Records"); /// option for deleting record
                gotoxy(30,16);
                printf("4. Exit"); /// exit from the program
                gotoxy(30,18);
                printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
                fflush(stdin); /// flush the input buffer
                choicea  = getche(); /// get the input from keyboard
                switch(choicea)
                {
                case '1':  /// if user press 1
                    system("cls");
                    fseek(fpa,0,SEEK_END); /// search the file and move cursor to end of the file
                    /// here 0 indicates moving 0 distance from the end of the file

                    another = 'y';
                    while(another == 'y')  /// if user want to add another record
                    {
                        printf("\nEnter Revenue: ");
                        scanf("%d",&a.revenue);
                        printf("\nEnter Employee Payments: ");
                        scanf("%d",&a.payments);
                        printf("\nEnter Office Rent: ");  //
                        scanf("%d",&a.officer);
                        printf("\nEnter Utility Bills.: ");   //
                        scanf("%d",&a.utility);
                        printf("\nEnter Date: ");
                        scanf("%s",a.date);
                        tot=a.revenue-a.payments-a.officer-a.utility;
                        if(tot>=0)
                        {
                            a.profit=tot;
                            a.loss=0;
                        }
                        else if(tot<0)
                        {
                            a.loss=tot;
                            a.profit=0;
                        }

                        //printf("Total=%d\n  Profit=%d\n Loss=%d",tot,a.profit,a.loss);*/
                        fwrite(&a,sizeof(a),1,fpa); /// write the record in the file

                        printf("\n Add another record(y/n)");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '2':
                    system("cls");
                    rewind(fpa); ///this moves file cursor to start of the file
                    int la=1;
                    while(fread(&a,sizeof(a),1,fpa)==1)  /// read the file and fetch the record one record per fetch
                    {

                        printf("\n%d  Revenue: %d\n   Payments:%d\n   Office Rent:%d\n   Utility Bill:%d\n  Profit:%d\n Loss:%d\n Date:%s\n  \n\n",la,a.revenue,a.payments,a.officer,a.utility,a.profit,a.loss,a.date); /// print the name, age and basic salary
                        la++;
                    }
                    getch();
                    break;

                case '3':
                    system("cls");
                    another = 'y';
                    while(another == 'y')
                    {
                        printf("\nEnter Date to delete: ");
                        scanf("%s",empid);
                        fta = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                        rewind(fp); /// move record to starting of file
                        while(fread(&a,sizeof(a),1,fpa) == 1)  /// read all records from file
                        {
                            if(strcmp(a.date,empid) != 0)  /// if the entered record match
                            {
                                fwrite(&a,sizeof(a),1,fta); /// move all records except the one that is to be deleted to temp file
                            }
                        }
                        fclose(fpa);
                        fclose(fta);
                        remove("ACC.DAT"); /// remove the orginal file
                        rename("Temp.dat","ACC.DAT"); /// rename the temp file to original file name
                        fpa = fopen("ACC.DAT", "rb+");
                        printf("Delete another record(y/n)");
                        fflush(stdin);
                        another = getche();
                    }
                    break;
                case '4':
                    fclose(fpa);/// close the file
                    getch();
                    break;
                }
            }
            break;
            case '4':
                exit(0);

            }

        }

    }
    else
        printf("\n\n\nWrong Password!!!!");///End Of First "if".
}///END OF MAIN



