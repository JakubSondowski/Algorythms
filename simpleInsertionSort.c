#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_OF_TABLE 100
#define NUMBER_OF_ELEMENTS_IN_ROW 10

#define BEFORE_BEING_SORTED "before being sorted"
#define AFTER_BEING_SORTED "after being sorted"

// This program generates an array of random numbers and sorts it using a simple
// insertion sort algorithm.
// Author: Jakub Sondowski
// Created: 08-06-2025
// License : None

void generateTable(void);       // Fills the array with random integers
void printTable(char *);        // Prints the array with formatting
void simpleInsertionSort(void); // Sorts the array using a simple insertion sort

int tableToBeSorted[SIZE_OF_TABLE]; // Global array to hold numbers to be sorted

int main(void) {
  generateTable();                 // Fill the array with random values
  printTable(BEFORE_BEING_SORTED); // Display the unsorted array
  simpleInsertionSort();           // Sort the array using insertion sort
  printTable(AFTER_BEING_SORTED);  // Display the sorted array

  return 0;
}

void generateTable() {
  srand(time(NULL)); // Seed the random number generator with current time

  // Fill the array with random integers from 0 to 99
  for (int iterator = 0; iterator < SIZE_OF_TABLE; iterator++) {
    tableToBeSorted[iterator] = rand() % 100;
  }
}

void printTable(char *actualState) {
  printf("Table %s:\n", actualState);

  // Print elements in rows, 10 per line
  for (int iterator = 0; iterator < SIZE_OF_TABLE; iterator++) {
    if (iterator % NUMBER_OF_ELEMENTS_IN_ROW == 0) {
      putchar('\n'); // Newline before each new row
    }
    printf("%3d,",
           tableToBeSorted[iterator]); // Print each element with padding
  }

  printf("\n\n"); // Extra spacing after the table
}

void simpleInsertionSort(void) {
  for (int mainIterator = 1; mainIterator < SIZE_OF_TABLE; mainIterator++) {
    int key = tableToBeSorted[mainIterator];
    int nestedIterator;

    for (nestedIterator = mainIterator - 1;
         nestedIterator >= 0 && tableToBeSorted[nestedIterator] > key;
         nestedIterator--) {
      tableToBeSorted[nestedIterator + 1] = tableToBeSorted[nestedIterator];
    }

    tableToBeSorted[nestedIterator + 1] = key;
  }
}

