/* File Copy: Write a C program to copy a file using file operations */

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source, *target;
  char *source_file, *target_file;

  // Get the source file name from the user.
  printf("Enter the source file name: ");
  source_file = malloc(20 * sizeof(char));
  scanf("%s", source_file);

  // Get the target file name from the user.
  printf("Enter the target file name: ");
  target_file = malloc(20 * sizeof(char));
  scanf("%s", target_file);

  // Open the source file in read mode.
  source = fopen(source_file, "r");
  if (source == NULL) {
    printf("Error opening source file.\n");
    exit(EXIT_FAILURE);
  }

  // Open the target file in write mode.
  target = fopen(target_file, "w");
  if (target == NULL) {
    printf("Error opening target file.\n");
    exit(EXIT_FAILURE);
  }

  // Read the source file character by character and write it to the target file.
  while (!feof(source)) {
    char ch = fgetc(source);
    fputc(ch, target);
  }

  // Close the source and target files.
  fclose(source);
  fclose(target);

  // Print a message indicating that the file copy was successful.
  printf("File copied successfully.\n");

  free(source_file);
  free(target_file);

  return 0;
}
