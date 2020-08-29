#include "../helper/helper.h"
#include <stdio.h>

/*
 * Sorts a given array.
 *
 * 1. Repeatedly swap the adjacent elements if they are in wrong order.
 *
 * This simple algorithm performs poorly in real world use and is used primarily
 * as an educational tool.
 *
 * In place sort as elements are moved without requiring extra memory space.
 * Time complexity: O(n^2)
 *
 * @param arr Array of integers to be sorted.
 * @param n Integer lenth of the array.
 */
void bubblesort_custom(int *arr, int n) {
  int i, j;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}