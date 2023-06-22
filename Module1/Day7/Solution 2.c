/* Case Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *source, *target;
  char ch;
  char *option = NULL;
  int case_handling = 0;

  // Check for the command-line options.
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      option = argv[i];
      if (strcmp(option, "-u") == 0) {
        case_handling = 1;
      } else if (strcmp(option, "-l") == 0) {
        case_handling = 2;
      } else if (strcmp(option, "-s") == 0) {
        case_handling = 3;
      } else {
        printf("Invalid option: %s\n", option);
        exit(EXIT_FAILURE);
      }
    }
  }

  // Get the source file name from the user.
  if (argc < 3) {
    printf("Please specify the source file name.\n");
    exit(EXIT_FAILURE);
  }

  char *source_file = argv[1];

  // Get the target file name from the user.
  char *target_file = argv[2];

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
  while ((ch = fgetc(source)) != EOF) {
    switch (case_handling) {
      case 1:
        // Upper case
        fputc(toupper(ch), target);
        break;
      case 2:
        // Lower case
        fputc(tolower(ch), target);
        break;
      case 3:
        // Sentence case
        if (ch == ' ') {
          fputc(toupper(ch), target);
        } else {
          fputc(tolower(ch), target);
        }
        break;
      default:
        // No case handling
        fputc(ch, target);
        break;
    }
  }

  // Close the source and target files.
  fclose(source);
  fclose(target);

  return 0;
}
