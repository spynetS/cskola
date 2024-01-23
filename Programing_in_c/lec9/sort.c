// 2023 Alfred Roos
#include <stdio.h>
#define MAX 10000


void sort(int arr[], int size);


int main()
{
    int a[MAX];
    int n = 0;
    int i;
    char c;
    while (scanf("%d%c",&a[n++],&c)==2) {
        if (c == ' ')
            continue;
        sort(a, n);
        for (i=0; i<n; i++)
            printf("%s%d", i?" ":"", a[i]);
        printf("\n");
        n = 0;
    }
    return 0;
}
void bubbleSort(int arr[], int size) {
  int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            count++;
        }
    }
    printf("Counts: %d\n",count);
}
// The sort function puts the elements of the given array in order.
//
// The first argument is a pointer to the starting element of the array.
// The second argument indicates the number of elements in the array.
void sort(int arr[], int size){
  //bubbleSort(arr,size);
  //return;
  int back = 0;
  int count = 0;
  for(int i = 0; i < size; i ++){
    if(i+1 < size && arr[i] > arr[i+1]){

      int tmp = arr[i+1];
      arr[i+1] = arr[i];
      arr[i]=tmp;

      if(i>=2){
        i-=2;
        back += 2;
      }
      else{
        //back=i;
        i=-1;
      }
    }
    else{
      i+=back;
      back=0;
    }
    count++;
  }
  printf("Counts: %d\n",count);
}
