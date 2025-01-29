#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void insert_record() {
    char name[MAX_LEN], roll[MAX_LEN];
    FILE *file = fopen("students.txt", "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    while (1) {
        printf("\nEnter name: ");
        scanf("%s", name);
        printf("Enter Roll Number: ");
        scanf("%s", roll);
        
        fprintf(file, "%s %s\n", name, roll);
        printf("\nRecord inserted successfully!\n");

        char ans;
        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &ans);
        if (ans != 'y') {
            break;
        }
    }

    fclose(file);
}

void modify_record() {
    char roll_no[MAX_LEN], name[MAX_LEN], roll[MAX_LEN];
    int found = 0;

    printf("\nEnter the Roll Number of the record to modify: ");
    scanf("%s", roll_no);

    FILE *file = fopen("students.txt", "r");
    FILE *temp = fopen("students_temp.txt", "w");

    if (!file || !temp) {
        perror("Error opening file");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    while (fscanf(file, "%s %s", name, roll) != EOF) {
        if (strcmp(roll, roll_no) == 0) {
            found = 1;
            printf("\nEnter new name: ");
            scanf("%s", name);
            printf("Enter new Roll Number: ");
            scanf("%s", roll);
        }
        fprintf(temp, "%s %s\n", name, roll);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("\nRecord modified successfully!\n");
    } else {
        printf("\nRecord not found!\n");
        remove("students_temp.txt");
    }
}

void delete_record() {
    char roll_no[MAX_LEN], name[MAX_LEN], roll[MAX_LEN];
    int found = 0;

    printf("\nEnter the Roll Number of the record to delete: ");
    scanf("%s", roll_no);

    FILE *file = fopen("students.txt", "r");
    FILE *temp = fopen("students_temp.txt", "w");

    if (!file || !temp) {
        perror("Error opening file");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    while (fscanf(file, "%s %s", name, roll) != EOF) {
        if (strcmp(roll, roll_no) == 0) {
            found = 1;
            continue;
        }
        fprintf(temp, "%s %s\n", name, roll);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("students.txt");
        rename("students_temp.txt", "students.txt");
        printf("\nRecord deleted successfully!\n");
    } else {
        printf("\nRecord not found!\n");
        remove("students_temp.txt");
    }
}

void display_records() {
    char name[MAX_LEN], roll[MAX_LEN];

    printf("\nStudent Records:\n");

    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("No records found!\n");
        return;
    }

    while (fscanf(file, "%s %s", name, roll) != EOF) {
        printf("Name: %s\nRoll Number: %s\n\n", name, roll);
    }

    fclose(file);
}

void register_user() {
    char username[MAX_LEN], password[MAX_LEN];
    int exists = 0;

    printf("Enter username: ");
    scanf("%s", username);

    FILE *file = fopen("users.txt", "r");
    if (file) {
        char stored_user[MAX_LEN], stored_pass[MAX_LEN];
        while (fscanf(file, "%s %s", stored_user, stored_pass) != EOF) {
            if (strcmp(username, stored_user) == 0) {
                printf("You are already registered, please login.\n");
                exists = 1;
                break;
            }
        }
        fclose(file);
    }

    if (exists) return;

    printf("Enter password: ");
    scanf("%s", password);

    file = fopen("users.txt", "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);

    printf("User registered successfully!\n");
}

int login_user() {
    char username[MAX_LEN], password[MAX_LEN], stored_user[MAX_LEN], stored_pass[MAX_LEN];
    int logged_in = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("No users found!\n");
        return 0;
    }

    while (fscanf(file, "%s %s", stored_user, stored_pass) != EOF) {
        if (strcmp(username, stored_user) == 0 && strcmp(password, stored_pass) == 0) {
            logged_in = 1;
            break;
        }
    }

    fclose(file);

    if (!logged_in) {
        printf("Login unsuccessful!\n");
        return 0;
    }

    printf("Login successful!\n");

    while (1) {
        int choice;
        printf("\n1. Insert Record\n");
        printf("2. Modify Record\n");
        printf("3. Delete Record\n");
        printf("4. Display Records\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_record();
                break;
            case 2:
                modify_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                display_records();
                break;
            case 5:
                printf("Logging out...\n");
                return 1;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void unregister_user() {
    char username[MAX_LEN], password[MAX_LEN], stored_user[MAX_LEN], stored_pass[MAX_LEN];
    int found = 0;

    printf("Enter username to unregister: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen("users.txt", "r");
    FILE *temp = fopen("users_temp.txt", "w");

    if (!file || !temp) {
        perror("Error opening file");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    while (fscanf(file, "%s %s", stored_user, stored_pass) != EOF) {
        if (strcmp(username, stored_user) == 0 && strcmp(password, stored_pass) == 0) {
            found = 1;
            printf("User unregistered successfully!\n");
            continue;
        }
        fprintf(temp, "%s %s\n", stored_user, stored_pass);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("users.txt");
        rename("users_temp.txt", "users.txt");
    } else {
        printf("User not found!\n");
        remove("users_temp.txt");
    }
}

int main() {
    while (1) {
        int choice;
        printf("\nWelcome to Student Management Record!\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Unregister\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                unregister_user();
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
