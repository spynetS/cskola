// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
int factorial(int n){
  int sum = 1;
  for(int i = 1; i <= n; i ++){
    sum *= i;
  }
  return sum;
}

int main(){
  int value;
  while(scanf("%d",&value)>0){
    printf("%d\n",factorial(value));
  }
  return 0;
}
