// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int triple(int a){
  return a*3;
}

int main(){
  int value;
  while(scanf("%d",&value)==1){
    printf("%d\n",triple(value));
  }
  return 0;
}
