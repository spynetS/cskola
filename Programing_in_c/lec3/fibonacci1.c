// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n){
  if(n == 0) return 0;
  int prev = 0;
  int curr = 1;
  for(int i = 0; i < n-1;i++){
    int temp = curr;
    curr = prev+curr;
    prev = temp;
  }
  return curr;
}


int main(){
  int value;
  scanf("%d",&value);
  printf("%d\n",fibonacci(value));
  return 0;
}
