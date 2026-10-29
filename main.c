
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

// Add a student
void addStudent() {
    if (count >= MAX) {
        printf("\nStudent record limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    // Check for duplicate roll number
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == students[count].rollNo) {
            printf("Roll number already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("\nStudent added successfully!\n");
}

// Display all students
void displayStudents() {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");
    printf("%-12s %-25s %-10s\n", "Roll Number", "Name", "Marks");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-12d %-25s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks);
    }
}

// Search for a student using linear search
void searchStudent() {
    int rollNo;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name       : %s\n", students[i].name);
            printf("Marks      : %.2f\n", students[i].marks);
            return;
        }
    }

    printf("\nStudent not found!\n");
}

// Update student details
void updateStudent() {
    int rollNo;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", students[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nStudent details updated successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

// Delete a student record
void deleteStudent() {
    int rollNo;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("\nStudent record deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

// Sort students by marks using bubble sort
void sortStudents() {
    if (count == 0) {
        printf("\nNo student records to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks > students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by marks in ascending order!\n");
    displayStudents();
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n\n====================================\n");
        printf("   STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by Marks\n");
        printf("7. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please restart the program.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                printf("\nThank you for using the Student Record Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please select 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}
