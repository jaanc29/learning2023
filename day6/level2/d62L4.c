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

int compareMarks(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    } else {
        return 0;
    }
}

void sortStudentsByMarks(Student students[], int numStudents) {
    qsort(students, numStudents, sizeof(Student), compareMarks);
}

void displayStudents(const Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

void searchStudentByName(const Student students[], int numStudents, const char* name) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n\n", students[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf("Student not found.\n\n");
    }
}

Student* addStudent(Student* students, int* numStudents, int rollno, const char* name, float marks) {
    int newSize = (*numStudents) + 1;
    Student* newStudents = (Student*)malloc(newSize * sizeof(Student));

    memcpy(newStudents, students, (*numStudents) * sizeof(Student));

    newStudents[*numStudents].rollno = rollno;
    strcpy(newStudents[*numStudents].name, name);
    newStudents[*numStudents].marks = marks;

    (*numStudents)++;

    free(students);

    return newStudents;
}

Student* deleteStudent(Student* students, int* numStudents) {
    if (*numStudents <= 0) {
        printf("No students to delete.\n");
        return students;
    }

    int newSize = (*numStudents) - 1;
    Student* newStudents = (Student*)malloc(newSize * sizeof(Student));

    memcpy(newStudents, students + 1, newSize * sizeof(Student));

    (*numStudents)--;

    free(students);

    return newStudents;
}

void swapStudents(Student* students, int index1, int index2) {
    Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

void rotateStudents(Student* students, int numStudents, int k) {
    int rotation = k % numStudents;

    if (rotation == 0) {
        return;
    }

    Student* temp = (Student*)malloc(rotation * sizeof(Student));

    memcpy(temp, students + (numStudents - rotation), rotation * sizeof(Student));

    memmove(students + rotation, students, (numStudents - rotation) * sizeof(Student));

    memcpy(students, temp, rotation * sizeof(Student));

    free(temp);
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

    sortStudentsByMarks(students, numStudents);


    char searchName[20];
    printf("Enter the name to search for: ");
    fgets(searchName, sizeof(searchName), stdin);

    if (searchName[strlen(searchName) - 1] == '\n')
        searchName[strlen(searchName) - 1] = '\0';

    searchStudentByName(students, numStudents, searchName);

    int newRollNo;
    char newName[20];
    float newMarks;

    printf("Enter the details of the new student (Format: rollno name marks): ");
    scanf("%d %s %f", &newRollNo, newName, &newMarks);

    students = addStudent(students, &numStudents, newRollNo, newName, newMarks);

    printf("\nUpdated student list:\n");
    displayStudents(students, numStudents);

    int index1, index2;
    printf("Enter the indexes of the students to swap: ");
    scanf("%d %d", &index1, &index2);

    swapStudents(students, index1, index2);

    printf("\nUpdated student list after swapping:\n");
    displayStudents(students, numStudents);

    students = deleteStudent(students, &numStudents);

    printf("\nUpdated student list after deletion:\n");
    displayStudents(students, numStudents);

    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    rotateStudents(students, numStudents, k);

    printf("\nUpdated student list after rotation:\n");
    displayStudents(students, numStudents);

    free(students);

    return 0;
}
