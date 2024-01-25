// 2023 Alfred Roos
#include <stdio.h>
#define MAX 10000

void reverse(int arr[], int sz);


int main(){

    int a[MAX];
    int n = 0;
    int i;
    char c;
    while (scanf("%d%c", &a[n++], &c)==2) {
        if (c == ' ')
            continue;
        reverse(a, n);
        for (i=0; i<n; i++)
            printf("%s%d", i?" ":"", a[i]);
        printf("\n");
        n = 0;
    }
    return 0;
}


// The reverse function reverses the element of a given array
//
// The first argument is a pointer to the starting element of the array.
// The second argument indicates the number of elements in the array.
//
// If before the call the array contains: 4, 2, 7 and 8 in that order,
// after the call the array should contain: 8, 7, 2 and 4 in that order.
void reverse(int arr[], int sz){
  for(int i = 0 ; i < sz/2; i ++){
    int tmp = arr[i];
    arr[i] = arr[sz-1-i];
    arr[sz-1-i] = tmp;
  }
}
