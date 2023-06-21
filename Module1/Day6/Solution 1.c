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

void parseString(char* input, struct Student* students, int size) {
    char* token = strtok(input, " ");
    int i = 0;

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); 

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  
    }

    char input[100];
    printf("Enter the student details in the format 'rollno name marks':\n");

    for (int i = 0; i < size; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  

        parseString(input, &students[i], size);
    }

    printf("\nStudent Data:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
