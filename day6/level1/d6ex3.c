#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

typedef struct Student Student;

void parseInputString(const char* input,Student students[], int* numStudents) {
    char* token;
    char copyInput[100];

    strcpy(copyInput, input);

    token = strtok(copyInput, " ");

    students[*numStudents].rollno = atoi(token);

    token = strtok(NULL, " ");
    strncpy(students[*numStudents].name, token, sizeof(students[*numStudents].name) - 1);
    students[*numStudents].name[sizeof(students[*numStudents].name) - 1] = '\0';

    token = strtok(NULL, " ");
    students[*numStudents].marks = atof(token);

    (*numStudents)++;
}

void initializeStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

void displayStudents(const Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}


int main() {
    Student* students;
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    while (getchar() != '\n');

    students = (Student*)malloc(numStudents * sizeof(Student));

    initializeStudents(students, numStudents);

    for (int i = 0; i < numStudents; i++) {
        char input[100];

        printf("Enter student information (Format: rollno name marks): ");
        fgets(input, sizeof(input), stdin);

        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        parseInputString(input, students, &i);
    }

    displayStudents(students, numStudents);

    free(students);

    return 0;
}