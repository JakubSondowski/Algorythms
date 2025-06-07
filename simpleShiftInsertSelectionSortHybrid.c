#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_OF_TABLE 100
#define BEFORE_BEING_SORTED "before being sorted"
#define AFTER_BEING_SORTED "after being sorted"

// This program generates an array of random numbers and sorts it using a simple
// shift-insert selection sort hybrid algorithm.
// Author: Jakub Sondowski
// Created: 07-06-2025
// License : None

void generateTable(void); // Fills the array with random integers
void printTable(char *);  // Prints the array with formatting
void hybrid(
    void); // Sorts the array using a hybrid of shift-insert and selection sort

int tableToBeSorted[SIZE_OF_TABLE]; // Global array to hold numbers to be sorted

int main(void) {
  generateTable();
  printTable(BEFORE_BEING_SORTED);
  hybrid();
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
    if (iterator % 10 == 0) {
      putchar('\n');
    }
    printf("%3d,", tableToBeSorted[iterator]);
  }

  printf("\n\n"); // Add spacing after the table
}

void hybrid(void) {
  int minVal = tableToBeSorted[0];
  int minValIndex = 0;

  for (int mainIterator = 1; mainIterator < SIZE_OF_TABLE; mainIterator++) {
    for (int iterator = mainIterator; iterator < SIZE_OF_TABLE; iterator++) {
      if (tableToBeSorted[iterator] < minVal) {
        minVal = tableToBeSorted[iterator];
        minValIndex = iterator;
      }
    }
    for (int lastVal = minValIndex; lastVal >= mainIterator; lastVal--) {
      tableToBeSorted[lastVal] = tableToBeSorted[lastVal - 1];
    }
    tableToBeSorted[mainIterator - 1] = minVal;
    minVal = tableToBeSorted[mainIterator];
    minValIndex = mainIterator;
  }
}
