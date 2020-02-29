#include <stdio.h>

void printArray(int a[], int start, int end) {
  printf("arr={");
  for(int i=start; i <= end; i++) {
    if(i > start) {
      printf(",");
    }
    printf("%d", a[i]);
  }
  printf("}\n");
}

void swap(int a[], int from, int to) {
  int tmp = a[to];
  a[to] = a[from];
  a[from] = tmp;
}

void quicksort(int thelist[], int start, int end) {
  // base case is array of 0 or 1 length
  if(end - start <= 0) {
    return;
  }

  int pivot = thelist[end]; // choose last element's value as pivot

  // partition array, moving elements less than pivot to the left half, and greater elements to the right
  int j = end-1;
  for(int i = start; i < j;) {
    if (thelist[i] > pivot) {
      swap(thelist, i, j);
      j--; // move swap-to position down the array
    } else {
      i++; // only move on if element is less-than-or-equal-to pivot
    }
  }

  // move pivot into place, if necessary
  if(thelist[j] > pivot) {
    swap(thelist, end, j);
  }

  //recurse for left half and right half
  quicksort(thelist, start, j-1);
  quicksort(thelist, j+1, end);
}

int main(int argc, char *argv[]) {
  int arr[] = {1,3,4,9,7,6,8,2,5};
  int arrsz = sizeof(arr)/sizeof(int);

  printf("before sorting, ");
  printArray(arr, 0, arrsz-1);

  quicksort(arr, 0, arrsz-1);

  printf(" after sorting, ");
  printArray(arr, 0, arrsz-1);
}
