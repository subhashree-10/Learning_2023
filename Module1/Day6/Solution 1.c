 /* Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };

Note: User must be able define the no. of inputs/size of the array during runtime. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students) {
    int i = 0;
    char* token = strtok((char*)input, " ");

    while (token != NULL) {
        switch (i) {
            case 0:
                students->rollno = atoi(token);
                break;
            case 1:
                strncpy(students->name, token, sizeof(students->name) - 1);
                students->name[sizeof(students->name) - 1] = '\0';
                break;
            case 2:
                students->marks = atof(token);
                break;
            default:
                break;
        }

        i++;
        token = strtok(NULL, " ");
    }
}

int main() {
    const char* input = "1001 Aron 100.00";
    const int numStudents = 1;
    struct Student students[numStudents];

    parseString(input, students);

    // Print the initialized structure
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}

