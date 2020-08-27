#include <stdio.h> 
#include <stdlib.h>

/*
 * Merges two sorted halves of an array.
 *
 * @param arr Array to be sorted.
 * @param l Left-most index of the array.
 * @param m Middle index of the array.
 * @param r Right-most index of the array.
 */
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create and copy data to temp arrays
  int L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // Merge the temp arrays back into arr[l..r]
  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Merge remaining temp elements into original array
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/*
 * Sorts a given array.
 *
 * 1. Divide the unsorted list into n sublists, each containing one element (a
 * list of one element is considered sorted).
 * 2. Repeatedly merge sublists to produce new sorted sublists until there is
 * only one sublist remaining.
 *
 * Out of place sort as it requires extra memory space.
 * Time complexity: O(n*log n)
 *
 * @param arr Array of integers to be sorted.
 * @param l Left-most index of the array.
 * @param r Right-most index of the array.
 */
void mergesort_custom(int arr[], int l, int r) {
  if (l >= r) {
    return;
  }

  int m = l + (r - l) / 2;

  mergesort_custom(arr, l, m);
  mergesort_custom(arr, m + 1, r);

  merge(arr, l, m, r);
}