/*
 * README
 * Author: Alexander Carlsson
 * Generated: 2019-09-16
 * Last updated: 2019-09-19
 *
 * Merge sort:
 * Sorts an int array of hardcoded length using a combination
 * of recursion and iteration to sort said array in ascending
 * order.
 *
 * Usage:
 * Executed through terminal.
 * Alternatively call the "mergeSort" function.
 * See individual functions for further information
 *
 * Based (heavily) on:
 * GeeksForGeeks MergeSort Example:
 * https://www.geeksforgeeks.org/merge-sort/
 */
#include<stdlib.h>
#include<stdio.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int low, int mid, int high)
{
	int i, j, k;
	int arrLen1 = mid - low + 1;
	int arrLen2 = high - mid;

	/* create temp arrays */
	int L[arrLen1], R[arrLen2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < arrLen1; i++) {

    L[i] = arr[low + i];
  }
	for (j = 0; j < arrLen2; j++) {

    R[j] = arr[mid + 1+ j];
  }

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = low; // Initial index of merged subarray

	while (i < arrLen1 && j < arrLen2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[]
	while (i < arrLen1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[]
	while (j < arrLen2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int low, int high) {
	if (low < high) {
		// Same as (l+r)/2, but avoids overflow
		int mid = low+(high-low)/2;

		// Sorts all "left" halves
		mergeSort(arr, low, mid);

    // Sorts all "right" halves
		mergeSort(arr, mid+1, high);

		merge(arr, low, mid, high);
	}
}

// void printArray(int A[], int size) {
// 	int i;
// 	for (i=0; i < size; i++) {
//
//     printf("%d ", A[i]);
//   }
// 	printf("\n");
// }

int main() {
  int LENGTH = 1000000;

  int arr[LENGTH];

  int i = 0;
  while(i <= LENGTH) {
    scanf("%d", &(arr[i++]));
  }

	mergeSort(arr, 0, LENGTH - 1);

	// printf("\nSorted array is \n");
	// printArray(arr, LENGTH);
	return 0;
}





















// this comment is intetional
