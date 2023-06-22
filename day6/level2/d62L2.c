#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    float score;
};

typedef struct Student Student;

void parseInputString(const char* input, Student students[], int* numStudents) {
    char* token;
    char copyInput[100];

    strcpy(copyInput, input);

    token = strtok(copyInput, " ");

    students[*numStudents].id = atoi(token);

    token = strtok(NULL, " ");
    strncpy(students[*numStudents].name, token, sizeof(students[*numStudents].name) - 1);
    students[*numStudents].name[sizeof(students[*numStudents].name) - 1] = '\0';

    token = strtok(NULL, " ");
    students[*numStudents].score = atof(token);

    (*numStudents)++;
}

void initializeStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].id = 0;
        strcpy(students[i].name, "");
        students[i].score = 0.0;
    }
}

int compareScores(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    if (studentA->score < studentB->score) {
        return 1;
    } else if (studentA->score > studentB->score) {
        return -1;
    } else {
        return 0;
    }
}

void sortStudentsByScore(Student students[], int numStudents) {
    qsort(students, numStudents, sizeof(Student), compareScores);
}

void displayStudents(const Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Score: %.2f\n\n", students[i].score);
    }
}

void searchStudentByName(const Student students[], int numStudents, const char* name) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Score: %.2f\n\n", students[i].score);
            found = 1;
        }
    }

    if (!found) {
        printf("Student not found.\n\n");
    }
}

Student* addStudent(Student* students, int* numStudents, int id, const char* name, float score) {
    int newSize = (*numStudents) + 1;
    Student* newStudents = (Student*)malloc(newSize * sizeof(Student));

    memcpy(newStudents, students, (*numStudents) * sizeof(Student));

    newStudents[*numStudents].id = id;
    strcpy(newStudents[*numStudents].name, name);
    newStudents[*numStudents].score = score;

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

int main() {
    Student* students;
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    while (getchar() != '\n')
        ;

    students = (Student*)malloc(numStudents * sizeof(Student));

    initializeStudents(students, numStudents);

    for (int i = 0; i < numStudents; i++) {
        char input[100];

        printf("Enter student information (Format: id name score): ");
        fgets(input, sizeof(input), stdin);

        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        parseInputString(input, students, &i);
    }

    sortStudentsByScore(students, numStudents);

    char searchName[20];
    printf("Enter the name to search for: ");
    fgets(searchName, sizeof(searchName), stdin);

    if (searchName[strlen(searchName) - 1] == '\n')
        searchName[strlen(searchName) - 1] = '\0';

    searchStudentByName(students, numStudents, searchName);

    int newID;
    char newName[20];
    float newScore;

    printf("Enter the details of the new student (Format: id name score): ");
    scanf("%d %s %f", &newID, newName, &newScore);

    students = addStudent(students, &numStudents, newID, newName, newScore);

    printf("\nUpdated student list:\n");
    displayStudents(students, numStudents);

    students = deleteStudent(students, &numStudents);

    printf("\nUpdated student list after deletion:\n");
    displayStudents(students, numStudents);

    free(students);

    return 0;
}
