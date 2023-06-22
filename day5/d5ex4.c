#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char email[60];
    int age;
    float percentage;
};

typedef struct Student Student;


void displayStudent(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Email: %s\n", student->email);
    printf("Age: %d\n", student->age);
    printf("Percentage: %.2f\n", student->percentage);
    printf("\n");

}

int main() {
    int n;
    printf("Enter the Count of students: ");
    scanf("%d", &n);


    Student* students = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Email: ");
        scanf("%s", students[i].email);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
        printf("\n");
    }


    printf("Details of all students:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        displayStudent(&students[i]);
        // printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    free(students);

    return 0;
}