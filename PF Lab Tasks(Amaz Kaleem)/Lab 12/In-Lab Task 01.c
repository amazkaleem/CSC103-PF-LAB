#include <stdio.h>

struct Student {
    char name[20];
    int eng;
    int math;
    int phys;
    double mean;
    char grade;
};


char determineGrade(double mean) {
    if (mean >= 90) return 'A';
    else if (mean >= 80) return 'B';
    else if (mean >= 70) return 'C';
    else if (mean >= 60) return 'D';
    else return 'S';
}

int main() {
    struct Student students[10];
    int i;
    int j;

    
    for (i = 0; i < 10; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter English marks: ");
        scanf("%d", &students[i].eng);
        printf("Enter Math marks: ");
        scanf("%d", &students[i].math);
        printf("Enter Physics marks: ");
        scanf("%d", &students[i].phys);

        
        students[i].mean = (students[i].eng + students[i].math + students[i].phys) / 3.0;

        
        students[i].grade = determineGrade(students[i].mean);
    }

    
    printf("\nStudent Results:\n");
    for (j = 0; j < 10; j++) {
        printf("Name: %s, Mean: %.2f, Grade: %c\n", students[j].name, students[j].mean, students[j].grade);
    }

    return 0;
}

