#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define SUBJECTS 3

typedef struct {
    char name[50];
    float fsc;
    float matric;
    float merit;
    float entryMarks;
    char preferences[SUBJECTS][10]; // Subject preferences
    char assignedSubject[10];       // Final assigned subject
} Student;

typedef struct {
    char name[10];
    int seats;
    int filled;
} Subject;

void calculateMerit(Student* s) {
    s->merit = 0.5 * s->entryMarks + 0.4 * s->fsc + 0.1 * s->matric;
}

void sortStudentsByMerit(Student students[], int n) {
    Student temp;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(students[i].merit < students[j].merit) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    Subject subjects[SUBJECTS] = {
        {"CS", 0, 0},
        {"EE", 0, 0},
        {"SE", 0, 0}
    };

    printf("Enter available seats for CS, EE, SE:\n");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("%s: ", subjects[i].name);
        scanf("%d", &subjects[i].seats);
    }

    // Input student data
    printf("\nEnter details for 15 students:\n");
    for(int i = 0; i < MAX_STUDENTS; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
		// Entry Test Marks (out of 100)
		do {
		    printf("Entry Marks (out of 100): ");
		    scanf("%f", &students[i].entryMarks);
		    if (students[i].entryMarks < 0 || students[i].entryMarks > 100)
		        printf("Invalid input! Entry marks must be between 0 and 100.\n");
		} while (students[i].entryMarks < 0 || students[i].entryMarks > 100);
		
		// FSc Marks (out of 1100)
		do {
		    printf("FSc Marks (out of 1100): ");
		    scanf("%f", &students[i].fsc);
		    if (students[i].fsc < 0 || students[i].fsc > 1100)
		        printf("Invalid input! FSc marks must be between 0 and 1100.\n");
		} while (students[i].fsc < 0 || students[i].fsc > 1100);
		
		// Matric Marks (out of 1100)
		do {
		    printf("Matric Marks (out of 1100): ");
		    scanf("%f", &students[i].matric);
		    if (students[i].matric < 0 || students[i].matric > 1100)
		        printf("Invalid input! Matric marks must be between 0 and 1100.\n");
		} while (students[i].matric < 0 || students[i].matric > 1100);

        printf("Enter 3 subject preferences (CS, EE, SE): ");
        for(int j = 0; j < SUBJECTS; j++) {
            scanf("%s", students[i].preferences[j]);
        }
        calculateMerit(&students[i]);
        strcpy(students[i].assignedSubject, "None");
    }

    // Sort by merit
    sortStudentsByMerit(students, MAX_STUDENTS);

    // Allocate subjects
    for(int i = 0; i < MAX_STUDENTS; i++) {
        for(int j = 0; j < SUBJECTS; j++) {
            for(int k = 0; k < SUBJECTS; k++) {
                if(strcmp(students[i].preferences[j], subjects[k].name) == 0 && subjects[k].filled < subjects[k].seats) {
                    strcpy(students[i].assignedSubject, subjects[k].name);
                    subjects[k].filled++;
                    goto nextStudent;
                }
            }
        }

        // If not assigned in preferences
        printf("\n%s was not allocated any of their preferred subjects.\n", students[i].name);
        printf("Available subjects:\n");
        for(int k = 0; k < SUBJECTS; k++) {
            if(subjects[k].filled < subjects[k].seats) {
                printf("%s ", subjects[k].name);
            }
        }
        printf("\nChoose from available subjects: ");
        char choice[10];
        scanf("%s", choice);
        for(int k = 0; k < SUBJECTS; k++) {
            if(strcmp(choice, subjects[k].name) == 0 && subjects[k].filled < subjects[k].seats) {
                strcpy(students[i].assignedSubject, subjects[k].name);
                subjects[k].filled++;
                break;
            }
        }
    nextStudent:
        continue;
    }

    // Final Merit List
    printf("\n----- Final Merit List -----\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "FSc", "Matric", "Merit", "Assigned");
    for(int i = 0; i < MAX_STUDENTS; i++) {
        printf("%-20s %-10.1f %-10.1f %-10.2f %-10s\n",
            students[i].name,
            students[i].fsc,
            students[i].matric,
            students[i].merit,
            students[i].assignedSubject);
    }

    return 0;
}

