#include <stdio.h>
#include <string.h>


#define MAX_USERS 3
#define MAX_MONTHS 12


struct month {
    int month[MAX_MONTHS];
};


struct tracker {
    char name[30];
    int total_money[MAX_MONTHS];
    int money_used[MAX_MONTHS];
    int saving[MAX_MONTHS];
    struct month m;
};


struct tracker track_person[MAX_USERS];


// Function prototypes
void ExpDe(struct tracker track_person[], int n);
void expdeM(struct tracker track_person[], int n);
void expdeY(struct tracker track_person[], int n);
void Summary(struct tracker track_person[], int n);
void SummaryM(struct tracker track_person[], int n);
void updateM(struct tracker track_person[], int n);
void uptotal(struct tracker track_person[], int n);
int totalSaving(struct tracker track_person[], int n);
void percentageAmountSaved(struct tracker track_person[], int n);


void ExpDe(struct tracker track_person[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter User Name %d: ", i + 1);
        scanf(" %[^\n]", track_person[i].name);
       
        // Initialize all arrays to 0
        for (int j = 0; j < MAX_MONTHS; j++) {
            track_person[i].total_money[j] = 0;
            track_person[i].money_used[j] = 0;
            track_person[i].saving[j] = 0;
            track_person[i].m.month[j] = 0;
        }
    }
    printf("Data Stored Successfully!\n");
}


void expdeM(struct tracker track_person[], int n) {
    char u[30];
    printf("Enter User Name: ");
    scanf(" %[^\n]", u);
   
    for (int i = 0; i < n; i++) {
        if (strcmp(u, track_person[i].name) == 0) {
            int num;
            printf("Enter Month Number (1-12): ");
            scanf("%d", &num);
           
            if(num < 1 || num > 12) {
                printf("Invalid month number!\n");
                return;
            }
           
            track_person[i].m.month[num-1] = num;
            printf("Total Amount in Month %d: ", num);
            scanf("%d", &track_person[i].total_money[num-1]);
            printf("Total Amount Used in Month %d: ", num);
            scanf("%d", &track_person[i].money_used[num-1]);
            track_person[i].saving[num-1] = track_person[i].total_money[num-1] - track_person[i].money_used[num-1];
           
            printf("Data Stored Successfully!\n");
            return;
        }
    }
   
    printf("User Not Found!\n");
}


void expdeY(struct tracker track_person[], int n) {
    char u[30];
    printf("Enter User Name: ");
    scanf(" %[^\n]", u);
   
    for (int i = 0; i < n; i++) {
        if (strcmp(u, track_person[i].name) == 0) {
            for (int j = 0; j < 12; j++) {
                printf("Total Amount in Month %d: ", j + 1);
                scanf("%d", &track_person[i].total_money[j]);
                printf("Total Amount Used in Month %d: ", j + 1);
                scanf("%d", &track_person[i].money_used[j]);
                track_person[i].saving[j] = track_person[i].total_money[j] - track_person[i].money_used[j];
                track_person[i].m.month[j] = j + 1;
            }
            printf("Data Stored Successfully!\n");
            return;
        }
    }
   
    printf("User Name Not Found!\n");
}


void Summary(struct tracker track_person[], int n) {
    char u[30];
    printf("Enter User Name: ");
    scanf(" %[^\n]", u);
   
    for (int j = 0; j < n; j++) {
        if (strcmp(u, track_person[j].name) == 0) {
            for (int i = 0; i < 12; i++) {
                printf("Month: %d\n", i + 1);
                printf("Total Amount in Month: %d\n", track_person[j].total_money[i]);
                printf("Total Amount Used in Month: %d\n", track_person[j].money_used[i]);
                printf("Savings: %d\n", track_person[j].saving[i]);
            }
            return;
        }
    }
    printf("User Name Not Found!\n");
}


void SummaryM(struct tracker track_person[], int n) {
    char u[30];
    printf("Enter User Name: ");
    scanf(" %[^\n]", u);
   
    for (int j = 0; j < n; j++) {
        if (strcmp(u, track_person[j].name) == 0) {
            int mn;
            printf("Enter Month Number: ");
            scanf("%d", &mn);
           
            if (mn >= 1 && mn <= 12) {
                printf("Month: %d\n", mn);
                printf("Total Amount in Month: %d\n", track_person[j].total_money[mn-1]);
                printf("Total Amount Used in Month: %d\n", track_person[j].money_used[mn-1]);
                printf("Savings: %d\n", track_person[j].saving[mn-1]);
            } else {
                printf("Wrong Month Number!\n");
            }
            return;
        }
    }
    printf("User Name Not Found!\n");
}


void updateM(struct tracker track_person[], int n) {
    char n3[30];
    int n1, n2;
    printf("Enter User Name stored in your Expense Book: ");
    scanf(" %[^\n]", n3);
    printf("Enter Month Number: ");
    scanf("%d", &n1);
    printf("Enter New/Updated Total Money: ");
    scanf("%d", &n2);
   
    int userFound = 0;
   
    for (int i = 0; i < n; i++) {
        if (strcmp(n3, track_person[i].name) == 0) {
            userFound = 1;

            if (n1 >= 1 && n1 <= 12) {
                track_person[i].total_money[n1-1] = n2;
                track_person[i].saving[n1-1] = track_person[i].total_money[n1-1] - track_person[i].money_used[n1-1];
                printf("Updated successfully!\n");
                return;
            }
        }
    }
   
    if (!userFound) {
        printf("User Name Not Found!\n");
    } else {
        printf("Not in Your Record!\n");
    }
}


void uptotal(struct tracker track_person[], int n) {
    char n3[30];
    int n1, n2;
    printf("Enter Name stored in your Expense Book: ");
    scanf(" %[^\n]", n3);
    printf("Enter Month Number: ");
    scanf("%d", &n1);
    printf("Enter New/Updated Monthly Money: ");
    scanf("%d", &n2);
   
    int userFound = 0;
   
    for (int i = 0; i < n; i++) {
        if (strcmp(n3, track_person[i].name) == 0) {
            userFound = 1;
           
            if (n1 >= 1 && n1 <= 12) {
                track_person[i].money_used[n1-1] = n2;
                track_person[i].saving[n1-1] = track_person[i].total_money[n1-1] - track_person[i].money_used[n1-1];
                printf("Updated successfully!\n");
                return;
            }
        }
    }
   
    if (!userFound) {
        printf("User Name Not Found!\n");
    }
}


int totalSaving(struct tracker track_person[], int n) {
    char u[30];
    printf("Enter User Name: ");
    scanf(" %[^\n]", u);
   
    for (int j = 0; j < n; j++) {

        if (strcmp(u, track_person[j].name) == 0) {

            int sum = 0;
            for (int i = 0; i < 12; i++) {
                sum += track_person[j].saving[i];
            }
            return sum;
        }
    }
   
    printf("User Name Not Found!\n");
    return 0;
}


void percentageAmountSaved(struct tracker track_person[], int n) {

    char u[30];
    printf("Enter User Name: ");
    scanf(" %[^\n]", u);
   
    for (int j = 0; j < n; j++) {
        if (strcmp(u, track_person[j].name) == 0) {
            int totalMoney = 0;
            int savedMoney = 0;
           
            for (int i = 0; i < 12; i++) {
                totalMoney += track_person[j].total_money[i];
                savedMoney += track_person[j].saving[i];
            }
           
            if (totalMoney > 0) {
                float percentage = ((float)savedMoney / totalMoney) * 100;
                printf("Percentage of Amount Saved: %.2f%%\n", percentage);
            } else {
                printf("No total money recorded.\n");
            }
            return;
        }
    }
   
    printf("User Name Not Found!\n");
}


int main() {
    printf("\t\t\t------- Welcome To Expense Book [Free Version] -------\n\n");
    printf("\t\t-------------------------------------------------------------------\n\n");
    printf("\t\t Guidelines:\n\n");
    printf("\t\t-> Only 3 User's Data Can be Stored in Free Version\n");
    printf("\t\t-> if You Add More than 3 User then It will automatically store 3 users in Expense Book\n\n");
    printf("\t\t-------------------------------------------------------------------\n\n");
   
    int n;
    printf("How Many Users to Add in Expense Book? (max 3): ");
    scanf("%d", &n);
   
    if (n > MAX_USERS) {
        printf("Only 3 Users' Data Can be Stored in Free Version\n");
        n = MAX_USERS;
    }
   
    ExpDe(track_person, n);
   
    int option;
    int ch;
   
    do {
        printf("\t\t\t----  Menu  ----\n\n");
        printf("\t\t1.Add User in Expense Book\n");
        printf("\t\t2.Add Expense Details - For A Month\n");
        printf("\t\t3.Add Expense Details - For A Year\n");
        printf("\t\t4.Display Expense Details of A Particular Month\n");
        printf("\t\t5.Display All Expense Details As A Summary\n");
        printf("\t\t6.Update Total Money of a Particular Month\n");
        printf("\t\t7.Update Monthly Money Used of a Particular Month\n");
        printf("\t\t8.Calculate Total Savings of A Year\n");
        printf("\t\t9.Calculate Percentage of Amount Saved in a Year\n");
        printf("\t\t10.EXIT\n");
        printf("\n\n");
       
        printf("Enter Your choice: ");
        scanf("%d", &ch);
       
        switch(ch) {
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
                updateM(track_person, n);
                break;
            case 7:
                uptotal(track_person, n);
                break;
            case 8: {
                int sum = totalSaving(track_person, n);
                printf("Total Savings: %d\n", sum);
                break;
            }
            case 9:
                percentageAmountSaved(track_person, n);
                break;
            case 10:
                printf("Exiting Expense Book...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
       
        printf("\nDo you want to continue? (Press any number except 10): ");
        scanf("%d", &option);
       
    } while (option != 10);
   
    return 0;
}

