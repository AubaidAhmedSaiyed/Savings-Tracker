// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

#define USERS 3;

struct month
{
    int month[12];
};

struct tracker
{
    char name[30];
    int total_money[12];
    int money_used[12];
    int saving[12];
    struct month m;
};

struct tracker track_person[3];

void ExpDe(struct tracker track_person[], int n);
void expdeM(struct tracker track_person[], int n);
void expdeY(struct tracker track_person[], int n);
void Summary(struct tracker track_person[], int n);
void SummaryM(struct tracker track_person[], int n);
void updateM(struct tracker track_person[], int n);
void uptotal(struct tracker track_person[], int n);
int totalSaving(struct tracker track_person[], int n);
void percentageAmountSaved(struct tracker track_person[], int n);

void ExpDe(struct tracker track_person[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter User Name %d : ", i + 1);
        scanf(" %[^\n]", track_person[i].name);

        for (int j = 0; j < 12; j++)
        {
            track_person[i].total_money[j] = 0;
            track_person[i].money_used[j] = 0;
            track_person[i].saving[j] = 0;
            track_person[i].m.month[j] = 0;
        }
    }

    printf("Data Stored Successfully !\n");
}
void expdeM(struct tracker track_person[], int n)
{
    char u[30];
    printf("Enter User Name:");
    scanf(" %[^\n]", u);
    int userFound = 0;

    for (int i = 0; i < n; i++)
    {

        if (strcmp(u, track_person[i].name) == 0)
        {
            userFound = 1;

            int num;
            printf("Enter Month Number [ 1-12 ]:");
            scanf("%d", &num);

            track_person[i].m.month[num - 1] = num;
            printf("Total Amount in Month %d :", num);
            scanf("%d", &track_person[i].total_money[num - 1]);
            printf("Total Amount Used in Month %d :", num);
            scanf("%d", &track_person[i].money_used[num - 1]);
            track_person[i].saving[num - 1] = (track_person[i].total_money[num - 1]) - (track_person[i].money_used[num - 1]);

            printf("Data Stored Successfully !\n");

            return;
        }
    }

    if (userFound == 0)
    {
        printf("User Not Found !");
    }
}
void expdeY(struct tracker track_person[], int n)
{
    char u[30];
    printf("Enter User Name:");
    scanf(" %[^\n]", u);
    int userFound = 0;
    for (int i = 0; i < n; i++)
    {

        if (strcmp(u, track_person[i].name) == 0)
        {
            userFound = 1;

            for (int j = 0; j < 12; j++)
            {
                printf("Total Amount in Month %d :", j + 1);
                scanf("%d", &track_person[i].total_money[j]);
                printf("Total Amount Used in Month %d :", j + 1);
                scanf("%d", &track_person[i].money_used[j]);
                track_person[i].saving[j] = track_person[i].total_money[j] - track_person[i].money_used[j];
                int a = i + 1;
                a = track_person[i].m.month[j];
            }
            printf("Data Stored Successfully !\n");
            return;
        }
    }
    if (userFound == 0)
    {
        printf("User Not Found !");
    }
}

void Summary(struct tracker track_person[], int n)
{
    char u[30];
    printf("Enter User Name :");
    scanf(" %[^\n]", u);
    int userFound = 0;
    for (int j = 0; j < n; j++)
    {

        if (strcmp(u, track_person[j].name) == 0)
        {
            userFound = 1;

            for (int i = 0; i < 12; i++)
            {

                printf("Month : %d\n", i + 1);
                printf("Total Amount in Month : %d\n", track_person[j].total_money[i]);
                printf("Total Amount Used in Month : %d\n", track_person[j].money_used[i]);
                printf("Savings : %d\n", track_person[j].saving[i]);
            }
            return;
        }
    }
    if (userFound == 0)
    {
        printf("User Not Found !");
    }
}

void SummaryM(struct tracker track_person[], int n)
{
    char u[30];
    printf("Enter User Name :");
    scanf(" %[^\n]", u);
    int userFound = 0;

    for (int j = 0; j < n; j++)
    {

        if (strcmp(u, track_person[j].name) == 0)
        {
            userFound = 1;

            int mn;
            printf("Enter Month Number:");
            scanf("%d", &mn);

            if (mn >= 1 && mn <= 12)
            {
                printf("Month : %d\n", mn);
                printf("Total Amount in Month : %d\n", track_person[j].total_money[mn - 1]);
                printf("Total Amount Used in Month : %d\n", track_person[j].money_used[mn - 1]);
                printf("Savings : %d\n", track_person[j].saving[mn - 1]);
            }
            else
            {
                printf("Wrong Month Number!\n");
            }
            return;
        }
    }

    if (userFound == 0)
    {
        printf("User Not Found !");
    }
}
void updateM(struct tracker track_person[], int n)
{

    int monthN, UpdatedM;
    char userName[30];

    printf("Enter User Name stored in your Expense Book:");
    scanf(" %[^\n]", &userName);

    printf("\nEnter Month Number [ 1-12 ]:");
    scanf("%d", &monthN);

    printf("\nEnter New/Updated Money Used in that month:");
    scanf("%d", &UpdatedM);

    int userFound = 0;

    for (int i = 0; i < n; i++)
    {

        if (strcmp(userName, track_person[i].name) == 0)
            userFound = 1;
        {
            if (monthN >= 1 && monthN <= 12)
            {

                track_person[i].money_used[monthN - 1] = UpdatedM;
                track_person[i].saving[monthN - 1] = track_person[i].total_money[monthN - 1] - track_person[i].money_used[monthN - 1];
                printf("Updated successfully !\n");
                return;
            }
            else
            {
                printf("Not in Your Record !\n");
            }
        }
    }
    if (userFound == 0)
    {
        printf("User Name Not Found!\n");
    }
}

void uptotal(struct tracker track_person[], int n)
{
    int monthN, UpdatedM;
    char userName[30];

    printf("Enter Name stored in your Expense Book:");
    scanf(" %[^\n]", &userName);

    printf("\nEnter Month Number:\n");
    scanf("%d", &monthN);

    printf("\nEnter New/Updated total Money Used:");
    scanf("%d", &UpdatedM);

    int userFound = 0;
    // int monthFound = 0;

    for (int i = 0; i < n; i++)
    {

        if (strcmp(userName, track_person[i].name) == 0)
        {
            userFound = 1;

            if (monthN >= 1 && monthN <= 12)
            {

                // monthFound = 1;

                track_person[i].total_money[monthN - 1] = UpdatedM;
                track_person[i].saving[monthN - 1] = track_person[i].total_money[monthN - 1] - track_person[i].money_used[monthN - 11];

                printf("\nUpdated successfully !\n");
                return;
            }

            // if (monthFound == 0)
            // {
            //     printf("Not in Your Record !\n");
            // }
        }
    }

    if (userFound == 0)
    {
        printf("User Name Not Found!\n");
    }
}

int totalSaving(struct tracker track_person[], int n)
{

    char u[30];
    printf("Enter User Name :");
    scanf(" %[^\n]", &u);

    // int sum = 0;
    // int userFound = 0;

    for (int j = 0; j < n; j++)
    {

        if (strcmp(u, track_person[j].name) == 0)
        {

            int sum = 0;

            for (int i = 0; i < 12; i++)
            {

                sum = sum + track_person[j].saving[i];
            }
            return sum;
        }
    }
        printf("User Name Not Found!\n");
        return 0;
    // if (userFound == 0)
    // {
    
    // }
}
void percentageAmountSaved(struct tracker track_person[], int n)
{

    char u[30];
    printf("Enter User Name :");
    scanf(" %[^\n]", u);

    int total = 0;
    int sumMoney = 0;
    int userFound = 0;

    for (int j = 0; j < n; j++)
    {

        if (strcmp(u, track_person[j].name) == 0)
        {

            userFound = 1;
            for (int i = 0; i < 12; i++)
            {
                total = total + track_person[j].total_money[i];
                sumMoney = sumMoney + track_person[j].saving[i];
            }
            break;
        }
    }
    if (userFound == 0)
    {
        printf("User Name Not Found!\n");
        return;
    }
    if (total > 0)
    {

        float percentage = ((float)sumMoney / total) * 100;

        printf("Percentage of Amount Saved : %.2f %%\n", percentage);
    }
    else
    {
        printf("No total Money Recorded\n");
    }
    return;
}

void main()
{
    // Write C code here
    printf("\t\t\t------- Welcome To  Expense Book [Free Version] -------\n\n");
    printf("\t\t-------------------------------------------------------------------\n\n");
    printf("\t\t Guidelines:\n\n");
    printf("\t\t-> Only 3 User's Data Can be Stored in Free Version\n");
    printf("\t\t-> if You Add More than 3 User then It will automatically store 3 users in Expense Book\n\n");
    printf("\t\t-------------------------------------------------------------------\n\n");
    int n;
    printf("How Many User's to Add in Expense Book ? :");
    scanf("%d", &n);
    if (n > 3)
    {
        printf("Only 3 User's Data Can be Stored in Free Version\n");
        n = 3;
        struct tracker track_person[n];
    }
    else
    {
        struct tracker track_person[n];
    }
    printf("\n");
    int ch;
    // int option;

    do
    {
        printf("\t\t\t----  Menu  ----\n\n");
        printf("\n");
        printf("\t\t1.Add User in Expense Book\n");
        printf("\t\t2.Add Expense Details - For A Month\n");
        printf("\t\t3.Add Expense Details - For A Year\n");
        printf("\t\t4.Display Expense Details of A Particular Month\n");
        printf("\t\t5.Display All Expense Details As A Summary\n");
        printf("\t\t6.Update Total Money of a Particular Month \n");
        printf("\t\t7.Update Monthly Money Used of a Particular Month\n");
        printf("\t\t8.Calculate Total Savings of A Year\n");
        printf("\t\t9.Calculate Percentage of Amount Saved in a Year\n");
        printf("\t\t10.EXIT\n");
        printf("\n\n");

        printf("Enter Your choice:");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            ExpDe(track_person, n);
            break;
        case 2:
            expdeM(track_person, n);
            break;
        case 3:
            expdeY(track_person, n);
            break;
        case 4:
            SummaryM(track_person, n);
            break;
        case 5:
            Summary(track_person, n);
            break;
        case 6:
            uptotal(track_person, n);
            break;
        case 7:
            updateM(track_person, n);
            break;
        case 8:

            printf("Total Savings are : %d", totalSaving(track_person, n));
            break;
        case 9:
            percentageAmountSaved(track_person, n);
            break;
        case 10:
            printf("OK");
            break;
        }

    } while (ch != 10);
}