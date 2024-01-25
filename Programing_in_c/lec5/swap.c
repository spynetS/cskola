// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>

int main(){
  char string[30];
  int value;
  while(scanf("%d %s",&value,string)>0){
    printf("%s %d\n",string,value);
  }
  return 0;
}
