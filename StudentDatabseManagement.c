/*
=> Data Structures II Project <=
=> Student Database Management System <=
-Krishna Sharma AP22110010128
-Aryan Kumar AP22110010120
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student
{
    char studentID[20];
    char name[50];
    float gpa;
    char username[20];
    char password[20];
    struct Student *left;
    struct Student *right;
};

// Structure to represent a user (admin or student)
struct Admin
{
    char username[20];
    char password[20];
    int isAdmin;
    struct Student *studentDetails; // Add studentDetails for each user
    struct Admin *left;
    struct Admin *right;
};

// Function prototype for displayStudentDetails
void displayStudentDetails(struct Student *student);

void displayMenu()
{
    printf("\n=== Student Database Management ===\n");
    printf("1. Login as Admin\n");
    printf("2. Login as Student\n");
    printf("3. Display Students\n");
    printf("4. Add Student\n");
    printf("5. Logout\n");
    printf("6. Exit\n");
}

struct Student *insertStudent(struct Student *root, const char *id, const char *name, float gpa, const char *username, const char *password)
{
    if (root == NULL)
    {
        struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
        if (newStudent == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newStudent->studentID, id);
        strcpy(newStudent->name, name);
        newStudent->gpa = gpa;
        strcpy(newStudent->username, username);
        strcpy(newStudent->password, password);
        newStudent->left = newStudent->right = NULL;

        return newStudent;
    }

    if (strcmp(id, root->studentID) < 0)
    {
        root->left = insertStudent(root->left, id, name, gpa, username, password);
    }
    else if (strcmp(id, root->studentID) > 0)
    {
        root->right = insertStudent(root->right, id, name, gpa, username, password);
    }

    return root;
}

void displayStudentsBST(struct Student *root)
{
    if (root != NULL)
    {
        displayStudentsBST(root->left);
        printf("%-15s%-10s%-5.2f\n", root->name, root->studentID, root->gpa);
        displayStudentsBST(root->right);
    }
}

void freeStudentsBST(struct Student *root)
{
    if (root != NULL)
    {
        freeStudentsBST(root->left);
        freeStudentsBST(root->right);
        free(root);
    }
}

struct Admin *insertAdmin(struct Admin *root, const char *username, const char *password, int isAdmin)
{
    if (root == NULL)
    {
        struct Admin *newAdmin = (struct Admin *)malloc(sizeof(struct Admin));
        if (newAdmin == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newAdmin->username, username);
        strcpy(newAdmin->password, password);
        newAdmin->isAdmin = isAdmin;
        newAdmin->studentDetails = NULL; // Initialize studentDetails to NULL
        newAdmin->left = newAdmin->right = NULL;

        return newAdmin;
    }

    if (strcmp(username, root->username) < 0)
    {
        root->left = insertAdmin(root->left, username, password, isAdmin);
    }
    else if (strcmp(username, root->username) > 0)
    {
        root->right = insertAdmin(root->right, username, password, isAdmin);
    }

    return root;
}

void login(struct Admin *root)
{
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    struct Admin *current = root;

    while (current != NULL)
    {
        if (strcmp(username, current->username) == 0 && strcmp(password, current->password) == 0)
        {
            printf("Login successful.\n");
            if (current->isAdmin)
            {
                // Admin is logged in
                printf("Welcome, Admin!\n");
            }
            else
            {
                // Student is logged in
                printf("Welcome, Student!\n");
            }
            return;
        }
        else if (strcmp(username, current->username) < 0)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    printf("Invalid username or password. Please try again.\n");
}

int isAdminLoggedIn(struct Admin *root)
{
    struct Admin *current = root;

    while (current != NULL)
    {
        if (current->isAdmin)
        {
            return 1; // Admin is logged in
        }
        else
        {
            current = current->right; // Go to the right subtree for admins
        }
    }

    printf("You must be logged in as admin to perform this action.\n");
    return 0; // Admin is not logged in
}

// Function to display students
void displayStudents(struct Student *root)
{
    if (root == NULL)
    {
        printf("No students in the database.\n");
    }
    else
    {
        printf("\n=== Student List ===\n");
        printf("%-15s%-10s%-5s\n", "Name", "ID", "GPA");
        displayStudentsBST(root);
        printf("====================\n");
    }
}

// Function prototype for displayStudentDetails
void displayStudentDetails(struct Student *student)
{
    printf("\n=== Student Details ===\n");
    printf("Name: %s\n", student->name);
    printf("ID: %s\n", student->studentID);
    printf("GPA: %.2f\n", student->gpa);
    printf("=======================\n");
}

void addStudent(struct Student **root)
{
    char id[20], name[50], username[20], password[20];
    float gpa;

    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter student GPA: ");
    scanf("%f", &gpa);

    int year, course, stream, roll;
    printf("Enter admission year (e.g., 22 for 2022): ");
    scanf("%d", &year);

    printf("Enter course number: ");
    scanf("%d", &course);

    printf("Enter stream number: ");
    scanf("%d", &stream);

    printf("Enter roll number: ");
    scanf("%d", &roll);

    sprintf(id, "AP%02d%04d%d%04d", year, course, stream, roll);

    printf("Enter student username: ");
    scanf("%s", username);

    printf("Enter student password: ");
    scanf("%s", password);

    *root = insertStudent(*root, id, name, gpa, username, password);

    printf("Student added successfully.\n");
}

void studentLogin(struct Admin *root)
{
    char username[20];
    char password[20];

    printf("Enter student username: ");
    scanf("%s", username);

    printf("Enter student password: ");
    scanf("%s", password);

    struct Admin *current = root;

    while (current != NULL)
    {
        if (strcmp(username, current->username) == 0 && strcmp(password, current->password) == 0 && !current->isAdmin)
        {
            printf("Login successful as student.\n");
            displayStudentDetails(current->studentDetails);
            return;
        }
        else if (strcmp(username, current->username) < 0)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    printf("Invalid student username or password. Please try again.\n");
}

int main()
{
    struct Student *studentRoot = NULL;
    struct Admin *userRoot = NULL;

    userRoot = insertAdmin(userRoot, "admin", "srmap", 1);

    int choice;
    int loggedInAdminIndex = -1;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            login(userRoot);
            loggedInAdminIndex = isAdminLoggedIn(userRoot);
            break;
        case 2:
            studentLogin(userRoot);
            break;
        case 3:
            displayStudents(studentRoot);
            break;
        case 4:
            if (loggedInAdminIndex != -1)
            {
                addStudent(&studentRoot);
            }
            else
            {
                printf("You must be logged in as admin to perform this action.\n");
            }
            break;
        case 5:
            loggedInAdminIndex = -1;
            printf("Logged out successfully.\n");
            break;
        case 6:
            freeStudentsBST(studentRoot);
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
