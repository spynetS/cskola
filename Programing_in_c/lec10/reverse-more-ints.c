// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

void reverselist(int* arr, int sz){
  for(int i = 0; i < sz/2;i++){
    int tmp = arr[i];
    arr[i] = arr[sz-1-i];
    arr[sz-1-i] = tmp;
  }
}

void printArr(int* arr,int sz){
  printf("reverse:");
  for(int i = 0; i < sz;i++){
    printf(" %d",arr[i]);
  }
  printf("\n");
}

int main(){
  int value;
  while(scanf("%d",&value)>0){
    int *arr = (int*) malloc(sizeof(int)*value);
    if(arr != NULL){
      for(int i = 0; i < value; i ++){
        scanf("%d",&arr[i]);
      }
      reverselist(arr,value);
      printArr(arr,value);
      free(arr);
    }else{
      printf("out of memory\n");
      return (0);
    }
  }
  return 0;
}
