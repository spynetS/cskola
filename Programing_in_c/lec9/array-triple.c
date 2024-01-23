// 2023 Alfred Roos
#include <stdio.h>
#define MAX 10000

void triple_array_elements(int arr[], int sz);


int main()
{
    int a[MAX];
    int n = 0;
    int i;
    char c;
    while (scanf("%d%c", &a[n++], &c)==2) {
        if (c == ' ')
            continue;
        triple_array_elements(a, n);
        for (i=0; i<n; i++)
            printf("%s%d", i?" ":"", a[i]);
        printf("\n");
        n = 0;
    }
    return 0;
}


// The triple_array_elements triples each element of a given array
//
// The first argument is a pointer to the starting element of the array.
// The second argument indicates the number of elements in the array.
//
// If this function is called giving an array with elements 1, 7 and 4
// the function should update the array to contain elements 3, 21 and 12.
void triple_array_elements(int arr[], int size)
{
  for(size_t i = 0; i < size; i++){
    arr[i]*=3;
  }
}
