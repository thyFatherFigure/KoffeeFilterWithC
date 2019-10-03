/*
 * README
 * Author: Alexander Carlsson
 * Generated: 2019-09-14
 * Last updated: 2019-09-19
 *
 * Insertion sort:
 * Sorts an int array of given length using a recursive
 * implementation of insertion sort in ascending order.
 *
 * Usage:
 * Executed through terminal.
 * Alternatively call "sort" function.
 * See individual functions for further information
 *
 * Based on:
 * Slide examples
 */
#include <stdio.h>

/*
 * Compare
 * DESCRIPTION:
 *   Makes a "is lesser than" comparison between two integers.
 * PRECONDITIONS:
 *   n/a
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   INPUT: (1, 2)
 *   OUTPUT: 1
 *
 *   INPUT: (2, 1)
 *   OUTPUT: 0
 *
 *   INPUT: (2, 2)
 *   OUTPUT: 0
 */
int compare(int a, int b) {
  return (a < b);
}

/*
 * Swap
 * DESCRIPTION:
 *   Swaps the values of two integer pointers.
 * PRECONDITIONS:
 *   n/a
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array[0], array[1])
 *   OUTPUT:
 *   post: array = {2, 1, 3, 4}
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array[1], array[1])
 *   OUTPUT:
 *   post: array = {1, 2, 3, 4}
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array[0], array[-1])
 *   OUTPUT:
 *   post: array = {VALUE FROM MEMORY, 2, 3, 4}
 */
void swap(int *a, int *b) {
  int temp = *a;

  *a = *b;
  *b = temp;
}

/*
 * arrayToStringExec
 * DESCRIPTION:
 *   The main functionality of the arrayToString function.
 *   Prints array according to the format [e1],[e2], ... , [en],
 *   Call using function "arrayToString"
 * PRECONDITIONS:
 *   currentIndex = 0 (or desired starting position)
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4, 0)
 *   OUTPUT: [1],[2],[3],[4],
 *
 *   pre: array = {}
 *   INPUT: (array, 0, 0)
 *   OUTPUT:
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4, 1)
 *   OUTPUT: [2],[3],[4],
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 3, 0)
 *   OUTPUT: [1],[2],[3],
 */
void arrayToStringExec(int *array, int length, int currentIndex) {

  // base case
  if(currentIndex >= length) {
    printf("\n");
    return;
  }

  printf("%s%d%s", "[", array[currentIndex], "],");

  // recursive call with increased index
  arrayToStringExec(array, length, currentIndex+1);

}

/*
 * arrayToString
 * DESCRIPTION:
 *   The "UI" function of "arrayToStringExec".
 *   Calls "arrayToStringExec" using proper arguments for printing of array.
 * PRECONDITIONS:
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4)
 *   OUTPUT: [1],[2],[3],[4],
 *
 *   pre: array = {}
 *   INPUT: (array, 0)
 *   OUTPUT:
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 3)
 *   OUTPUT: [1],[2],[3],
 */
void arrayToString(int *array, int length) {
  arrayToStringExec(array, length, 0);
}

/*
 * sortInner
 * DESCRIPTION:
 *   The inner recursive loop of the insertion sort algoritm.
 *   Checks if the array element of the current index is larger
 *   than any elements prior. Swaps these elements using "swap"
 *   if this should be the case.
 *   Prints the new state of the array if "swap" is called.
 * PRECONDITIONS:
 *   index is within bounds of array
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 1)
 *   OUTPUT: [3],[4],[2],[1],
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 4)
 *   OUTPUT: [1],[4],[3],[2],
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 2, 4)
 *   OUTPUT: [1],[4],
 *
 *   pre: array = {1, 2, 0, 4}
 *   INPUT: (array, 4, 3)
 *   OUTPUT: [0],[2],[1],[4],
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4, 4)
 *   OUTPUT: [1],[2],[3],[4],
 */
void sortInner(int *array, int length, int index) {

  // base case
  if(index <= 0) {
    return;
  }

  if(compare(array[index], array[index-1])) {

    swap(&array[index], &array[index-1]);
    // arrayToString(array, length);
  }

  // recursive call with decreased index
  sortInner(array, length, index-1);

}

/*
 * sortOuter
 * DESCRIPTION:
 *   The outer recursive loop of the insertion sort algoritm.
 *   Calls the "sortInner" for each element of the array starting
 *   at "index".
 *   Called by "sort".
 * PRECONDITIONS:
 *   index is within bounds of array
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 1)
 *   OUTPUT:
 *   post: array = {1, 2, 3, 4}
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 3, 0)
 *   OUTPUT:
 *   post: array = {2, 3, 4, 1}
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 2)
 *   OUTPUT:
 *   post: array = {4, 1, 2, 3}
 *
 *   pre: array = {3, 4, 0, 1}
 *   INPUT: (array, 4, 0)
 *   OUTPUT:
 *   post: array = {0, 1, 3, 4}
 */
void sortOuter(int *array, int length, int index) {

  // base case
  if(index >= length) {
    return;
  }

  sortInner(array, length, index);

  // recursive call with increased index
  sortOuter(array, length, index+1);

}

/*
 * sort
 * DESCRIPTION:
 *   The "UI" function of "sortOuter" and "sortInner", together making the
 *   insertion sort algoritm.
 *   Calls "sortOuter" using proper arguments for sorting of the entire array.
 * PRECONDITIONS:
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4)
 *   OUTPUT: [3],[4],[2],[1],
 *           [3],[2],[4],[1],
 *           [2],[3],[4],[1],
 *           [2],[3],[1],[4],
 *           [2],[1],[3],[4],
 *           [1],[2],[3],[4],
 *   post: array = {1, 2, 3, 4}
 *
 *   pre: array = {3, 4, 0, 1}
 *   INPUT: (array, 4, 0)
 *   OUTPUT: [0],[4],[1],
 *           [0],[1],[4],
 *   post: array = {0, 1, 3, 4}
 *
 *   pre: array = {1, 2, 4, 3, 5, 0}
 *   INPUT: (array, 6, 0)
 *   OUTPUT: [1],[2],[3],[4],[5],[0],
 *           [1],[2],[3],[4],[0],[5],
 *           [1],[2],[3],[0],[4],[5],
 *           [1],[2],[0],[3],[4],[5],
 *           [1],[0],[2],[3],[4],[5],
 *           [0],[1],[2],[3],[4],[5],
 *   post: array = {0, 1, 2, 3, 4, 5}
 */
void sort(int *array, int length) {
  sortOuter(array, length, 1);
}



int main() {

  //TODO: Implement testing of premade arrays instead of taking user input

  // get array length and array content from Stdin
  int length;
  printf("%s", "length of array: ");
  scanf("%d", &length);

  int array[length];

  for (int i = 0; i < length; i++) {
    scanf("%d", &array[i]);
  }

  // sort array and print results
  sort(array, length);

  printf("\n%s\n", "Result:");
  arrayToString(array, length);


  return 0;
}




























// this comment is intetional
