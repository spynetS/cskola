#include <stdio.h>

int main(){
  int age[10] = {0,1,2,3,4,5,67,8,9};
  int age2[10] = {0,3,2,3,4,5,67,8,9};

  if(*age == *age2){
    printf("hej\n");
  }

  return 0;
}
