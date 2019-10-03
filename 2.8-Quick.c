/*
 * README
 * Author: Alexander Carlsson
 * Generated: 2019-09-16
 * Last updated: 2019-09-19
 *
 * Quick sort:
 * Sorts an int array of hardcoded length using a combination
 * of recursion and iteration to sort said array in ascending
 * order.
 *
 * Usage:
 * Executed through terminal.
 * Alternatively call the "quickSort" function.
 * See individual functions for further information
 *
 * Based (heavily) on:
 * GeeksForGeeks QuickSort Example:
 * https://www.geeksforgeeks.org/merge-sort/
 */
#include<stdio.h>
#include<stdlib.h>
#include"2.1.c"

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high) {
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int *arr, int low, int high, int cutoff) {
  if(high < cutoff) {
    sort(arr, high); // call to insertion sort
		return;
  }

	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1, cutoff);
		quickSort(arr, pi + 1, high, cutoff);
	}
}

/* Function to print an array */
void printArray(int *arr, int size) {
	long i;
	for (i=0; i < size; i++) {
    printf("%d ", arr[i]);

  }
}

// Driver program to test above functions
int main(int argc, char **argv) {

  int LENGTH = 10000;
  int* arr = (int*) malloc(LENGTH * sizeof(int));

  int i = 0;
  while(i < LENGTH) {
    scanf("%d", &arr[i]);
    i++;
  }


	int n = LENGTH;
  // printf("Unsorted array: \n");
  // printArray(arr, n);

	quickSort(arr, 0, n-1, *argv[0]);
	// printf("\nSorted array: \n");
  // printArray(arr, n);
  // printf("\n");

  free(arr);

	return 0;
}

















// this comment is intetional
