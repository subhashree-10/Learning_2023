/* File Copy: Write a C program to copy a file using file operations */

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source, *target;
  char ch;
 
  printf("Enter the source file name: ");
  char source_file[20];
  scanf("%s", source_file);

  printf("Enter the target file name: ");
  char target_file[20];
  scanf("%s", target_file);

  source = fopen(source_file, "r");
  if (source == NULL) {
    printf("Error opening source file.\n");
    exit(EXIT_FAILURE);
  }

 target = fopen(target_file, "w");
  if (target == NULL) {
    printf("Error opening target file.\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(source)) != EOF) {
    fputc(ch, target);
  }

   fclose(source);
   fclose(target);

   printf("File copied successfully.\n");

   return 0;
}
