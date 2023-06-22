 /* Data Viewer:
Write an application to view the log stored in data.csv
Example, say you have the following data in data.csv

------------------------------------

EntryNo,sensorNo,Temperature,Humidity,Light,

1,S1,36.5,100,50,10:30:50
2,S3,30,100,50,10:30:55
3,S2,-6.6,100,10,10:31:00
------------------------------------

a. Write a function to extract each line in the .csv file and store it in an array of structures. 
b. Also implement functions to display the contents of the array of structures. */

Question-a

#include <stdio.h>
#include <stdlib.h>

struct log_entry {
  int entry_no;
  char sensor_no[10];
  float temperature;
  int humidity;
  int light;
  char time_stamp[20];
};

int main(void) {
  FILE *file;
  struct log_entry *entries;
  int i;
  int entries_count;
  char *entries_count_ptr = &entries_count;

  // Open the file in read mode.
  file = fopen("data.csv", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(EXIT_FAILURE);
  }

  // Read the number of entries in the file.
  fscanf(file, "%d", entries_count_ptr);

  // Allocate memory for the array of structures.
  entries = malloc(entries_count * sizeof(struct log_entry));
  if (entries == NULL) {
    printf("Error allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  // Read each line in the file and store it in the array of structures.
  for (i = 0; i < entries_count; i++) {
    fscanf(file, "%d,%[^,],%f,%d,%d,%[^\n]", &entries[i].entry_no,
            entries[i].sensor_no, &entries[i].temperature, &entries[i].humidity,
            &entries[i].light, entries[i].time_stamp);
  }

  // Close the file.
  fclose(file);

  // Print the contents of the array of structures.
  for (i = 0; i < entries_count; i++) {
    printf("Entry No: %d\n", entries[i].entry_no);
    printf("Sensor No: %s\n", entries[i].sensor_no);
    printf("Temperature: %.2f\n", entries[i].temperature);
    printf("Humidity: %d\n", entries[i].humidity);
    printf("Light: %d\n", entries[i].light);
    printf("Time Stamp: %s\n", entries[i].time_stamp);
  }

  // Free the memory allocated for the array of structures.
  free(entries);

  return 0;
}

Question-b

#include <stdio.h>
#include <stdlib.h>

struct log_entry {
  int entry_no;
  char sensor_no[10];
  float temperature;
  int humidity;
  int light;
  char time_stamp[20];
};

void print_log_entry(struct log_entry *entry) {
  printf("Entry No: %d\n", entry->entry_no);
  printf("Sensor No: %s\n", entry->sensor_no);
  printf("Temperature: %.2f\n", entry->temperature);
  printf("Humidity: %d\n", entry->humidity);
  printf("Light: %d\n", entry->light);
  printf("Time Stamp: %s\n", entry->time_stamp);
}

int main(void) {
  FILE *file;
  struct log_entry *entries;
  int i;
  int entries_count;
  char *entries_count_ptr = &entries_count;

  // Open the file in read mode.
  file = fopen("data.csv", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(EXIT_FAILURE);
  }

  // Read the number of entries in the file.
  fscanf(file, "%d", entries_count_ptr);

  // Allocate memory for the array of structures.
  entries = malloc(entries_count * sizeof(struct log_entry));
  if (entries == NULL) {
    printf("Error allocating memory.\n");
    exit(EXIT_FAILURE);
  }

  // Read each line in the file and store it in the array of structures.
  for (i = 0; i < entries_count; i++) {
    fscanf(file, "%d,%[^,],%f,%d,%d,%[^\n]", &entries[i].entry_no,
            entries[i].sensor_no, &entries[i].temperature, &entries[i].humidity,
            &entries[i].light, entries[i].time_stamp);
  }

  // Close the file.
  fclose(file);

  // Print the contents of the array of structures.
  for (i = 0; i < entries_count; i++) {
    print_log_entry(&entries[i]);
  }

  // Free the memory allocated for the array of structures.
  free(entries);

  return 0;
}


