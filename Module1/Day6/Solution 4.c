/* Write a function to sort the array of structures in descending order based on marks */

#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudentsByMarks(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

void displayStudents(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

int main() {
    const int numStudents = 4;
    struct Student students[numStudents] = {
        {1001, "John", 85.5},
        {1002, "Emma", 92.0},
        {1003, "Michael", 78.5},
        {1004, "Sophia", 91.2}
    };

    printf("Before sorting:\n");
    displayStudents(students, numStudents);

    sortStudentsByMarks(students, numStudents);

    printf("After sorting:\n");
    displayStudents(students, numStudents);

    return 0;
}
