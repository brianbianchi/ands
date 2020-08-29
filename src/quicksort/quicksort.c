#include "../helper/helper.h"
#include <stdio.h>

/*
 * Pivots on the last element of the array,
 * and places the pivot element at its correct position in sorted array
 *
 * @param arr Array to be sorted.
 * @param l Left-most index of the array.
 * @param r Right-most index of the array.
 */
int partition(int arr[], int l, int r) {
  int pivot = arr[r];
  int i = (l - 1);

  for (int j = l; j <= r - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[r]);
  return (i + 1);
}

/*
 * Sorts a given array.
 *
 * 1. Pick an element, called a pivot, from the array.
 * 2. Partitioning: reorder the array so that all elements with values less than
 * the pivot come before the pivot, while all elements with values greater than
 * the pivot come after it (equal values can go either way). After this
 * partitioning, the pivot is in its final position.
 * 3. Recursively apply the above steps to the sub-array of elements with
 * smaller values and separately to the sub-array of elements with greater
 * values.
 *
 * In place sort as elements are moved about the pivot without requiring a
 * separate array. 
 * Time complexity: O(n*log n)
 *
 * @param arr Array to be sorted.
 * @param l Left-most index of the array.
 * @param r Right-most index of the array.
 */
void quicksort_custom(int arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  int pi = partition(arr, l, r);

  quicksort_custom(arr, l, pi - 1);
  quicksort_custom(arr, pi + 1, r);
}