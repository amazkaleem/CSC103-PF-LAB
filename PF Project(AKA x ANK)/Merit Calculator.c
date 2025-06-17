#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 7
#define SUBJECTS 6

typedef struct {
    char name[50];
    float fsc;
    float matric;
    float merit;
    float entryMarks;
    char preferences[3][10];
    char assignedSubject[10];
} Student;

typedef struct {
    char name[10];
    int seats;
    int filled;
} Subject;

void calculateMerit(Student* s) {
    s->merit = 0.5 * s->entryMarks + 0.4 * ((s->fsc / 1100) * 100) + 0.1 * ((s->matric / 1100) * 100);
}

void sortStudentsByMerit(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].merit < students[j].merit) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void inputSubjects() {
    FILE *f = fopen("subjects.txt", "w");
    char subjectNames[SUBJECTS][10] = {"CS", "EE", "SE", "CE", "AI", "DS"};
    int seats;

    printf("Enter seats for each subject:\n");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("%s: ", subjectNames[i]);
        scanf("%d", &seats);
        fprintf(f, "%s %d\n", subjectNames[i], seats);
    }

    fclose(f);
}

void inputStudents() {
    FILE *f = fopen("students.txt", "w");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        Student s;
        printf("\nEnter data for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", s.name);

        do {
            printf("Entry Marks (0-100): ");
            scanf("%f", &s.entryMarks);
        } while (s.entryMarks < 0 || s.entryMarks > 100);

        do {
            printf("FSc Marks (0-1100): ");
            scanf("%f", &s.fsc);
        } while (s.fsc < 0 || s.fsc > 1100);

        do {
            printf("Matric Marks (0-1100): ");
            scanf("%f", &s.matric);
        } while (s.matric < 0 || s.matric > 1100);

        printf("Enter 3 preferences (CS, EE, SE, CE, AI, DS): ");
        for (int j = 0; j < 3; j++) {
            scanf("%s", s.preferences[j]);
        }

        fprintf(f, "%s\n%.2f\n%.2f\n%.2f\n%s %s %s\n",
                s.name, s.entryMarks, s.fsc, s.matric,
                s.preferences[0], s.preferences[1], s.preferences[2]);
    }

    fclose(f);
}

void reconsiderSeats(Student students[], Subject subjects[], int studentCount, int subjectCount) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].assignedSubject, "Ineligible") != 0 &&
            strcmp(students[i].assignedSubject, "None") != 0) {

            printf("\n%s was allocated %s. Do they want to keep the seat? (yes/no): ", 
                   students[i].name, students[i].assignedSubject);
            char response[10];
            scanf("%s", response);

            if (strcmp(response, "no") == 0 || strcmp(response, "No") == 0) {
                // Free the seat
                for (int j = 0; j < subjectCount; j++) {
                    if (strcmp(subjects[j].name, students[i].assignedSubject) == 0) {
                        subjects[j].filled--;
                        break;
                    }
                }

                strcpy(students[i].assignedSubject, "None");

                for (int k = 0; k < studentCount; k++) {
                    if (students[k].merit >= 50 && strcmp(students[k].assignedSubject, "None") == 0) {
                        for (int j = 0; j < subjectCount; j++) {
                            if (strcmp(subjects[j].name, students[i].assignedSubject) == 0 &&
                                subjects[j].filled < subjects[j].seats) {

                                strcpy(students[k].assignedSubject, subjects[j].name);
                                subjects[j].filled++;
                                printf("-> Seat re-assigned to %s (Merit: %.2f)\n", 
                                       students[k].name, students[k].merit);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}

void allocateRemainingSeats(Student students[], Subject subjects[], int studentCount, int subjectCount) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].merit >= 50 && strcmp(students[i].assignedSubject, "None") == 0) {
            for (int j = 0; j < subjectCount; j++) {
                if (subjects[j].filled < subjects[j].seats) {
                    strcpy(students[i].assignedSubject, subjects[j].name);
                    subjects[j].filled++;
                    printf("Automatically assigned %s to %s (Merit: %.2f)\n",
                           subjects[j].name, students[i].name, students[i].merit);
                    break;
                }
            }
        }
    }
}

int main() {
    Subject subjects[SUBJECTS] = {
        {"CS", 0, 0}, {"EE", 0, 0}, {"SE", 0, 0},
        {"CE", 0, 0}, {"AI", 0, 0}, {"DS", 0, 0}
    };
    Student students[MAX_STUDENTS];

    inputSubjects();
    inputStudents();

    FILE *sf = fopen("subjects.txt", "r");
    if (!sf) {
        printf("Error opening subjects.txt\n");
        return 1;
    }
    for (int i = 0; i < SUBJECTS; i++) {
        fscanf(sf, "%s %d", subjects[i].name, &subjects[i].seats);
    }
    fclose(sf);

    FILE *stf = fopen("students.txt", "r");
    if (!stf) {
        printf("Error opening students.txt\n");
        return 1;
    }

    for (int i = 0; i < MAX_STUDENTS; i++) {
        fscanf(stf, " %[^\n]", students[i].name);
        fscanf(stf, "%f", &students[i].entryMarks);
        fscanf(stf, "%f", &students[i].fsc);
        fscanf(stf, "%f", &students[i].matric);
        fscanf(stf, "%s %s %s", students[i].preferences[0],
               students[i].preferences[1], students[i].preferences[2]);

        calculateMerit(&students[i]);
        strcpy(students[i].assignedSubject, "None");
    }
    fclose(stf);

    sortStudentsByMerit(students, MAX_STUDENTS);

    FILE *logf = fopen("unassigned_log.txt", "w");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].merit < 50) {
            strcpy(students[i].assignedSubject, "Ineligible");
            fprintf(logf, "%s is ineligible (Merit: %.2f)\n", students[i].name, students[i].merit);
            continue;
        }

        int assigned = 0;
        for (int j = 0; j < 3 && !assigned; j++) {
            for (int k = 0; k < SUBJECTS; k++) {
                if (strcmp(students[i].preferences[j], subjects[k].name) == 0 &&
                    subjects[k].filled < subjects[k].seats) {
                    strcpy(students[i].assignedSubject, subjects[k].name);
                    subjects[k].filled++;
                    assigned = 1;
                    break;
                }
            }
        }

        if (!assigned) {
            fprintf(logf, "%s was not assigned any seat initially. Pending possible reassignment.\n", students[i].name);
            printf("\n%s was not allocated any of their preferred subjects.\n", students[i].name);
            printf("Available subjects:\n");
            for (int k = 0; k < SUBJECTS; k++) {
                if (subjects[k].filled < subjects[k].seats) {
                    printf("%s ", subjects[k].name);
                }
            }
            printf("\nChoose from the above available subjects: ");
            char choice[10];
            scanf("%s", choice);
            for (int k = 0; k < SUBJECTS; k++) {
                if (strcmp(choice, subjects[k].name) == 0 && subjects[k].filled < subjects[k].seats) {
                    strcpy(students[i].assignedSubject, subjects[k].name);
                    subjects[k].filled++;
                    break;
                }
            }
        }
    }

    fclose(logf);

    reconsiderSeats(students, subjects, MAX_STUDENTS, SUBJECTS);
    allocateRemainingSeats(students, subjects, MAX_STUDENTS, SUBJECTS);

    FILE *outf = fopen("final_merit_list.txt", "w");
    fprintf(outf, "----- Final Merit List -----\n");
    fprintf(outf, "%-20s %-10s %-10s %-10s %-10s\n", "Name", "FSc", "Matric", "Merit", "Assigned");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        fprintf(outf, "%-20s %-10.1f %-10.1f %-10.2f %-10s\n",
                students[i].name, students[i].fsc, students[i].matric,
                students[i].merit, students[i].assignedSubject);
    }

    fclose(outf);

    printf("\nData saved to files successfully.\nCheck:\n");
    printf("  - subjects.txt\n  - students.txt\n  - final_merit_list.txt\n  - unassigned_log.txt\n");

    return 0;
}
