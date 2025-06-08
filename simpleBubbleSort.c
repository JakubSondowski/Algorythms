#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_OF_TABLE 100
#define NUMBER_OF_ELEMENTS_IN_ROW 10

#define BEFORE_BEING_SORTED "before being sorted"
#define AFTER_BEING_SORTED "after being sorted"

// This program generates an array of random numbers and sorts it using a simple
// bubble sort algorithm.
// Author: Jakub Sondowski
// Created: 07-06-2025
// License : None

void generateTable(void);    // Fills the array with random integers
void printTable(char *);     // Prints the array with formatting
void simpleBubbleSort(void); // Sorts the array using a simple bubble sort

int tableToBeSorted[SIZE_OF_TABLE]; // Global array to hold numbers to be sorted

int main(void) {
  generateTable();
  printTable(BEFORE_BEING_SORTED);
  simpleBubbleSort();
  printTable(AFTER_BEING_SORTED);

  return 0;
}

void generateTable() {
  // Seeds the random number generator with the current time
  srand(time(NULL));

  // Fill the table with random numbers between 0 and 99
  for (int iterator = 0; iterator < SIZE_OF_TABLE; iterator++) {
    tableToBeSorted[iterator] = rand() % 100;
  }
}

void printTable(char *actualState) {
  printf("Table %s:\n", actualState);

  // Print each number in the array, 10 numbers per line
  for (int iterator = 0; iterator < SIZE_OF_TABLE; iterator++) {
    if (iterator % NUMBER_OF_ELEMENTS_IN_ROW == 0) {
      putchar('\n');
    }
    printf("%3d,", tableToBeSorted[iterator]);
  }

  printf("\n\n"); // Add spacing after the table
}

void simpleBubbleSort(void) {
  int buffer;

  // Simple bubble sort implementation
  for (int mainIterator = 0; mainIterator < SIZE_OF_TABLE - 1; mainIterator++) {
    for (int nestedIterator = 0; nestedIterator < SIZE_OF_TABLE - 1;
         nestedIterator++) {
      if (tableToBeSorted[nestedIterator] >
          tableToBeSorted[nestedIterator + 1]) {
        // Swap the two values
        buffer = tableToBeSorted[nestedIterator];
        tableToBeSorted[nestedIterator] = tableToBeSorted[nestedIterator + 1];
        tableToBeSorted[nestedIterator + 1] = buffer;
      }
    }
  }
}
