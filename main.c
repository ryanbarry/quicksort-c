#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int start, int end) {
  printf("arr={");
  for(int i=start; i <= end; i++) {
    if(i > start) {
      printf(",");
    }
    printf("%d", a[i]);
  }
  printf("}");
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
  int j = end;
  for(int i = start; i < j;) {
    if (thelist[i] > pivot) {
      j--; // move swap-to position down the array
      swap(thelist, i, j);
    } else {
      i++; // only move on if element is less-than-or-equal-to pivot
    }
  }

  // move pivot into place, if necessary
  if(thelist[j] > pivot) {
    swap(thelist, end, j);
  }

  //recurse for left and right "halves"
  quicksort(thelist, start, j-1);
  quicksort(thelist, j+1, end);
}

int main(int argc, char *argv[]) {
  int arr[100];
  //int arr[] = {1,1,3,5,4,2,9,8,7,6,5,6,7,8,2,5};
  //int arr[] = {20,26,13,26,20,17,25};
  //int arr[] = {70,70,71,71,71,71,73,72,70};
  int arrsz = sizeof(arr)/sizeof(int);

  srand(time(NULL));
  for(int i=0; i < arrsz; i++) {
    arr[i] = rand() % 100;
  }

  printf("before sorting, ");
  printArray(arr, 0, arrsz-1);
  printf("\n");

  quicksort(arr, 0, arrsz-1);

  printf(" after sorting, ");
  printArray(arr, 0, arrsz-1);
  printf("\n");

  int max = 0, maxidx = 0, err = 0;
  for(int i=0; i < arrsz; i++) {
    if(arr[i] < max) {
      printf("not sorted! idx %d has value %d which is less than value %d at idx %d\n", i, arr[i], max, maxidx);
      err++;
    } else {
      max = arr[i];
      maxidx = i;
    }
  }

  return err;
}
