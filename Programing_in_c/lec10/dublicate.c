// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>


int *duplicate(int arr[], int sz);


int main()
{
    int array[5] = {2,3,5,7,13};
    int *copy;
    int i;

    printf("original array:");
    for (i=0; i<5; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");

    copy = duplicate(array, 5);

    printf("the array copy:");
    for (i=0; i<5; i++) {
        printf(" %d", copy[i]);
    }
    printf("\n");

    // free the copy!
    free(copy);
}


// allocates a copy of the given integer array
int *duplicate(int arr[], int sz)
{
  // add your implementation here
  int* arr_copy = (int*) malloc(sizeof(int)*sz);
  for(int i = 0; i < sz; i++){
    arr_copy[i]=arr[i];
  }
  return arr_copy;
}
