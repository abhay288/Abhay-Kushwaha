Index

1.	Introduction
o	Overview of the Student Data Management System
o	Objectives of the Project
2.	Functional Modules
o	User Registration
o	User Login
o	Record Management
	Insert Record
	Modify Record
	Delete Record
	Display Records
o	User Unregistration
3.	Key Features
o	File-based Data Storage
o	User Authentication
o	Record Modification and Deletion
o	Error Handling
4.	Testing and Debugging
o	Testing
o	Debugging
o	
5.	Implementation Details
o	C Program



6.	Code Structure
o	Main Function
o	Functions Overview
	register_user()
	login_user()
	insert_record()
	modify_record()
	delete_record()
	display_records()
	unregister_user()
7.	Technical Details
o	Programming Language: C
o	Data Storage: File Handling (students.txt, users.txt)
o	Libraries Used: stdio.h, stdlib.h, string.h
8.	Challenges Faced
o	Error Handling
o	Ensuring Data Integrity
9.	Conclusion
o	Summary of Features
o	Future Enhancements
10.	Appendices
o	Code Listings
o	Sample Input and Output




Introduction
OVERVIEW OF THE STUDENT DATA MANAGEMENT SYSTEM
The Student Data Management System is a console-based application developed in C programming. Its purpose is to provide a structured and efficient way to manage student records using simple file handling techniques. The system operates through a user-friendly interface and incorporates the following key functionalities:
1.	User Registration and Authentication:
o	Users are required to register with a username and password, which are securely stored in a file (users.txt).
o	Authentication ensures that only authorized users can access and modify student records.
2.	Record Management Operations:
o	Adding Records: Allows users to create and save new student records, including the student's name and roll number.
o	Modifying Records: Enables editing an existing record's details by searching for it using the roll number.
o	Deleting Records: Provides an option to remove specific records based on the roll number.
o	Viewing Records: Displays all stored student records, helping users review or analyze the data.
3.	Data Storage Using Files:
o	The system uses text files (students.txt and users.txt) for persistent data storage, ensuring that records and credentials are not lost when the program is closed.
4.	Secure and Organized Access:
o	Each operation is secured by user login, and the program ensures data integrity during modifications or deletions.
The system is ideal for small-scale applications, like managing student records in a classroom, where simplicity and functionality are prioritized.
________________________________________

OBJECTIVES OF THE PROJECT
The primary goals of this project are as follows:
1.	To Create a Functional Student Data Management System:
o	Design and implement a practical tool for managing student information efficiently.
o	Incorporate all essential operations like adding, editing, deleting, and viewing records.
2.	To Introduce File Handling Concepts in C:
o	Demonstrate how to read, write, and manipulate text files using file input/output functions (fopen, fclose, fprintf, fscanf, etc.).
o	Handle file operations with proper error handling to ensure reliability.
3.	To Ensure User Authentication:
o	Add a layer of security by requiring users to log in using valid credentials before accessing sensitive operations.
4.	To Demonstrate Modular Programming:
o	Divide the code into small, reusable functions like insert_record(), modify_record(), and delete_record() for better organization and readability.
5.	To Incorporate Error-Handling Techniques:
o	Manage errors gracefully, such as when files are missing, or inputs are invalid.
o	Prevent unauthorized access and ensure the correctness of operations.
6.	To Provide a Foundation for Further Enhancements:
o	Lay the groundwork for future improvements, such as adding features for encrypted passwords, advanced search capabilities, or database integration.




Functional Modules
USER REGISTRATION
Function: register_user()
Allows users to register by providing a username and password. Ensures that a username is unique by checking the users.txt file.
USER LOGIN
Function: login_user()
Authenticates users by matching the username and password from users.txt. Provides access to record management operations upon successful login.
RECORD MANAGEMENT
1.	Insert Record
Function: insert_record()
o	Adds a new student record (name and roll number) to the students.txt file.
o	Ensures multiple records can be added in a single session.
2.	Modify Record
Function: modify_record()
o	Searches for a record by roll number in students.txt.
o	Updates the name and roll number if the record is found.
3.	Delete Record
Function: delete_record()
o	Searches for a record by roll number in students.txt.
o	Deletes the record if found, using a temporary file for rewriting.
4.	Display Records
Function: display_records()
o	Reads and displays all records from students.txt.
o	Displays "No records found!" if the file is empty or missing.
USER UNREGISTRATION
Function: unregister_user()
Removes a user’s credentials from users.txt after verifying their username and password.


Key Features
FILE-BASED DATA STORAGE
•	User data is stored in users.txt.
•	Student records are maintained in students.txt.
USER AUTHENTICATION
Ensures secure access by validating usernames and passwords during login.
RECORD MODIFICATION AND DELETION
Allows dynamic updates to student records with error handling for nonexistent records.
ERROR HANDLING
•	Checks for file availability before operations.
•	Handles scenarios like file opening errors and invalid user input.
















Testing and Debugging
TESTING
Testing ensures the program performs as expected across various scenarios. Key testing areas include:
1.	User Authentication
o	Test valid and invalid login attempts.
o	Verify that unregistered users cannot log in.
2.	Record Management
o	Insert records and confirm they are saved in students.txt.
o	Modify records and ensure updates are correctly reflected.
o	Delete records and check that the correct record is removed.
o	Display records and validate the output format.
3.	Error Handling
o	Test with missing files (students.txt, users.txt).
o	Input invalid or unexpected data, e.g., incorrect roll numbers.
4.	Boundary Testing
o	Check system behavior with no records or a full file.
DEBUGGING
Debugging identifies and resolves issues in the program. Common debugging techniques include:
1.	Print Debugging
o	Use printf statements to trace program flow and monitor variable values.
2.	File Access Debugging
o	Ensure proper file opening and closing to avoid corruption.
o	Check file permissions and paths.
3.	Logical Errors
o	Verify conditions in loops and if-else statements for correctness.
4.	Memory Issues
o	Ensure all resources (e.g., file pointers) are freed/closed correctly.
5.	User Input
o	Validate inputs to prevent unexpected behavior, such as buffer overflows.
Implementation Details
C PROGRAM
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
Code Structure
MAIN FUNCTION
The entry point of the program handles the user menu for registration, login, unregistration, and exiting the application.
FUNCTIONS OVERVIEW
1.	register_user(): Handles user registration by writing new credentials to users.txt.
2.	login_user(): Authenticates users and provides access to the record management menu.
3.	insert_record(): Appends new student records to students.txt.
4.	modify_record(): Updates existing records based on roll number.
5.	delete_record(): Deletes a record based on roll number by rewriting the file.
6.	display_records(): Reads and displays all records from students.txt.
7.	unregister_user(): Deletes a user’s credentials from users.txt.













Technical Details
PROGRAMMING LANGUAGE
C
DATA STORAGE
File Handling
•	users.txt: Stores user credentials (username and password).
•	students.txt: Stores student records (name and roll number).
LIBRARIES USED
•	stdio.h: For input and output operations.
•	stdlib.h: For memory management and general utilities.
•	string.h: For string manipulation functions like strcmp().
















Challenges Faced
ERROR HANDLING
1.	Handling Missing or Corrupt Files:
o	Ensuring the program does not crash when users.txt or students.txt files are missing or corrupted.
o	Displaying appropriate error messages using perror and skipping operations if files are inaccessible.
2.	Ensuring Proper File Closure After Operations:
o	Preventing data loss or file corruption by ensuring all opened files are properly closed using fclose.
o	Managing temporary files (students_temp.txt, users_temp.txt) during modification or deletion to ensure seamless transitions.

ENSURING DATA INTEGRITY
1.	Preventing Overwrites or Duplication of Data During Updates:
o	Avoiding accidental overwriting of student records by carefully validating roll numbers before modification or deletion.
o	Checking for duplicate usernames during registration to maintain data uniqueness.
2.	Securing User Credentials During Login and Unregistration:
o	Ensuring that user credentials in users.txt are stored in plain text (current implementation) but laying a foundation for encrypted password handling.
o	Cross-verifying credentials during login or unregistration to prevent unauthorized actions.



Conclusion
SUMMARY OF FEATURES
The system successfully implements a basic Student Data Management System with the following key features:
•	User Authentication: Validates users with a username and password to restrict access.
•	File-Based Storage: Uses text files (students.txt and users.txt) for persistent and straightforward data storage.
•	Record Management Capabilities: Provides functionalities for adding, editing, deleting, and viewing student records.
•	Error Handling: Manages errors like missing files, invalid inputs, and duplicate data effectively.
FUTURE ENHANCEMENTS
1.	Support for Encrypted Passwords:
o	Improve security by implementing hashing algorithms like SHA256 to store encrypted passwords instead of plain text.
2.	Implementing a Graphical User Interface (GUI):
o	Replace the text-based interface with a more user-friendly GUI using frameworks like GTK (C-based) or porting to a language with better UI capabilities.
3.	Enable Advanced Search Features:
o	Allow searching records by name, roll number, or other fields to enhance usability.





Appendices
CODE LISTINGS
Includes the entire source code of the project.
SAMPLE INPUT AND OUTPUT
1.	User Registration:
o	Input: username = Alice, password = 1234.
o	Output: "User registered successfully!"
2.	Record Management:
o	Input: Insert a record with name = John, roll = 001.
o	Output: "Record inserted successfully!"


