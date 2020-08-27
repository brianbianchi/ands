#include "mergesort/mergesort.h"
#include "quicksort/quicksort.h"
#include <stdio.h>
#include <string.h>

/*
 * Prints given array.
 */
void print_array(int A[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  static int template[] = {5, 9, 1, 3, 4, 6, 6, 3, 2};
  int a[9];
  int len = sizeof(a) / sizeof(int);

  memcpy(a, template, sizeof(template));
  printf("original array:\n");
  print_array(a, len);

  printf("mergesort:\n");
  mergesort_custom(a, 0, len - 1);
  print_array(a, len);

  memcpy(a, template, sizeof(template));
  printf("mergesort:\n");
  quicksort_custom(a, 0, len - 1);
  print_array(a, len);

  return (0);
}
