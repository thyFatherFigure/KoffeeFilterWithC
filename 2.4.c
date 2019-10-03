/*
 * README
 * Author: Alexander Carlsson
 * Generated: 2019-09-16
 * Last updated: 2019-09-16
 *
 * Insertion sort:
 * Sorts an int array of given length using a recursive
 * implementation of insertion sort.
 * Counts and prints the amount of swaps performed as well as
 * the amounts of inversions.
 *
 * Usage:
 * Executed through terminal.
 * Alternatively call "sort" function.
 * See individual functions for further information
 *
 * Based on:
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
 *   Returns a part-sum of the amount of swaps performed.
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
int sortInner(int *array, int length, int index, int count) {

  // base case
  if(index <= 0) {
    return count;
  }

  if(compare(array[index], array[index-1])) {
    count++;
    swap(&array[index], &array[index-1]);
    arrayToString(array, length);
  }

  // recursive call with decreased index
  sortInner(array, length, index-1, count);

}

/*
 * sortOuter
 * DESCRIPTION:
 *   The outer recursive loop of the insertion sort algoritm.
 *   Calls the "sortInner" for each element of the array starting
 *   at "index".
 *   Called by "sort".
 *   Returns the amount of swaps performed.
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
int sortOuter(int *array, int length, int index, int count) {

  // base case
  if(index >= length) {
    return count;
  }

  count = sortInner(array, length, index, count);

  // recursive call with increased index
  count = sortOuter(array, length, index+1, count);

}

/*
 * sort
 * DESCRIPTION:
 *   The "UI" function of "sortOuter" and "sortInner", together making the
 *   insertion sort algoritm.
 *   Calls "sortOuter" using proper arguments for sorting of the entire array.
 *   Returns the amount of swaps performed.
 * PRECONDITIONS:
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4)
 *   OUTPUT:
 *   post: array = {1, 2, 3, 4}
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 3)
 *   OUTPUT:
 *   post: array = {2, 3, 4, 1}
 *
 *   pre: array = {3, 4, 0, 1}
 *   INPUT: (array, 4, 0)
 *   OUTPUT:
 *   post: array = {0, 1, 3, 4}
 */
int sort(int *array, int length) {

  int count = 0;

  count += sortOuter(array, length, 1, count);

  return count;
}

/*
 * inversionsInner
 * DESCRIPTION:
 *   The inner recursive loop of the inversion count algoritm.
 *   Checks if the array element of the current index is larger
 *   than any elements prior. Increases the "count" variable
 *   if this should be the case.
 *   Prints the inversion case on format:
 *   [i,a[i]], [j, a[j]] where i and j are indices and a[i], a[j] are the values of the elements
 *   Returns a part-sum of the amount of inversions registered.
 * PRECONDITIONS:
 *   i is within bounds of array
 *   j = i+1 for intended use (usually handled by caller)
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4, 0, 1, 0)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-3] [0,-1],[3,-4]
 *           Inversions of array: 3
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 3, 0, 1, 0)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-3]
 *           Inversions of array: 2
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 1, 2, 0)
 *   OUTPUT: Inversions of array: 3
 *
 *
 *   pre: array = {1, 2, 4, 3, 5, 0}
 *   INPUT: (array, 6, 0, 1, 0)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-4] [0,-1],[3,-3] [0,-1],[4,-5]
 *           Inversions of array: 4
 */
int inversionsInner(int *array, int length, int i, int j, int count) {
  // base case
  if(j == length) {
    return count;
  }

  if(array[i] > array[j]) {
    count++;
    printf("[%d,%d],[%d,%d] ", i, array[i], j, array[j]);
  }

  // recursive call
  count = inversionsInner(array, length, i, j+1, count);

}

/*
 * inversionsOuter
 * DESCRIPTION:
 *   The outer recursive loop of the inversion count algoritm.
 *   Calls the "inversionsInner" function for each element of the array starting
 *   at "index".
 *   Called by "inversions".
 *   Returns the sum of the amount of inversions registered.
 * PRECONDITIONS:
 *   index is within bounds
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4, 0, 1, 0)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-3] [0,-1],[3,-4] [1,-2],[2,-3]
 *           [1,-2],[3,-4] [2,-3],[3,-4]
 *           Inversions of array: 6
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 3, 0, 1, 0)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-3] [0,-1],[3,-4] [1,-2],[2,-3]
 *           [1,-2],[3,-4]
 *           Inversions of array: 5
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4, 1, 2, 0)
 *   OUTPUT: Inversions of array: 0
 *
 *
 *   pre: array = {1, 2, 4, 3, 5, 0}
 *   INPUT: (array, 6, 0, 1, 0)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-4] [0,-1],[3,-3] [0,-1],[4,-5]
 *           [1,-2],[2,-4] [1,-2],[3,-3] [1,-2],[4,-5] [2,-4],[4,-5]
 *           [3,-3],[4,-5]
 *           Inversions of array: 9
 */
int inversionsOuter(int *array, int length, int index, int count) {

  if(index == length) {
    return count;
  }

  count = inversionsInner(array, length, index, index+1, count);

  count = inversionsOuter(array, length, index+1, count);
}

/*
 * inversions
 * DESCRIPTION:
 *   The "UI" function of "inversionsOuter" and "inversionsInner", together making the
 *   insertions count algoritm.
 *   Calls "inversionsOuter" using proper arguments for counting inversions of the entire array.
 *   Returns the amount of swaps performed.
 * PRECONDITIONS:
 *   length = length of array
 * POSTCONDITIONS:
 *   n/a
 * EXAMPLES:
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 4)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-3] [0,-1],[3,-4] [1,-2],[2,-3]
 *           [1,-2],[3,-4] [2,-3],[3,-4]
 *           Inversions of array: 6
 *
 *   pre: array = {1, 2, 3, 4}
 *   INPUT: (array, 3)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-3] [0,-1],[3,-4] [1,-2],[2,-3]
 *           [1,-2],[3,-4]
 *           Inversions of array: 5
 *
 *   pre: array = {4, 3, 2, 1}
 *   INPUT: (array, 4)
 *   OUTPUT: Inversions of array: 0
 *
 *
 *   pre: array = {1, 2, 4, 3, 5, 0}
 *   INPUT: (array, 6)
 *   OUTPUT: [0,-1],[1,-2] [0,-1],[2,-4] [0,-1],[3,-3] [0,-1],[4,-5]
 *           [1,-2],[2,-4] [1,-2],[3,-3] [1,-2],[4,-5] [2,-4],[4,-5]
 *           [3,-3],[4,-5]
 *           Inversions of array: 9
 */
int inversions(int *array, int length) {

  return inversionsOuter(array, length, 0, 0);

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


  // invert before
  for (int i = 0; i < length; i++) {
    array[i]*=-1;
  }

  printf("\n%s%d\n", "Invertions of array: ", inversions(array, length));

  // sort array and print results
  int count = sort(array, length);

  // invert after
  for (int i = 0; i < length; i++) {
    array[i]*=-1;
  }

  printf("\n%s%d%s\n", "Result: of ", count, " swaps");
  arrayToString(array, length);


  return 0;
}




























// this comment is intetional
