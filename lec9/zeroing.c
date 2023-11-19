// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

void zero_int(int *px){
  *px=0;
}

int main(){
  int value;
  while(scanf("%d",&value)>0){
    printf("Before zeroing: %d\n",value);
    zero_int(&value);
    printf("After zeroing: %d\n",value);

  }
  return 0;
}
