#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a user
typedef struct User {
    char username[20];
    char password[20];
    char role; // 'A' for admin, 'T' for teacher, 'S' for student
} User;

// Define the structure for a student record
typedef struct Student {
    char studentID[15];
    char name[50];
    int year;
    int course;
    int stream;
    int roll;
    float gpa;
    struct Student *left;
    struct Student *right;
} Student;

// Function to create a new student node
Student *Create(int year, int course, int stream, int roll, const char *name, float gpa) {
    Student *newStudent = (Student *)malloc(sizeof(Student));

    // Generate the student ID
    sprintf(newStudent->studentID, "AP%02d%04d%d%04d", year, course, stream, roll);

    strcpy(newStudent->name, name);
    newStudent->year = year;
    newStudent->course = course;
    newStudent->stream = stream;
    newStudent->roll = roll;
    newStudent->gpa = gpa;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

// Function to insert a student into the BST
Student *Insert(Student *root, int year, int course, int stream, int roll, const char *name, float gpa) {
    if (root == NULL)
        return Create(year, course, stream, roll, name, gpa);

    // Compare student IDs for insertion in the BST
    int comparison = strcmp(Create(year, course, stream, roll, "", 0)->studentID, root->studentID);

    if (comparison < 0)
        root->left = Insert(root->left, year, course, stream, roll, name, gpa);
    else if (comparison > 0)
        root->right = Insert(root->right, year, course, stream, roll, name, gpa);

    return root;
}

// Function to search for a student by ID in the BST
Student *Search(Student *root, const char *studentID) {
    if (root == NULL || strcmp(studentID, root->studentID) == 0)
        return root;

    int comparison = strcmp(studentID, root->studentID);
    if (comparison < 0)
        return Search(root->left, studentID);

    return Search(root->right, studentID);
}

// Function to display student information
void displayStudent(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Student ID: %s\n", student->studentID);
    printf("GPA: %.2f\n", student->gpa);
}

// Function to perform an in-order traversal of the BST
void Traverse(Student *root) {
    if (root != NULL) {
        Traverse(root->left);
        displayStudent(root);
        Traverse(root->right);
    }
}

// Function to modify student information by ID in the BST
void Modify(Student *root, const char *studentID, float newGPA) {
    Student *student = Search(root, studentID);
    if (student != NULL) {
        student->gpa = newGPA;
        printf("Student information modified successfully!\n");
    } else {
        printf("Student with ID %s not found.\n", studentID);
    }
}

// Function to delete a student by ID from the BST
Student *Delete(Student *root, const char *studentID) {
    if (root == NULL)
        return root;

    int comparison = strcmp(studentID, root->studentID);
    if (comparison < 0)
        root->left = Delete(root->left, studentID);
    else if (comparison > 0)
        root->right = Delete(root->right, studentID);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Student *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Student *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Student *temp = FindMin(root->right);
        strcpy(root->studentID, temp->studentID);
        root->right = Delete(root->right, temp->studentID);
    }

    return root;
}

// Helper function to find the node with the minimum value in a BST
Student *FindMin(Student *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to get student details from the user
void getStudentDetails(char *name, int *year, int *course, int *stream, int *roll, float *gpa) {
    printf("Name: ");
    scanf("%s", name);
    printf("Year: ");
    scanf("%d", year);
    printf("Course: ");
    scanf("%d", course);
    printf("Stream: ");
    scanf("%d", stream);
    printf("Roll No: ");
    scanf("%d", roll);
    printf("GPA: ");
    scanf("%f", gpa);
}

// Function to display the menu options based on user role
void displayMenu(char role) {
    printf("Enter 1 to display the Student Database\n");

    if (role == 'A') {
        printf("Enter 2 to Add a Student to the Database\n");
        printf("Enter 3 to Search for a Student in the Database\n");
        printf("Enter 4 to Modify Student Information\n");
        printf("Enter 5 to Delete a Student Record\n");
    }
    else if(role == '')

    printf("Enter 0 to EXIT\n");
    printf("Enter your choice: ");
}

// Function to free memory
void freeMemory(Student *root) {
    if (root != NULL) {
        freeMemory(root->left);
        freeMemory(root->right);
        free(root);
    }
}

int main() {
    // Sample users (you should replace this with a more secure authentication system)
    User users[] = {
        {"admin", "admin123", 'A'},
        {"teacher", "teacher123", 'T'},
        {"student", "student123", 'S'}
    };
    int numUsers = sizeof(users) / sizeof(users[0]);

    char username[20];
    char password[20];
    char role;

    // Get user credentials
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter role (A for admin, T for teacher, S for student): ");
    scanf(" %c", &role);

    // Authenticate user
    if (Authenticate(users, numUsers, username, password, &role)) {
        printf("Authentication successful!\n");

        // Now, you can determine the user's role and show the appropriate menu
        Student *root = NULL;
        int choice;

        do {
            displayMenu(role);

            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Student Records:\n");
                    Traverse(root);
                    break;

                case 2:
                    if (role == 'A') {
                        char name[50];
                        int year, course, stream, roll;
                        float gpa;
                        int n;
                        printf("Enter the no. of students to add: ");
                        scanf("%d", &n);
                        for (int i = 0; i < n; i++) {
                            printf("Enter details of Student %d\n", i + 1);
                            getStudentDetails(name, &year, &course, &stream, &roll, &gpa);
                            root = Insert(root, year, course, stream, roll, name, gpa);
                        }
                        printf("Students added successfully!\n");
                    } else {
                        printf("Permission denied. Only administrators can add students.\n");
                    }
                    break;

                case 3:
                    // Search functionality
                    break;

                case 4:
                    // Modify functionality
                    break;

                case 5:
                    // Delete functionality
                    break;

                case 0:
                    printf("Thank you for using SRMAP Database System\n");
                    freeMemory(root);
                    return 0;

                default:
                    printf("Invalid Choice.\n");
            }
        } while (choice != 0);
    } else {
        printf("Authentication failed. Exiting...\n");
    }

    return 0;
}
