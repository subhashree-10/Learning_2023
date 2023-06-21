/* Write a function to display all members in the above array of structures */

#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

int main() {
    const int numStudents = 3;
    struct Student students[numStudents] = {
        {1001, "John", 85.5},
        {1002, "Emma", 92.0},
        {1003, "Michael", 78.5}
    };

    displayStudents(students, numStudents);

    return 0;
}
