#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 15
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

        // Write to file
        fprintf(f, "%s\n%.2f\n%.2f\n%.2f\n%s %s %s\n",
                s.name, s.entryMarks, s.fsc, s.matric,
                s.preferences[0], s.preferences[1], s.preferences[2]);
    }

    fclose(f);
}

int main() {
    Subject subjects[SUBJECTS] = {
        {"CS", 0, 0}, {"EE", 0, 0}, {"SE", 0, 0},
        {"CE", 0, 0}, {"AI", 0, 0}, {"DS", 0, 0}
    };
    Student students[MAX_STUDENTS];

    // 1. Get inputs and store them in files
    inputSubjects();
    inputStudents();

    // 2. Read subjects from file
    FILE *sf = fopen("subjects.txt", "r");
    if (!sf) {
        printf("Error opening subjects.txt\n");
        return 1;
    }
    for (int i = 0; i < SUBJECTS; i++) {
        fscanf(sf, "%s %d", subjects[i].name, &subjects[i].seats);
    }
    fclose(sf);

    // 3. Read students from file
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

    // 4. Sort by merit
    sortStudentsByMerit(students, MAX_STUDENTS);

    FILE *logf = fopen("unassigned_log.txt", "w");

    // 5. Subject allocation
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
            fprintf(logf, "%s was not assigned any preferred subject.\n", students[i].name);
            printf("\n%s was not allocated any of their preferred subjects.\n", students[i].name);
        	printf("Available subjects:\n");
	        for(int k = 0; k < SUBJECTS; k++) {
	            if(subjects[k].filled < subjects[k].seats) {
	                printf("%s ", subjects[k].name);
	            }
	        }
	        printf("\nChoose from the above available subjects: ");
	        char choice[10];
	        scanf("%s", choice);
	        for(int k = 0; k < SUBJECTS; k++) {
	            if(strcmp(choice, subjects[k].name) == 0 && subjects[k].filled < subjects[k].seats) {
	                strcpy(students[i].assignedSubject, subjects[k].name);
	                subjects[k].filled++;
	                break;
	            }
	        }
            if (strcmp(students[i].assignedSubject, "None") == 0) {
                fprintf(logf, "No available seats for %s.\n", students[i].name);
            }
        }
    }

    fclose(logf);

    // 6. Final merit list
    FILE *outf = fopen("final_merit_list.txt", "w");
    fprintf(outf, "----- Final Merit List -----\n");
    fprintf(outf, "%-20s %-10s %-10s %-10s %-10s\n", "Name", "FSc", "Matric", "Merit", "Assigned");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        fprintf(outf, "%-20s %-10.1f %-10.1f %-10.2f %-10s\n",
                students[i].name, students[i].fsc, students[i].matric,
                students[i].merit, students[i].assignedSubject);
    }

    fclose(outf);

    printf("\n Data saved to files successfully.\nCheck:\n");
    printf("  - subjects.txt\n  - students.txt\n  - final_merit_list.txt\n  - unassigned_log.txt\n");

    return 0;
}

