/* Write a program to demonstrate the swapping the fields of two structures using pointers */

#include <stdio.h>

struct student {
  int roll_number;
  char name[50];
};

void swap_structures(struct student *s1, struct student *s2) {
  struct student temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}

int main() {
  struct student s1 = {12345, "John Doe"};
  struct student s2 = {67890, "Jane Doe"};

  printf("Before swapping:\n");
  printf("s1.roll_number = %d\n", s1.roll_number);
  printf("s1.name = %s\n", s1.name);
  printf("s2.roll_number = %d\n", s2.roll_number);
  printf("s2.name = %s\n", s2.name);

  swap_structures(&s1, &s2);

  printf("After swapping:\n");
  printf("s1.roll_number = %d\n", s1.roll_number);
  printf("s1.name = %s\n", s1.name);
  printf("s2.roll_number = %d\n", s2.roll_number);
  printf("s2.name = %s\n", s2.name);

  return 0;
}
