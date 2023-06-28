 /**Write a function to sort the array of structures in descending order based on marks **/
 #include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Custom comparison function for sorting in descending order based on marks
int compareStudents(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    // Sort in descending order based on marks
    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    }

    return 0;
}

void displayStudents(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents = 5;
    struct Student students[] = {
        {1001, "John", 85.5},
        {1002, "Emily", 92.0},
        {1003, "Michael", 78.3},
        {1004, "Sophia", 92.0},
        {1005, "David", 88.7}
    };

    // Sort the array of structures based on marks in descending order
    qsort(students, numStudents, sizeof(struct Student), compareStudents);

    // Display the sorted array of structures
    displayStudents(students, numStudents);

    return 0;
}