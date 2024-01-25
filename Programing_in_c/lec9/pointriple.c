// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

void triple_pointer(int *ptr_num){
  *ptr_num*=3;
}

int main(){
  int value;
  while(scanf("%d",&value)>0){
    triple_pointer(&value);
    printf("%d\n",value);

  }
  return 0;
}
