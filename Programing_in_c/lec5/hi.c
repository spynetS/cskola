// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  char name[30];
  while(scanf("%s",name)==1){
    printf("Hello, %s!\n",name);
  }
  return 0;
}
