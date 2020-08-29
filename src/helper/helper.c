#include <stdio.h>

/*
 * Prints given array.
 * 
 * @param A Integer array to be sorted.
 * @param n Integer length of the array.
 */
void print_array(int A[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

/*
 * Swaps two elements in place.
 * 
 * @param a Pointer to the first integer to be swapped.
 * @param b Pointer to the second integer to be swapped.
 */
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}