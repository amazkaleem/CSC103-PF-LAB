#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NUM_EXAMS 3

struct Student {
    char name[50];
    int rollNumber;
    int marks[NUM_EXAMS];
};

// Function declarations
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void displayAverage(struct Student students[], int count);
void findTopper(struct Student students[], int count);
void searchByRoll(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Display Average Marks\n");
        printf("4. Find Topper\n");
        printf("5. Search by Roll Number\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(students, &studentCount); break;
            case 2: displayStudents(students, studentCount); break;
            case 3: displayAverage(students, studentCount); break;
            case 4: findTopper(students, studentCount); break;
            case 5: searchByRoll(students, studentCount); break;
            case 6: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}

// Add student details
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Enter marks in 3 subjects:\n");
    for (int i = 0; i < NUM_EXAMS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &students[*count].marks[i]);
    }

    (*count)++;
    printf("Student added successfully.\n");
}

// Display all student info
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nName: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: ");
        for (int j = 0; j < NUM_EXAMS; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\n");
    }
}

// Calculate and display average marks
void displayAverage(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < NUM_EXAMS; j++) {
            total += students[i].marks[j];
        }
        float average = total / (float)NUM_EXAMS;
        printf("Average marks of %s (Roll %d): %.2f\n", students[i].name, students[i].rollNumber, average);
    }
}

// Find student with highest total marks
void findTopper(struct Student students[], int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    int maxTotal = -1, topperIndex = -1;
    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < NUM_EXAMS; j++) {
            total += students[i].marks[j];
        }
        if (total > maxTotal) {
            maxTotal = total;
            topperIndex = i;
        }
    }

    printf("\nTopper: %s (Roll %d) with total marks %d\n",
           students[topperIndex].name,
           students[topperIndex].rollNumber,
           maxTotal);
}

// Search student by roll number
void searchByRoll(struct Student students[], int count) {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nStudent Found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Marks: ");
            for (int j = 0; j < NUM_EXAMS; j++) {
                printf("%d ", students[i].marks[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}
